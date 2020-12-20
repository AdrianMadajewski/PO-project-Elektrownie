#include "Kopalnia_Glebinowa.h"

Kopalnia_Glebinowa::Kopalnia_Glebinowa(const std::string& nazwa, const double moc,
	const std::string& lokalizacja, const std::string typ_surowca,
	const std::string& rodzaj_wegla, const double kalorycznosc,
	const std::string& rodzaj_kopalni, const double tonarz,
	const double czystosc_wegla, const double koszt_wydobycia,
	const std::string& lokalizacja_kopalni, const int liczba_gornikow) :
	Weglowe{ nazwa, moc, lokalizacja, typ_surowca, rodzaj_wegla, kalorycznosc },
	Brunatny{ nazwa, moc, lokalizacja, typ_surowca, rodzaj_wegla, kalorycznosc, rodzaj_kopalni, tonarz },
	Kamienny{ nazwa, moc, lokalizacja, typ_surowca, rodzaj_wegla, kalorycznosc, czystosc_wegla, koszt_wydobycia },
	m_lokalizacja_kopalni{lokalizacja_kopalni}, m_liczba_gornikow{liczba_gornikow}
{
	// obiekty.push_back(*this);
}

void Kopalnia_Glebinowa::setLokalizacjaKopalni(const std::string& lokalizacja_kopalni)
{
	m_lokalizacja_kopalni = lokalizacja_kopalni;
}

void Kopalnia_Glebinowa::setLiczbaGornikow(const int liczba_gornikow)
{
	m_liczba_gornikow = liczba_gornikow;
}

int Kopalnia_Glebinowa::getLiczbaGornikow() const
{
	return m_liczba_gornikow;
}

std::string Kopalnia_Glebinowa::getLokalizacjaKopalni() const
{
	return m_lokalizacja_kopalni;
}

std::ostream& Kopalnia_Glebinowa::wypiszInformacje(std::ostream& out) const
{
	out << "KOPALNIA_GLEBINOWA" << '\n';
	out << "Nazwa: " << getNazwa() << '\n';
	out << "Moc:[MW] " << getMoc() << '\n';
	out << "Lokalizacja: " << getLokalizacja() << '\n';
	out << "Typ-surowca: " << getTypSurowca() << '\n';
	out << "Rodzaj-wegla: " << getRodzajWegla() << '\n';
	out << "Kalorycznosc[kcal/kg]: " << getKalorycznosc() << '\n';
	out << "Rodzaj-kopalni: " << getRodzajKopalni() << '\n';
	out << "Wydobycie[t]: " << getTonarz() << '\n';
	out << "Koszt-wydobycia[zl]: " << getKosztaWydobycia() << '\n';
	out << "Czystosc-wegla[%]: " << getCzystoscWegla() << '\n';
	out << "Lokalizacja-kopalni: " << getLokalizacjaKopalni() << '\n';
	out << "Liczba-gornikow: " << getLiczbaGornikow();
	return out;
}

void Kopalnia_Glebinowa::modyfikuj()
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
	std::cout << "9. Koszta wydobycia [zl]" << '\n';
	std::cout << "10. Czystosc wegla [%]" << '\n';
	std::cout << "11. Lokalizacja kopalni" << '\n';
	std::cout << "12. Liczba gornikow" << '\n';

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
		std::cout << "Podaj koszta wydobycia [zl]: " << '\n';
		std::cout << "$ ";
		std::cin >> d_temp;
		setKosztaWydobycia(d_temp);
		break;
	case 10:
		std::cout << "Podaj czystosc wegla [%]: " << '\n';
		std::cout << "$ ";
		std::cin >> d_temp;
		setCzystoscWegla(d_temp);
		break;
	case 11:
		std::cout << "Podaj lokalizacje kopalni: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setLokalizacjaKopalni(s_temp);
		break;
	case 12:
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

void Kopalnia_Glebinowa::wypiszDoPliku(std::ostream& plik) const
{
	plik << "KOPALNIA_GLEBINOWA" << '\n';
	plik << getNazwa() << '\n';
	plik << getMoc() << '\n';
	plik << getLokalizacja() << '\n';
	plik << getTypSurowca() << '\n';
	plik << getRodzajWegla() << '\n';
	plik << getKalorycznosc() << '\n';
	plik << getRodzajKopalni() << '\n';
	plik << getTonarz() << '\n';
	plik << getCzystoscWegla() << '\n';
	plik << getKosztaWydobycia() << '\n';
	plik << getLokalizacjaKopalni() << '\n';
	plik << getLiczbaGornikow();
}

std::istream& Kopalnia_Glebinowa::wczytajInformacjePlik(std::istream& in)
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
	in >> d_tmp;
	setCzystoscWegla(d_tmp);
	in >> d_tmp;
	setKosztaWydobycia(d_tmp);
	in >> s_tmp;
	setLokalizacjaKopalni(s_tmp);
	in >> i_tmp;
	setLiczbaGornikow(i_tmp);
	return in;
}
