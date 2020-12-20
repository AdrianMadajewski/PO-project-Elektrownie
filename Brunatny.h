#ifndef BRUNATNY_H
#define BRUNATNY_H

#include "Weglowe.h"

class Brunatny : virtual public Weglowe
{
private:
	std::string m_rodzaj_kopalni{};
protected:
	double m_tonaz{}; // [t]
public:
	Brunatny(const std::string& nazwa, const double moc,
		const std::string& lokalizacja, const std::string typ_surowca,
		const std::string& rodzaj_wegla, const double kalorycznosc,
		const std::string& rodzaj_kopalni, const double tonarz);

	void setRodzajKopalni(const std::string& rodzaj_kopalni);
	void setTonaz(const double tonarz);

	std::string getRodzajKopalni() const;
	double getTonarz() const;

	virtual std::ostream& wypiszInformacje(std::ostream& out) const = 0;
	virtual void wypiszDoPliku(std::ostream& plik) const = 0;
	virtual void modyfikuj() = 0;
};

#endif