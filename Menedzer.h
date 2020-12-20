#ifndef MENEDZER_H
#define MENEDZER_H

#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <iostream>

#include "Wodne.h"
#include "Jadrowe.h"
#include "Gazowe.h"
#include "Ropa.h"
#include "Kopalnia_Glebinowa.h"
#include "Kopalnia_Odkrywkowa.h"

template<typename T>
class Menedzer
{
private:
	static inline std::vector<T> obiekty{};
public:
	bool dodajElement(const std::string &nazwa);
	bool usunElement(const std::string& nazwa);
	typename std::vector<T>::iterator znajdzElement(const std::string& nazwa);
	bool modyfikujElement(const std::string& nazwa);
	void zapiszDoPliku(std::ostream& strumien = std::cout);
	inline bool empty();
	bool wypiszInformacje(const std::string& nazwa);
	void wypiszNazwy(std::ostream &strumien = std::cout);
	void wczytajElementy(std::istream& strumien);
	void clear();
};

template<typename T>
typename std::vector<T>::iterator Menedzer<T>::znajdzElement(const std::string& nazwa)
{
	typename std::vector<T>::iterator it;
	for (it = Menedzer<T>::obiekty.begin(); it != Menedzer<T>::obiekty.end(); ++it) {
		if (it->getNazwa() == nazwa) {
			return it;
		}
	}
	return Menedzer<T>::obiekty.end();
}

template<typename T>
bool Menedzer<T>::modyfikujElement(const std::string& nazwa)
{
	typename std::vector<T>::iterator it;
	if ((it = znajdzElement(nazwa)) != Menedzer<T>::obiekty.end())
	{
		it->modyfikuj();
		return true;
	}
	return false;
}

template<typename T>
inline void Menedzer<T>::zapiszDoPliku(std::ostream& strumien)
{
	for (const auto& element : obiekty)
	{
		element.wypiszDoPliku(strumien);
		strumien << '\n';
	}
}

template<typename T>
inline bool Menedzer<T>::empty()
{
	return obiekty.empty();
}

template<typename T>
inline bool Menedzer<T>::wypiszInformacje(const std::string& nazwa)
{
	typename std::vector<T>::iterator it;
	if ((it = znajdzElement(nazwa)) != Menedzer<T>::obiekty.end())
	{
		std::cout << *it << '\n';
		return true;
	}
	return false;
}

template<typename T>
inline void Menedzer<T>::wypiszNazwy(std::ostream &strumien)
{
	for (const auto& element : obiekty)
	{
		strumien << element.getNazwa() << '\n';
	}
}

template<typename T>
inline void Menedzer<T>::wczytajElementy(std::istream& strumien)
{
	T obiekt;
	strumien >> obiekt;
	obiekty.push_back(obiekt);
}

template<typename T>
inline void Menedzer<T>::clear()
{
	obiekty.clear();
}

template<typename T>
bool Menedzer<T>::usunElement(const std::string& nazwa)
{
	typename std::vector<T>::iterator it;
	if ((it = znajdzElement(nazwa)) != Menedzer<T>::obiekty.end())
	{
		Menedzer<T>::obiekty.erase(it);
		return true;
	}
	return false;
}

#endif