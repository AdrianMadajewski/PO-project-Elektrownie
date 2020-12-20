#include "Menedzer.h"

template<>
bool Menedzer<Wodne>::dodajElement(const std::string& nazwa)
{
	if (znajdzElement(nazwa) == Menedzer<Wodne>::obiekty.end())
	{
		double moc{};
		std::string lokalizacja{};
		std::string rodzaj_zbiornika{};
		std::cout << "Podaj moc [MW]: " << '\n';
		std::cout << "$ ";
		std::cin >> moc;
		std::cout << "Podaj lokalizacje: " << '\n';
		std::cout << "$ ";
		std::cin >> lokalizacja;
		std::cout << "Podaj rodzaj zbiornika wodnego: " << '\n';
		std::cout << "$ ";
		std::cin >> rodzaj_zbiornika;

		Wodne obiekt{ nazwa, moc, lokalizacja, rodzaj_zbiornika };
		obiekty.push_back(obiekt);

		return true;
	}
	return false;
}

template<>
bool Menedzer<Jadrowe>::dodajElement(const std::string& nazwa)
{
	if (znajdzElement(nazwa) == Menedzer<Jadrowe>::obiekty.end())
	{
		double moc{};
		std::string lokalizacja{};
		std::string pierwiastek{};
		std::cout << "Podaj moc [MW]: " << '\n';
		std::cout << "$ ";
		std::cin >> moc;
		std::cout << "Podaj lokalizacje: " << '\n';
		std::cout << "$ ";
		std::cin >> lokalizacja;
		std::cout << "Podaj uzywany pierwiastek: " << '\n';
		std::cout << "$ ";
		std::cin >> pierwiastek;

		Jadrowe obiekt{ nazwa, moc, lokalizacja, pierwiastek };
		obiekty.push_back(obiekt);

		return true;
	}
	return false;
}

template<>
bool Menedzer<Gazowe>::dodajElement(const std::string& nazwa)
{
	if (znajdzElement(nazwa) == Menedzer<Gazowe>::obiekty.end())
	{
		double moc{};
		std::string lokalizacja{};
		std::string typ_surowca{};
		std::string rodzaj_gazu{};
		std::string typ_gazu{};
		std::cout << "Podaj moc [MW]: " << '\n';
		std::cout << "$ ";
		std::cin >> moc;
		std::cout << "Podaj lokalizacje: " << '\n';
		std::cout << "$ ";
		std::cin >> lokalizacja;
		std::cout << "Podaj typ surowca: " << '\n';
		std::cout << "$ ";
		std::cin >> typ_surowca;
		std::cout << "Podaj rodzaj gazu: " << '\n';
		std::cout << "$ ";
		std::cin >> rodzaj_gazu;
		std::cout << "Podaj typ gazu: " << '\n';
		std::cout << "$ ";
		std::cin >> typ_gazu;

		Gazowe obiekt{ nazwa, moc, lokalizacja, typ_surowca, rodzaj_gazu, typ_gazu };
		obiekty.push_back(obiekt);

		return true;
	}
	return false;
}

template<>
bool Menedzer<Ropa>::dodajElement(const std::string& nazwa)
{
	if (znajdzElement(nazwa) == Menedzer<Ropa>::obiekty.end())
	{
		double moc{};
		std::string lokalizacja{};
		std::string typ_surowca{};
		double kalorycznosc{};
		double gestosc{};
		std::cout << "Podaj moc [MW]: " << '\n';
		std::cout << "$ ";
		std::cin >> moc;
		std::cout << "Podaj lokalizacje: " << '\n';
		std::cout << "$ ";
		std::cin >> lokalizacja;
		std::cout << "Podaj typ surowca: " << '\n';
		std::cout << "$ ";
		std::cin >> typ_surowca;
		std::cout << "Podaj kalorycznosc [kcal/kg]: " << '\n';
		std::cout << "$ ";
		std::cin >> kalorycznosc;
		std::cout << "Podaj gestosc [kg/m3]: " << '\n';
		std::cout << "$ ";
		std::cin >> gestosc;

		Ropa obiekt{ nazwa, moc, lokalizacja, typ_surowca, kalorycznosc, gestosc };
		obiekty.push_back(obiekt);

		return true;
	}
	return false;
}

