#include "Surowcow_Naturalnych.h"

Surowcow_Naturalnych::Surowcow_Naturalnych(const std::string& nazwa, const double moc,
	const std::string& lokalizacja, const std::string& typ_surowca) :
	Elektrownie{ nazwa, moc }, m_lokalizacja{lokalizacja}, m_typ_surowca{typ_surowca}
{
}

void Surowcow_Naturalnych::setLokalizacja(const std::string& lokalizacja)
{
	m_lokalizacja = lokalizacja;
}

void Surowcow_Naturalnych::setTypSurowca(const std::string& typ_surowca)
{
	m_typ_surowca = typ_surowca;
}

std::string Surowcow_Naturalnych::getTypSurowca() const
{
	return m_typ_surowca;
}

std::string Surowcow_Naturalnych::getLokalizacja() const
{
	return m_lokalizacja;
}
