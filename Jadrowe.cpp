#include "Jadrowe.h"

Jadrowe::Jadrowe(const std::string& nazwa, const double moc,
	const std::string lokalizacja, const std::string pierwiastek) :
	Elektrownie{ nazwa, moc }, m_lokalizacja{lokalizacja}, m_pierwiastek{pierwiastek}
{
	// obiekty.push_back(*this);
}

void Jadrowe::setLokalizacja(const std::string& lokalizacja)
{
	m_lokalizacja = lokalizacja;
}

void Jadrowe::setPierwiastek(const std::string& pierwiastek)
{
	m_pierwiastek = pierwiastek;
}

std::ostream& Jadrowe::wypiszInformacje(std::ostream& out) const
{
	out << "JADROWE" << '\n';
	out << "Nazwa: " << getNazwa() << '\n';
	out << "Moc[MW]: " << getMoc() << '\n';
	out << "Lokalizacja: " << getLokalizacja() << '\n';
	out << "Pierwiastek: " << getPierwiastek();
	return out;
}

void Jadrowe::modyfikuj()
{
	std::cout << "Co zmienic?" << '\n';
	std::cout << "1. Nazwa" << '\n';
	std::cout << "2. Moc[MW]" << '\n';
	std::cout << "3. Lokalizacja" << '\n';
	std::cout << "4. Pierwiastek" << '\n';
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
		std::cout << "Podaj wykorzystywany pierwiastek: " << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setPierwiastek(s_temp);
		break;
	default:
		std::cout << "Zla opcja wyboru" << '\n';
		break;
	}
}

void Jadrowe::wypiszDoPliku(std::ostream& plik) const
{
	plik << "JADROWE" << '\n';
	plik << getNazwa() << '\n';
	plik << getMoc() << '\n';
	plik << getLokalizacja() << '\n';
	plik << getPierwiastek();
}

std::istream& Jadrowe::wczytajInformacjePlik(std::istream& in) 
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
	setPierwiastek(s_tmp);
	return in;
}

std::string Jadrowe::getLokalizacja() const
{
	return m_lokalizacja;
}

std::string Jadrowe::getPierwiastek() const
{
	return m_pierwiastek;
}