template<>
bool Menedzer<Kopalnia_Odkrywkowa>::dodajElement(const std::string& nazwa)
{
	if (znajdzElement(nazwa) == Menedzer<Kopalnia_Odkrywkowa>::obiekty.end())
	{
		double moc{};
		std::string lokalizacja{};
		std::string typ_surowca{};
		double kalorycznosc{};
		std::string rodzaj_kopalni{};
		std::string rodzaj_wegla{};
		double tonarz{};
		std::string lokalizacja_kopalni{};
		int liczba_gornikow{};

		std::cout << "Podaj moc [MW]: " << '\n';
		std::cout << "$ ";
		std::cin >> moc;

		std::cout << "Podaj lokalizacje: " << '\n';
		std::cout << "$ ";
		std::cin >> lokalizacja;

		std::cout << "Podaj typ surowca: " << '\n';
		std::cout << "$ ";
		std::cin >> typ_surowca;

		std::cout << "Rodzaj wegla: " << '\n';
		std::cout << "$ ";
		std::cin >> rodzaj_wegla;

		std::cout << "Kalorycznosc [kcal/kg]: " << '\n';
		std::cout << "$ ";
		std::cin >> kalorycznosc;

		std::cout << "Podaj rodzaj kopalni: " << '\n';
		std::cout << "$ ";
		std::cin >> rodzaj_kopalni;

		std::cout << "Podaj wydobycie w tonach: " << '\n';
		std::cout << "$ ";
		std::cin >> tonarz;

		std::cout << "Podaj lokalizacje kopalni: " << '\n';
		std::cout << "$ ";
		std::cin >> lokalizacja_kopalni;

		std::cout << "Podaj liczbe gornikow: " << '\n';
		std::cout << "$ ";
		std::cin >> liczba_gornikow;

		Kopalnia_Odkrywkowa obiekt{ nazwa, moc, lokalizacja, typ_surowca,
			rodzaj_wegla, kalorycznosc, rodzaj_kopalni,
			tonarz, lokalizacja, liczba_gornikow };
		obiekty.push_back(obiekt);

		return true;
	}
	return false;
}

template<>
bool Menedzer<Kopalnia_Glebinowa>::dodajElement(const std::string& nazwa)
{
	if (znajdzElement(nazwa) == Menedzer<Kopalnia_Glebinowa>::obiekty.end())
	{
		double moc{};
		std::string lokalizacja{};
		std::string typ_surowca{};
		double kalorycznosc{};
		std::string rodzaj_kopalni{};
		std::string rodzaj_wegla{};
		double tonarz{};
		std::string lokalizacja_kopalni{};
		int liczba_gornikow{};
		double koszta_wydobycia{};
		double czystosc_wegla{};

		std::cout << "Podaj moc [MW]: " << '\n';
		std::cout << "$ ";
		std::cin >> moc;

		std::cout << "Podaj lokalizacje: " << '\n';
		std::cout << "$ ";
		std::cin >> lokalizacja;

		std::cout << "Podaj typ surowca: " << '\n';
		std::cout << "$ ";
		std::cin >> typ_surowca;

		std::cout << "Rodzaj wegla: " << '\n';
		std::cout << "$ ";
		std::cin >> rodzaj_wegla;

		std::cout << "Kalorycznosc [kcal/kg]: " << '\n';
		std::cout << "$ ";
		std::cin >> kalorycznosc;

		std::cout << "Podaj rodzaj kopalni: " << '\n';
		std::cout << "$ ";
		std::cin >> rodzaj_kopalni;

		std::cout << "Podaj wydobycie w tonach: " << '\n';
		std::cout << "$ ";
		std::cin >> tonarz;

		std::cout << "Podaj koszta wydobycia [zl]: " << '\n';
		std::cout << "$ ";
		std::cin >> koszta_wydobycia;

		std::cout << "Podaj czystosc wegla [%]: " << '\n';
		std::cout << "$ ";
		std::cin >> czystosc_wegla;

		std::cout << "Podaj lokalizacje kopalni: " << '\n';
		std::cout << "$ ";
		std::cin >> lokalizacja_kopalni;

		std::cout << "Podaj liczbe gornikow: " << '\n';
		std::cout << "$ ";
		std::cin >> liczba_gornikow;

		Kopalnia_Glebinowa obiekt{ nazwa, moc, lokalizacja, typ_surowca,
			rodzaj_wegla, kalorycznosc, rodzaj_kopalni,
			tonarz, czystosc_wegla, koszta_wydobycia, lokalizacja, liczba_gornikow };
		obiekty.push_back(obiekt);

		return true;
	}
	return false;
}