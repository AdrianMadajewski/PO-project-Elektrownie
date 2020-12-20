#ifndef KONSOLA_H
#define KONSOLA_H

#include "Menedzer.h"

#include <unordered_map>
#include <algorithm>
#include <cstdlib>	// for system()
#include <utility>	// for std::pair

class Konsola
{
private:
	enum class Wezel
	{
		ELEKTROWNIE,
		WODNE,
		JADROWE,
		SUROWCOW_NATURALNYCH,
		GAZOWE,
		ROPA,
		WEGLOWE,
		BRUNATNY,
		KAMIENNY,
		KOPALNIA_ODKRYWKOWA,
		KOPALNIA_GLEBINOWA,
	};

	enum class Komendy
	{
		CD,
		MO,
		DO,
		MDO,
		SHOW,
		DIR,
		SAVE,
		READ,
		TREE,
		EXIT,
		HELP,
		CLS,
	};

	static inline const std::unordered_map<std::string, Wezel> stringWezelMap
	{
		{"ELEKTROWNIE", Wezel::ELEKTROWNIE},
		{"WODNE", Wezel::WODNE},
		{"JADROWE", Wezel::JADROWE},
		{"GAZOWE", Wezel::GAZOWE},
		{"ROPA", Wezel::ROPA},
		{"KOPALNIA_ODKRYWKOWA", Wezel::KOPALNIA_ODKRYWKOWA},
		{"KOPALNIA_GLEBINOWA", Wezel::KOPALNIA_GLEBINOWA},
		{"SUROWCOW_NATURALNYCH", Wezel::SUROWCOW_NATURALNYCH},
		{"WEGLOWE", Wezel::WEGLOWE},
		{"BRUNATNY", Wezel::BRUNATNY},
		{"KAMIENNY", Wezel::KAMIENNY},
	};

	static inline std::unordered_map<Wezel, std::string> reverseWezelMap()
	{
		static std::unordered_map<Wezel, std::string> map;
		for (const auto& [key, value] : stringWezelMap) {
			map.insert(std::make_pair(value, key));
		}
		return map;
	}

	static inline const std::unordered_map<std::string, Komendy> KomendyMap
	{
		{"CD", Komendy::CD},
		{"MO", Komendy::MO},
		{"DO", Komendy::DO},
		{"MDO", Komendy::MDO},
		{"SHOW", Komendy::SHOW},
		{"DIR", Komendy::DIR},
		{"SAVE", Komendy::SAVE},
		{"READ", Komendy::READ},
		{"TREE", Komendy::TREE},
		{"EXIT", Komendy::EXIT},
		{"HELP", Komendy::HELP},
		{"CLS", Komendy::CLS},
	};

	static inline Wezel obecny_wezel = Wezel::ELEKTROWNIE;
	static inline Menedzer<Wodne> wodne{};
	static inline Menedzer<Jadrowe> jadrowe{};
	static inline Menedzer<Ropa> ropa{};
	static inline Menedzer<Gazowe> gazowe{};
	static inline Menedzer<Kopalnia_Odkrywkowa> k_odkrywkowa{};
	static inline Menedzer<Kopalnia_Glebinowa> k_glebinowa{};

	// Functionality

	static void wypiszDrzewko();
	static void zmienWezel();
	static void utworzObiekt();
	static void show();
	static void usunObiekt();
	static void modyfikujObiekt();
	static void dir();
	static void zapiszDoPliku();
	static void wczytajZPliku();
	static void help();
	static void cls();
public:
	static void uruchom();
};


#endif // !KONSOLA_H