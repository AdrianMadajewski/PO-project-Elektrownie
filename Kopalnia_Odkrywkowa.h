#ifndef ODKRYWKOWA_H
#define ODKRYWKOWA_H

#include "Brunatny.h"
#include <string>
#include <vector>

class Kopalnia_Odkrywkowa : public Brunatny
{
private:
	std::string m_lokalizacja_kopalni{};
	// inline static std::vector<Kopalnia_Odkrywkowa> obiekty{};
protected:
	int m_liczba_gornikow{};
public:
	Kopalnia_Odkrywkowa(const std::string& nazwa="", const double moc=0.0,
		const std::string& lokalizacja="", const std::string typ_surowca="",
		const std::string& rodzaj_wegla="", const double kalorycznosc=0.0,
		const std::string& rodzaj_kopalni="", const double tonarz=0.0,
		const std::string& lokalizacja_kopalni="", const int liczba_gornikow=0);

	void setLokalizacjaKopalni(const std::string& lokalizacja_kopalni);
	void setLiczbaGornikow(const int liczba_gornikow);

	int getLiczbaGornikow() const;
	std::string getLokalizacjaKopalni() const;

	virtual std::ostream& wypiszInformacje(std::ostream& out) const override;
	virtual void modyfikuj() override;

	virtual void wypiszDoPliku(std::ostream& plik) const override;
	virtual std::istream& wczytajInformacjePlik(std::istream& in) override;
};

#endif // !ODKRYWKOWA_H