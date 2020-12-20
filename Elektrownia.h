#ifndef ELEKTROWNIA_H
#define ELEKTROWNIA_H

#include <string>
#include <iostream>

class Elektrownie
{
private:
	std::string m_nazwa{};
protected:
	double m_moc{};
public:
	// Elektrownie();
	Elektrownie(const std::string &nazwa, double moc);
	virtual ~Elektrownie() = default;

	friend std::ostream& operator<<(std::ostream& out, const Elektrownie& obiekt);
	friend std::istream& operator>>(std::istream& in, Elektrownie &obiekt);
	virtual std::ostream& wypiszInformacje(std::ostream& out) const = 0;
	virtual void modyfikuj() = 0;
	virtual void wypiszDoPliku(std::ostream& plik) const = 0;
	virtual std::istream& wczytajInformacjePlik(std::istream& in) = 0;

	// Setters
	void setNazwa(const std::string &nazwa);
	void setMoc(const double moc);

	// Getters
	std::string getNazwa() const;
	double getMoc() const;
};

#endif