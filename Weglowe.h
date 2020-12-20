#ifndef WEGLOWE_H
#define WEGLOWE_H

#include "Surowcow_Naturalnych.h"

class Weglowe : public Surowcow_Naturalnych
{
private:
	std::string m_rodzaj_wegla{};
protected:
	double m_kalorycznosc{}; // [kcal/kg]
public:
	Weglowe(const std::string& nazwa, const double moc,
		const std::string& lokalizacja, const std::string& typ_surowca,
		const std::string& rodzaj_wegla, const double kalorycznosc);

	void setRodzajWegla(const std::string& rodzaj_wegla);
	void setKalorycznosc(const double kalorycznosc);

	std::string getRodzajWegla() const;
	double getKalorycznosc() const;

	virtual std::ostream& wypiszInformacje(std::ostream& out) const = 0;
	virtual void wypiszDoPliku(std::ostream& plik) const = 0;
	virtual void modyfikuj() = 0;
};

#endif // !WEGLOWE_H