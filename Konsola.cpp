#include "Konsola.h"

#include <fstream>

void Konsola::uruchom()
{
	std::cout << "input HELP for more info..." << '\n';
	std::string zmiana{};

	while (zmiana != "EXIT")
	{
		std::string obecny_wezel_s = reverseWezelMap().at(obecny_wezel);
		std::cout << obecny_wezel_s << "\\$ ";
		std::cin >> zmiana;
		std::transform(zmiana.begin(), zmiana.end(), zmiana.begin(),
			[](unsigned char c) { return toupper(c); });
		std::unordered_map<std::string, Komendy>::const_iterator it = KomendyMap.find(zmiana);
		
		if (it == KomendyMap.end()) {
			std::cout << "Niepoprawna komenda\n";
		}
		else
		{
			switch (it->second)
			{
			case Komendy::CD:
				zmienWezel();
				break;
			case Komendy::MO:
				utworzObiekt();
				break;
			case Komendy::DO:
				usunObiekt();
				break;
			case Komendy::MDO:
				modyfikujObiekt();
				break;
			case Komendy::SHOW:
				show();
				break;
			case Komendy::DIR:
				dir();
				break;
			case Komendy::SAVE:
				zapiszDoPliku();
				break;
			case Komendy::READ:
				wczytajZPliku();
				break;
			case Komendy::TREE:
				wypiszDrzewko();
				break;
			case Komendy::HELP:
				help();
				break;
			case Komendy::CLS:
				cls();
				break;
			}
		}
	}
}

void Konsola::wypiszDrzewko()
{
	std::cout << "                           ELEKTROWNIE                                         \n";
	std::cout << "                          /     |     \\                                       \n";
	std::cout << "                         /      |      \\                                      \n";
	std::cout << "                    ____/       |       \\________________                     \n";
	std::cout << "                   /            |                        \\                    \n";
	std::cout << "               WODNE         JADROWE                SUROWCOW_NATURALNYCH       \n";
	std::cout << "                                                   /          |          \\    \n";
	std::cout << "                                                  /           |           \\   \n";
	std::cout << "                                             WEGLOWE        GAZOWE         ROPA\n";
	std::cout << "                                            /       \\                         \n";
	std::cout << "                                           /         \\                        \n";
	std::cout << "                                      BRUNATNY        KAMIENNY                 \n";
	std::cout << "                                     /        \\_____     |                    \n";
	std::cout << "                                    /                \\   |                    \n";
	std::cout << "                         KOPALNIA_ODKRYWKOWA     KOPALNIA_GLEBINOWA            \n";
}

void Konsola::zmienWezel()
{
	std::string wezel;
	std::cin >> wezel;
	std::transform(wezel.begin(), wezel.end(), wezel.begin(),
		[](unsigned char c) { return toupper(c); });
	std::unordered_map<std::string, Wezel>::const_iterator it = stringWezelMap.find(wezel);
	if (it == stringWezelMap.end())
	{
		std::cout << "Niepoprawny wezel\n";
		return;
	}
	else
	{
		obecny_wezel = stringWezelMap.at(wezel);
	}
}

void Konsola::utworzObiekt()
{
	std::string nazwa{};
	std::cin >> nazwa;

	bool utworzono = false;

	switch (obecny_wezel)
	{
	case Wezel::WODNE:
		if (wodne.dodajElement(nazwa)) utworzono = true;
		break;
	case Wezel::JADROWE:
		if (jadrowe.dodajElement(nazwa)) utworzono = true;
		break;
	case Wezel::ROPA:
		if (ropa.dodajElement(nazwa)) utworzono = true;
		break;
	case Wezel::GAZOWE:
		if (gazowe.dodajElement(nazwa)) utworzono = true;
		break;
	case Wezel::KOPALNIA_GLEBINOWA:
		if (k_glebinowa.dodajElement(nazwa)) utworzono = true;
		break;
	case Wezel::KOPALNIA_ODKRYWKOWA:
		if (k_odkrywkowa.dodajElement(nazwa)) utworzono = true;
		break;
	default:
		std::cout << "Operacja nie jest dostepna z poziomu obecnego wezla" << '\n';
		return;
	}
	if (utworzono)
	{
		std::cout << "Obiekt zostal dodany pomyslnie" << '\n';
	}
	else
	{
		std::cout << "Obiekt o podanej nazwie istnieje juz w bazie obiektow" << '\n';
	}
}

