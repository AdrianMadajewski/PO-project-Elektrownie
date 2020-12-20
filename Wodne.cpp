#include "Wodne.h"

Wodne::Wodne(const std::string& nazwa, const double moc,
	const std::string& lokalizacja, const std::string& rodzaj_zbiornika) :
	Elektrownie{ nazwa, moc }, m_lokalizacja{lokalizacja}, m_rodzaj_zbiornika{rodzaj_zbiornika}
{
	// obiekty.push_back(*this);
}

void Wodne::setLokalizacja(const std::string& lokalizacja)
{
	m_lokalizacja = lokalizacja;
}

void Wodne::setRodzajZbiornika(const std::string& rodzaj_zbiornika)
{
	m_rodzaj_zbiornika = rodzaj_zbiornika;
}

std::ostream& Wodne::wypiszInformacje(std::ostream& out) const
{
	out << "WODNE" << '\n';
	out << "Nazwa: " << getNazwa() << '\n';
	out << "Moc[MW]: " << getMoc() << '\n';
	out << "Lokalizacja: " << getLokalizacja() << '\n';
	out << "Rodzaj-zbiornika: " << getRodzajZbiornika();
	return out;
}

void Wodne::modyfikuj()
{
	std::cout << "Co zmienic?" << '\n';
	std::cout << "1. Nazwa" << '\n';
	std::cout << "2. Moc[MW]" << '\n';
	std::cout << "3. Lokalizacja" << '\n';
	std::cout << "4. Rodzaj zbiornika wodnego" << '\n';
	
	// Temporary variables for changing
	std::string s_temp{};
	double d_temp{};

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
		std::cout << "Podaj lokalizacje: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setLokalizacja(s_temp);
		break;
	case 4:
		std::cout << "Podaj rodzaj zbiornika wodnego: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setRodzajZbiornika(s_temp);
		break;
	default:
		std::cout << "Zla opcja wyboru" << '\n';
		break;
	}
}

void Wodne::wypiszDoPliku(std::ostream& plik) const
{
	plik << "WODNE" << '\n';
	plik << getNazwa() << '\n';
	plik << getMoc() << '\n';
	plik << getLokalizacja() << '\n';
	plik << getRodzajZbiornika();
}

std::istream& Wodne::wczytajInformacjePlik(std::istream& in)
{
	std::string s_tmp{};
	double d_tmp{};
	in >> s_tmp;
	setNazwa(s_tmp);
	in >> d_tmp;
	setMoc(d_tmp);
	in >> s_tmp;
	setLokalizacja(s_tmp);
	in >> s_tmp;
	setRodzajZbiornika(s_tmp);
	return in;
}

std::string Wodne::getLokalizacja() const
{
	return m_lokalizacja;
}

std::string Wodne::getRodzajZbiornika() const
{
	return m_rodzaj_zbiornika;
}
