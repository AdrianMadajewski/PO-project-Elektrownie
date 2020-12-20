#ifndef JADROWE_H
#define JADROWE_H

#include "Elektrownia.h"
#include <string>
#include <vector>

class Jadrowe : public Elektrownie
{
private:
	std::string m_lokalizacja{};
	// inline static std::vector<Jadrowe> obiekty{};
protected:
	std::string m_pierwiastek{};
public:
	// Jadrowe() {};
	Jadrowe(const std::string& nazwa = "", const double moc = 0.0,
		const std::string lokalizacja = "", const std::string pierwiastek = "");

	void setLokalizacja(const std::string& lokalizacja);
	void setPierwiastek(const std::string& pierwiastek);

	virtual std::ostream& wypiszInformacje(std::ostream& out) const override;
	virtual void modyfikuj() override;
	virtual void wypiszDoPliku(std::ostream& plik) const override;
	virtual std::istream& wczytajInformacjePlik(std::istream& in) override;

	std::string getLokalizacja() const;
	std::string getPierwiastek() const;
};

#endif