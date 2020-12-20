#include "Kamienny.h"

Kamienny::Kamienny(const std::string& nazwa, const double moc, 
	const std::string& lokalizacja, const std::string typ_surowca, 
	const std::string& rodzaj_wegla, const double kalorycznosc, 
	const double czystosc_wegla, const double koszta_wydobycia) :
	Weglowe{nazwa, moc, lokalizacja, typ_surowca, rodzaj_wegla, kalorycznosc},
	m_czystosc_wegla{czystosc_wegla}, m_koszta_wydobycia{koszta_wydobycia}
{
}

void Kamienny::setKosztaWydobycia(const double koszta_wydobycia)
{
	m_koszta_wydobycia = koszta_wydobycia;
}

void Kamienny::setCzystoscWegla(const double czystosc_wegla)
{
	m_czystosc_wegla = czystosc_wegla;
}

double Kamienny::getKosztaWydobycia() const
{
	return m_koszta_wydobycia;
}

double Kamienny::getCzystoscWegla() const
{
	return m_czystosc_wegla;
}
