#include "Brunatny.h"

Brunatny::Brunatny(const std::string& nazwa, const double moc,
	const std::string& lokalizacja, const std::string typ_surowca,
	const std::string& rodzaj_wegla, const double kalorycznosc,
	const std::string& rodzaj_kopalni, const double tonarz) :
	Weglowe{ nazwa, moc, lokalizacja, typ_surowca, rodzaj_wegla, kalorycznosc },
	m_rodzaj_kopalni{ rodzaj_kopalni }, m_tonaz{ tonarz }
{
}

void Brunatny::setRodzajKopalni(const std::string& rodzaj_kopalni)
{
	m_rodzaj_kopalni = rodzaj_kopalni;
}

void Brunatny::setTonaz(const double tonarz)
{
	m_tonaz = tonarz;
}

std::string Brunatny::getRodzajKopalni() const
{
	return m_rodzaj_kopalni;
}

double Brunatny::getTonarz() const
{
	return m_tonaz;
}
