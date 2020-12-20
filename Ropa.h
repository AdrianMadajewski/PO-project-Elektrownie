#ifndef ROPA_H
#define ROPA_H

#include "Surowcow_Naturalnych.h"
#include <string>
#include <vector>

class Ropa : public Surowcow_Naturalnych
{
private:
	// inline static std::vector<Ropa> obiekty{};
	double m_kalorycznosc{}; // [kcal/kg]
protected:
	double m_gestosc{};	// [kg/m3]
public:
	Ropa(const std::string& nazwa = "", const double moc = 0.0,
		const std::string& lokalizacja = "", const std::string& typ_surowca = "",
		const double kalorycznosc = 0.0, const double gestosc = 0.0);

	void setGestosc(double gestosc);
	void setKalorycznosc(double kalorycznosc);

	double getKalorycznosc() const;
	double getGestosc() const;

	virtual std::ostream& wypiszInformacje(std::ostream& out) const override;
	virtual void wypiszDoPliku(std::ostream& plik) const override;
	virtual void modyfikuj() override;
	virtual std::istream& wczytajInformacjePlik(std::istream& in) override;
};

#endif // !ROPA_H