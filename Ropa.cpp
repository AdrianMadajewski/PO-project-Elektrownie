#include "Ropa.h"

Ropa::Ropa(const std::string& nazwa, const double moc, 
	const std::string& lokalizacja, const std::string& typ_surowca, 
	const double kalorycznosc, const double gestosc) :
	Surowcow_Naturalnych{nazwa, moc, lokalizacja, typ_surowca}, m_kalorycznosc{kalorycznosc}, m_gestosc{gestosc}
{
	// obiekty.push_back(*this);
}

void Ropa::setGestosc(double gestosc)
{
	m_gestosc = gestosc;
}

void Ropa::setKalorycznosc(double kalorycznosc)
{
	m_kalorycznosc = kalorycznosc;
}

double Ropa::getKalorycznosc() const
{
	return m_kalorycznosc;
}

double Ropa::getGestosc() const
{
	return m_gestosc;
}

std::ostream& Ropa::wypiszInformacje(std::ostream& out) const
{
	out << "ROPA" << '\n';
	out << "Nazwa: " << getNazwa() << '\n';
	out << "Moc:[MW] " << getMoc() << '\n';
	out << "Lokalizacja: " << getLokalizacja() << '\n';
	out << "Typ-surowca: " << getTypSurowca() << '\n';
	out << "Kalorycznosc:[kcal/kg] " << getKalorycznosc() << '\n';
	out << "Gestosc:[kg/m3] " << getGestosc();
	return out;
}

void Ropa::wypiszDoPliku(std::ostream& plik) const
{
	plik << "ROPA" << '\n';
	plik << getNazwa() << '\n';
	plik << getMoc() << '\n';
	plik << getLokalizacja() << '\n';
	plik << getTypSurowca() << '\n';
	plik << getKalorycznosc() << '\n';
	plik << getGestosc();
}

void Ropa::modyfikuj()
{
	std::cout << "Co zmienic?" << '\n';
	std::cout << "1. Nazwa" << '\n';
	std::cout << "2. Moc[MW]" << '\n';
	std::cout << "3. Lokalizacja" << '\n';
	std::cout << "4. Typ surowca" << '\n';
	std::cout << "5. Kalorycznosc[kcal/kg]" << '\n';
	std::cout << "6. Gestosc[kg/m3]" << '\n';

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
		std::cout << "Podaj kalorycznosc surowca" << '\n';
		std::cout << "$ ";
		std::cin >> d_temp;
		setKalorycznosc(d_temp);
		break;
	case 6:
		std::cout << "Podaj gestosc surowca" << '\n';
		std::cout << "$ ";
		std::cin >> d_temp;
		setGestosc(d_temp);
		break;
	default:
		std::cout << "Zla opcja wyboru" << '\n';
		break;
	}
}

std::istream& Ropa::wczytajInformacjePlik(std::istream& in)
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
	in >> d_tmp;
	setKalorycznosc(d_tmp);
	in >> d_tmp;
	setGestosc(d_tmp);

	return in;
}
