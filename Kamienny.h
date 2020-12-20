#ifndef KAMIENNY_H
#define KAMIENNY_H

#include "Weglowe.h"

class Kamienny : virtual public Weglowe
{
private:
	double m_czystosc_wegla{}; // [%]
protected:
	double m_koszta_wydobycia{}; // [zl]
public:
	Kamienny(const std::string& nazwa, const double moc,
		const std::string& lokalizacja, const std::string typ_surowca,
		const std::string& rodzaj_wegla, const double kalorycznosc,
		const double czystosc_wegla, const double koszta_wydobycia);

	void setKosztaWydobycia(const double koszta_wydobycia);
	void setCzystoscWegla(const double czystosc_wegla);

	double getKosztaWydobycia() const;
	double getCzystoscWegla() const;

	virtual std::ostream& wypiszInformacje(std::ostream& out) const = 0;
	virtual void wypiszDoPliku(std::ostream& plik) const = 0;
	virtual void modyfikuj() = 0;
};

#endif