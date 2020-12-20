#include "Gazowe.h"

Gazowe::Gazowe(const std::string& nazwa, const double moc, 
	const std::string& lokalizacja, const std::string typ_surowca, 
	const std::string& rodzaj_gazu, const std::string& typ_gazu) :
	Surowcow_Naturalnych{nazwa, moc, lokalizacja, typ_surowca}, 
	m_rodzaj_gazu{rodzaj_gazu}, m_typ_gazu{typ_gazu}
{
	// obiekty.push_back(*this);
}

void Gazowe::setRodzajGazu(const std::string& rodzaj_gazu)
{
	m_rodzaj_gazu = rodzaj_gazu;
}

void Gazowe::setTypGazu(const std::string& typ_gazu)
{
	m_typ_gazu = typ_gazu;
}

std::string Gazowe::getRodzajGazu() const
{
	return m_rodzaj_gazu;
}

std::string Gazowe::getTypGazu() const
{
	return m_typ_gazu;
}

std::ostream& Gazowe::wypiszInformacje(std::ostream& out) const
{
	out << "GAZOWE" << '\n';
	out << "Nazwa: " << getNazwa() << '\n';
	out << "Moc:[MW] " << getMoc() << '\n';
	out << "Lokalizacja: " << getLokalizacja() << '\n';
	out << "Typ-surowca: " << getTypSurowca() << '\n';
	out << "Rodzaj-gazu: " << getRodzajGazu() << '\n';
	out << "Typ-gazu: " << getTypGazu();
	return out;
}

void Gazowe::wypiszDoPliku(std::ostream& plik) const
{
	plik << "GAZOWE" << '\n';
	plik << getNazwa() << '\n';
	plik << getMoc() << '\n';
	plik << getLokalizacja() << '\n';
	plik << getTypSurowca() << '\n';
	plik << getRodzajGazu() << '\n';
	plik << getTypGazu();
}

void Gazowe::modyfikuj()
{
	std::cout << "Co zmienic?" << '\n';
	std::cout << "1. Nazwa" << '\n';
	std::cout << "2. Moc" << '\n';
	std::cout << "3. Lokalizacja" << '\n';
	std::cout << "4. Typ surowca" << '\n';
	std::cout << "5. Rodzaj gazu" << '\n';
	std::cout << "6. Typ gazu" << '\n';

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
		std::cout << "Podaj nowy typ surowca" << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setTypSurowca(s_temp);
		break;
	case 5:
		std::cout << "Podaj rodzaj gazu" << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setRodzajGazu(s_temp);
		break;
	case 6:
		std::cout << "Podaj typ gazu" << '\n';
		std::cout << "$ ";
		std::cin >> s_temp;
		setTypGazu(s_temp);
		break;
	default:
		std::cout << "Zla opcja wyboru" << '\n';
		break;
	}
}

std::istream& Gazowe::wczytajInformacjePlik(std::istream& in)
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
	setTypSurowca(s_tmp);
	in >> s_tmp;
	setRodzajGazu(s_tmp);
	in >> s_tmp;
	setTypGazu(s_tmp);
	return in;
}