void Konsola::show()
{
	std::string nazwa{};
	std::cin >> nazwa;

	bool istnieje = false;

	switch (obecny_wezel)
	{
	case Wezel::WODNE:
		if (wodne.wypiszInformacje(nazwa)) istnieje = true;
		break;
	case Wezel::JADROWE:
		if (jadrowe.wypiszInformacje(nazwa)) istnieje = true;
		break;
	case Wezel::ROPA:
		if (ropa.wypiszInformacje(nazwa)) istnieje = true;
		break;
	case Wezel::GAZOWE:
		if (gazowe.wypiszInformacje(nazwa)) istnieje = true;
		break;
	case Wezel::KOPALNIA_GLEBINOWA:
		if (k_glebinowa.wypiszInformacje(nazwa)) istnieje = true;
		break;
	case Wezel::KOPALNIA_ODKRYWKOWA:
		if (k_odkrywkowa.wypiszInformacje(nazwa)) istnieje = true;
		break;
	default:
		std::cout << "Operacja nie jest dostepna z poziomu obecnego wezla" << '\n';
		return;
	}
	if (istnieje)
	{
		std::cout << "Obiekt wypisany pomyslnie" << '\n';
	}
	else
	{
		std::cout << "Nie odnaleziono obiektu o okreslonej nazwie" << '\n';
	}
}

void Konsola::usunObiekt()
{
	std::string nazwa{};
	std::cin >> nazwa;

	bool usunieto = false;

	switch (obecny_wezel)
	{
	case Wezel::WODNE:
		if (wodne.usunElement(nazwa)) usunieto = true;
		break;
	case Wezel::JADROWE:
		if (jadrowe.usunElement(nazwa)) usunieto = true;
		break;
	case Wezel::ROPA:
		if (ropa.usunElement(nazwa)) usunieto = true;
		break;
	case Wezel::GAZOWE:
		if (gazowe.usunElement(nazwa)) usunieto = true;
		break;
	case Wezel::KOPALNIA_GLEBINOWA:
		if (k_glebinowa.usunElement(nazwa)) usunieto = true;
		break;
	case Wezel::KOPALNIA_ODKRYWKOWA:
		if (k_odkrywkowa.usunElement(nazwa)) usunieto = true;
		break;
	default:
		std::cout << "Operacja nie jest dostepna z poziomu obecnego wezla" << '\n';
		return;
	}
	if (usunieto)
	{
		std::cout << "Obiekt zostal usuniety pomyslnie" << '\n';
	}
	else
	{
		std::cout << "Obiekt o podanej nazwie nie istnieje w bazie obiektow" << '\n';
	}
}

void Konsola::modyfikujObiekt()
{
	std::string nazwa{};
	std::cin >> nazwa;

	bool zmodyfikowano = false;

	switch (obecny_wezel)
	{
	case Wezel::WODNE:
		if (wodne.modyfikujElement(nazwa)) zmodyfikowano = true;
		break;
	case Wezel::JADROWE:
		if (jadrowe.modyfikujElement(nazwa)) zmodyfikowano = true;
		break;
	case Wezel::ROPA:
		if (ropa.modyfikujElement(nazwa)) zmodyfikowano = true;
		break;
	case Wezel::GAZOWE:
		if (gazowe.modyfikujElement(nazwa)) zmodyfikowano = true;
		break;
	case Wezel::KOPALNIA_GLEBINOWA:
		if (k_glebinowa.modyfikujElement(nazwa)) zmodyfikowano = true;
		break;
	case Wezel::KOPALNIA_ODKRYWKOWA:
		if (k_odkrywkowa.modyfikujElement(nazwa)) zmodyfikowano = true;
		break;
	default:
		std::cout << "Operacja nie jest dostepna z poziomu obecnego wezla" << '\n';
		return;
	}
	if (zmodyfikowano)
	{
		std::cout << "Obiekt zostal zmodyfikowany" << '\n';
	}
	else
	{
		std::cout << "Nie mozna zmodyfikowac obiektu (powtarzajaca sie nazwa obiektu)" << '\n';
	}
}

// Dodaj sprawdzenie czy baza obiektow jest pusta i wtedy wypisuj

