#include "Elektrownia.h"


Elektrownie::Elektrownie(const std::string& nazwa, const double moc) :
	m_nazwa{nazwa}, m_moc{moc}
{
}

void Elektrownie::setNazwa(const std::string& nazwa)
{
	m_nazwa = nazwa;
}

void Elektrownie::setMoc(const double moc)
{
	m_moc = moc;
}

std::string Elektrownie::getNazwa() const
{
	return m_nazwa;
}

double Elektrownie::getMoc() const
{
	return m_moc;
}

std::ostream& operator<<(std::ostream& out, const Elektrownie& obiekt)
{
	obiekt.wypiszInformacje(out);
	return out;
}

std::istream& operator>>(std::istream& in, Elektrownie& obiekt)
{
	obiekt.wczytajInformacjePlik(in);
	return in;
}
