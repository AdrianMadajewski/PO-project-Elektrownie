#ifndef WODNE_H
#define WONDE_H

#include "Elektrownia.h"
#include <vector>
#include <string>

class Wodne : public Elektrownie
{
private:
	// inline static std::vector<Wodne> obiekty{};
	std::string m_lokalizacja{};
protected:
	std::string m_rodzaj_zbiornika{};
public:
	// Wodne();
	Wodne(const std::string& nazwa = "", const double moc = 0.0,
		const std::string& lokalizacja = "", const std::string& rodzaj_zbiornika = "");

	// Setters
	void setLokalizacja(const std::string &lokalizacja);
	void setRodzajZbiornika(const std::string &rodzaj_zbiornika);

	virtual std::ostream& wypiszInformacje(std::ostream& out) const override;
	virtual void modyfikuj() override;
	virtual void wypiszDoPliku(std::ostream& plik) const override;
	virtual std::istream& wczytajInformacjePlik(std::istream& in) override;

	// Getters
	std::string getLokalizacja() const;
	std::string getRodzajZbiornika() const;
};

#endif