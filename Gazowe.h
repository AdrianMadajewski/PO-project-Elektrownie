#ifndef GAZOWE_H
#define GAZOWE_H

#include "Surowcow_Naturalnych.h"
#include <string>
#include <vector>

class Gazowe : public Surowcow_Naturalnych
{
private:
	// inline static std::vector<Gazowe> obiekty{};
	std::string m_rodzaj_gazu{}; // ziemny
protected:
	std::string m_typ_gazu{}; // E, LW, LS, Lm, Ln
public:
	Gazowe(const std::string& nazwa = "", const double moc = 0.0,
		const std::string& lokalizacja = "", const std::string typ_surowca = "",
		const std::string& rodzaj_gazu = "", const std::string& typ_gazu = "");

	void setRodzajGazu(const std::string& rodzaj_gazu);
	void setTypGazu(const std::string& typ_gazu);

	std::string getRodzajGazu() const;
	std::string getTypGazu() const;

	virtual std::ostream& wypiszInformacje(std::ostream& out) const override;
	virtual void wypiszDoPliku(std::ostream& plik) const override;
	virtual void modyfikuj() override;
	virtual std::istream& wczytajInformacjePlik(std::istream& in) override;
};


#endif // !GAZOWE_H