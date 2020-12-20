#include "Weglowe.h"

Weglowe::Weglowe(const std::string& nazwa, const double moc, 
	const std::string& lokalizacja, const std::string& typ_surowca, 
	const std::string& rodzaj_wegla, const double kalorycznosc) :
	Surowcow_Naturalnych{nazwa, moc, lokalizacja, typ_surowca}, 
	m_rodzaj_wegla{rodzaj_wegla}, m_kalorycznosc{kalorycznosc}
{
}

void Weglowe::setRodzajWegla(const std::string& rodzaj_wegla)
{
	m_rodzaj_wegla = rodzaj_wegla;
}

void Weglowe::setKalorycznosc(const double kalorycznosc)
{
	m_kalorycznosc = kalorycznosc;
}

std::string Weglowe::getRodzajWegla() const
{
	return m_rodzaj_wegla;
}

double Weglowe::getKalorycznosc() const
{
	return m_kalorycznosc;
}
