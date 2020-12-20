#include "Kopalnia_Odkrywkowa.h"

Kopalnia_Odkrywkowa::Kopalnia_Odkrywkowa(const std::string& nazwa, const double moc, 
	const std::string& lokalizacja, const std::string typ_surowca, 
	const std::string& rodzaj_wegla, const double kalorycznosc, 
	const std::string& rodzaj_kopalni, const double tonarz, 
	const std::string& lokalizacja_kopalni, const int liczba_gornikow) :
	Weglowe{nazwa, moc, lokalizacja, typ_surowca, rodzaj_wegla, kalorycznosc},
	Brunatny{nazwa, moc, lokalizacja, typ_surowca, rodzaj_wegla, kalorycznosc, rodzaj_kopalni, tonarz},
	m_lokalizacja_kopalni{lokalizacja_kopalni}, m_liczba_gornikow{liczba_gornikow}
{
	// obiekty.push_back(*this);
}

void Kopalnia_Odkrywkowa::setLokalizacjaKopalni(const std::string& lokalizacja_kopalni)
{
	m_lokalizacja_kopalni = lokalizacja_kopalni;
}

void Kopalnia_Odkrywkowa::setLiczbaGornikow(const int liczba_gornikow)
{
	m_liczba_gornikow = liczba_gornikow;
}

int Kopalnia_Odkrywkowa::getLiczbaGornikow() const
{
	return m_liczba_gornikow;
}

std::string Kopalnia_Odkrywkowa::getLokalizacjaKopalni() const
{
	return m_lokalizacja_kopalni;
}

std::ostream& Kopalnia_Odkrywkowa::wypiszInformacje(std::ostream& out) const
{
	out << "KOPALNIA_ODKRYWKOWA" << '\n';
	out << "Nazwa: " << getNazwa() << '\n';
	out << "Moc:[MW] " << getMoc() << '\n';
	out << "Lokalizacja: " << getLokalizacja() << '\n';
	out << "Typ-surowca: " << getTypSurowca() << '\n';
	out << "Rodzaj-wegla: " << getRodzajWegla() << '\n';
	out << "Kalorycznosc[kcal/kg]: " << getKalorycznosc() << '\n';
	out << "Rodzaj-kopalni: " << getRodzajKopalni() << '\n';
	out << "Wydobycie[t]: " << getTonarz() << '\n';
	out << "Lokalizacja-kopalni: " << getLokalizacjaKopalni() << '\n';
	out << "Liczba-gornikow: " << getLiczbaGornikow();
	return out;
}

void Kopalnia_Odkrywkowa::modyfikuj()
{
	std::cout << "Co zmienic?" << '\n';
	std::cout << "1. Nazwa" << '\n';
	std::cout << "2. Moc [MW]" << '\n';
	std::cout << "3. Lokalizacja" << '\n';
	std::cout << "4. Typ surowca" << '\n';
	std::cout << "5. Rodzaj wegla" << '\n';
	std::cout << "6. Kalorycznosc [kcal/kg]" << '\n';
	std::cout << "7. Rodzaj kopalni" << '\n';
	std::cout << "8. Wydobycie w tonach" << '\n';
	std::cout << "9. Lokalizacja kopalni" << '\n';
	std::cout << "10. Liczba gornikow" << '\n';

	// Temporary variables for changing
	std::string s_temp{};
	double d_temp{};
	int i_temp{};

	int decision{};

	std::cout << "$ ";
	std::cin >> decision;

	switch (decision)
	{
	case 1:
		std::cout << "Podaj nowa nazwe: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setNazwa(s_temp);
		break;
	case 2:
		std::cout << "Podaj moc: " << '\n';
		std::cout << "$ ";
		std::cin >> d_temp;
		setMoc(d_temp);
		break;
	case 3:
		std::cout << "Podaj nowa lokalizacje: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setLokalizacja(s_temp);
		break;
	case 4:
		std::cout << "Podaj typ surowca: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setTypSurowca(s_temp);
		break;
	case 5:
		std::cout << "Podaj rodzaj wegla: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setRodzajWegla(s_temp);
		break;
	case 6:
		std::cout << "Podaj kalorycznosc[kcal/kg]: " << '\n';
		std::cout << "$ ";
		std::cin >> d_temp;
		setKalorycznosc(d_temp);
		break;
	case 7:
		std::cout << "Podaj rodzaj kopalni: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setRodzajKopalni(s_temp);
		break;
	case 8:
		std::cout << "Podaj wydobycie w tonach: " << '\n';
		std::cout << "$ ";
		std::cin >> d_temp;
		setTonaz(d_temp);
		break;
	case 9:
		std::cout << "Podaj lokalizacje kopalni: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setLokalizacjaKopalni(s_temp);
		break;
	case 10:
		std::cout << "Podaj liczbe gornikow: " << '\n';
		std::cout << "$ ";
		std::cin >> i_temp;
		setLiczbaGornikow(i_temp);
		break;
	default:
		std::cout << "Zla opcja wyboru" << '\n';
		break;
	}
}

void Kopalnia_Odkrywkowa::wypiszDoPliku(std::ostream& plik) const
{
	plik << "KOPALNIA_ODKRYWKOWA" << '\n';
	plik << getNazwa() << '\n';
	plik << getMoc() << '\n';
	plik << getLokalizacja() << '\n';
	plik << getTypSurowca() << '\n';
	plik << getRodzajWegla() << '\n';
	plik << getKalorycznosc() << '\n';
	plik << getRodzajKopalni() << '\n';
	plik << getTonarz() << '\n';
	plik << getLokalizacjaKopalni() << '\n';
	plik << getLiczbaGornikow();
}

std::istream& Kopalnia_Odkrywkowa::wczytajInformacjePlik(std::istream& in)
{
	std::string s_tmp{};
	double d_tmp{};
	int i_tmp{};

	in >> s_tmp;
	setNazwa(s_tmp);
	in >> d_tmp;
	setMoc(d_tmp);
	in >> s_tmp;
	setLokalizacja(s_tmp);
	in >> s_tmp;
	setTypSurowca(s_tmp);
	in >> s_tmp;
	setRodzajWegla(s_tmp);
	in >> d_tmp;
	setKalorycznosc(d_tmp);
	in >> s_tmp;
	setRodzajKopalni(s_tmp);
	in >> d_tmp;
	setTonaz(d_tmp);
	in >> s_tmp;
	setLokalizacjaKopalni(s_tmp);
	in >> i_tmp;
	setLiczbaGornikow(i_tmp);
	return in;
}