void Konsola::dir()
{
	/*
		Dostepne poziomy:
		ELEKTROWNIE - wszystko
		WODNE - wodne
		JADROWE - jadrowe
		SUROWCOW_NATURALNYCH - gazowe, ropa, k_odkrykowa, k_glebinowa
		GAZOWE - gazowe
		ROPA - ropa
		WEGLOWE - k_odkrywkowa, k_glebinowa
		BRUNATNY - k_odkrywkowa, k_glebinowa
		KAMIENNY - k_glebinowa,
		KOPALNIA_ODKRRYWKOWA - k_odkrywkowa
		KOPALNIA_GLEBINOWA - k_glebinowa
	*/

	if (wodne.empty() && jadrowe.empty() && ropa.empty() &&
		gazowe.empty() && k_glebinowa.empty() && k_odkrywkowa.empty())
	{
		std::cout << "Baza obiektow jest pusta" << '\n';
		return;
	}

	switch (obecny_wezel)
	{
	case Wezel::ELEKTROWNIE:
		if (!wodne.empty())
		{
			std::cout << "WODNE: " << '\n';
			wodne.wypiszNazwy();
		}
		if (!jadrowe.empty())
		{
			std::cout << "JADROWE: " << '\n';
			jadrowe.wypiszNazwy();
		}
		if (!gazowe.empty())
		{
			std::cout << "GAZOWE: " << '\n';
			gazowe.wypiszNazwy();
		}
		if (!ropa.empty())
		{
			std::cout << "ROPA: " << '\n';
			ropa.wypiszNazwy();
		}
		if (!k_glebinowa.empty())
		{
			std::cout << "KOPALNIA_GLEBINOWA: " << '\n';
			k_glebinowa.wypiszNazwy();
		}
		if (!k_odkrywkowa.empty())
		{
			std::cout << "KOPALNIA_ODKRYWKOWA: " << '\n';
			k_odkrywkowa.wypiszNazwy();
		}
		break;
	case Wezel::WODNE:
		if (!wodne.empty())
		{
			std::cout << "WODNE: " << '\n';
			wodne.wypiszNazwy();
		}
		break;
	case Wezel::JADROWE:
		if (!jadrowe.empty())
		{
			std::cout << "JADROWE: " << '\n';
			jadrowe.wypiszNazwy();
		}
		break;
	case Wezel::SUROWCOW_NATURALNYCH:
		if (!gazowe.empty())
		{
			std::cout << "GAZOWE: " << '\n';
			gazowe.wypiszNazwy();
		}
		if (!ropa.empty())
		{
			std::cout << "ROPA: " << '\n';
			ropa.wypiszNazwy();
		}
		if (!k_odkrywkowa.empty())
		{
			std::cout << "KOPALNIA_ODKRYWKOWA: " << '\n';
			k_odkrywkowa.wypiszNazwy();
		}
		if (!k_glebinowa.empty())
		{
			std::cout << "KOPALNIA_GLEBINOWA: " << '\n';
			k_glebinowa.wypiszNazwy();
		}
		break;
	case Wezel::ROPA:
		if (!ropa.empty())
		{
			std::cout << "ROPA: " << '\n';
			ropa.wypiszNazwy();
		}
		break;
	case Wezel::GAZOWE:
		if (!gazowe.empty())
		{
			std::cout << "GAZOWE: " << '\n';
			gazowe.wypiszNazwy();
		}
		break;
	case Wezel::WEGLOWE:
	case Wezel::BRUNATNY:
		if (!k_glebinowa.empty())
		{
			std::cout << "KOPALNIA_GLEBINOWA: " << '\n';
			k_glebinowa.wypiszNazwy();
		}
		if (!k_odkrywkowa.empty())
		{
			std::cout << "KOPALNIA_ODKRYWKOWA: " << '\n';
			k_odkrywkowa.wypiszNazwy();
		}
		break;
	case Wezel::KAMIENNY:
	case Wezel::KOPALNIA_GLEBINOWA:
		if (!k_glebinowa.empty())
		{
			std::cout << "KOPALNIA_GLEBINOWA: " << '\n';
			k_glebinowa.wypiszNazwy();
		}
		break;
	case Wezel::KOPALNIA_ODKRYWKOWA:
		if (!k_odkrywkowa.empty())
		{
			std::cout << "KOPALNIA_ODKRYWKOWA: " << '\n';
			k_odkrywkowa.wypiszNazwy();
		}
		break;
	default:
		std::cout << "Nie powinno wystapic - ERROR" << '\n';
		return;
	}
}

void Konsola::zapiszDoPliku()
{
	if (wodne.empty() && jadrowe.empty() && ropa.empty() &&
		gazowe.empty() && k_glebinowa.empty() && k_odkrywkowa.empty())
	{
		std::cout << "Baza obiektow jest pusta" << '\n';
		return;
	}

	std::cout << "Podaj nazwe pliku do zapisania\n";
	std::string nazwa_pliku{};
	std::cin >> nazwa_pliku;

	std::ofstream plik(nazwa_pliku);
	if (!plik.is_open())
	{
		std::cout << "Nie udalo sie otworzyc pliku o nazwie: " << nazwa_pliku << '\n';
		return;
	}

	wodne.zapiszDoPliku(plik);
	jadrowe.zapiszDoPliku(plik);
	gazowe.zapiszDoPliku(plik);
	ropa.zapiszDoPliku(plik);
	k_odkrywkowa.zapiszDoPliku(plik);
	k_glebinowa.zapiszDoPliku(plik);
	std::cout << "Obiekty zapisano pomyslnie." << '\n';

	plik.close();
}

void Konsola::wczytajZPliku()
{
	if (!wodne.empty() && !jadrowe.empty() && !ropa.empty() &&
		!gazowe.empty() && !k_glebinowa.empty() && !k_odkrywkowa.empty())
	{
		std::cout << "Nie mozna odczytac - w bazie wciaz istnieja obiekty" << '\n';
		return;
	}

	std::cout << "Podaj nazwe pliku do odczytu" << '\n';
	std::string nazwa_pliku{};
	std::cin >> nazwa_pliku;
	std::ifstream plik(nazwa_pliku);

	if (!plik.is_open())
	{
		std::cout << "Plik \"" << nazwa_pliku << "\" nie zostal odnaleziony." << '\n';
		return;
	}

	std::string typ_t{};
	while (plik >> typ_t)
	{
		Wezel wezel;

		std::unordered_map<std::string, Wezel>::const_iterator it = stringWezelMap.find(typ_t);
		if (it == stringWezelMap.end())
		{
			std::cout << "Blad czytania pliku" << '\n';
			wodne.clear();
			jadrowe.clear();
			ropa.clear();
			gazowe.clear();
			k_glebinowa.clear();
			k_odkrywkowa.clear();
			plik.close();
			return;
		}
		else
		{
			wezel = stringWezelMap.at(typ_t);
		}

		switch (wezel)
		{
		case Wezel::WODNE:
			wodne.wczytajElementy(plik);
			break;
		case Wezel::JADROWE:
			jadrowe.wczytajElementy(plik);
			break;
		case Wezel::ROPA:
			ropa.wczytajElementy(plik);
			break;
		case Wezel::GAZOWE:
			gazowe.wczytajElementy(plik);
			break;
		case Wezel::KOPALNIA_ODKRYWKOWA:
			k_odkrywkowa.wczytajElementy(plik);
			break;
		case Wezel::KOPALNIA_GLEBINOWA:
			k_glebinowa.wczytajElementy(plik);
			break;
		default:
			std::cout << "Blad czytania pliku." << '\n';
			plik.close();
			return;
		}
	}
	std::cout << "Wczytano pomyslnie" << '\n';
}

void Konsola::help()
{
	std::cout << "Dostepne komendy:\n"
		" - CD [nazwa wezla] - zmiana wezla\n"
		" - MO [nazwa] - utworzenie obiektu dla obecnego liscia\n"
		" - DO [nazwa] - usuniecie obiektu z obecnego liscia\n"
		" - MDO [nazwa] - modyfikacja obiektu z obecnego liscia\n"
		" - SHOW [nazwa] - wyswietla szczegolowe informacje dla obiektu o podanej nazwie\n"
		" - DIR - wypisuje wszystkie elementy z danego wezla\n"
		" - SAVE - zapisywanie danych do pliku\n"
		" - READ - wczytywanie danych z pliku\n"
		" - TREE - wyswietlanie struktury drzewa\n"
		" - HELP - wyswietlenie pomocy\n"
		" - CLS - wyczyszczenie konsoli\n"
		" - EXIT  - wyjscie z programu\n";
}

void Konsola::cls()
{
#if defined(_WIN32)
	system("cls");
#else
	system("clear");
#endif
}
