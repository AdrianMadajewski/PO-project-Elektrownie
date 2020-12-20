#ifndef SUROWCOW_NATURALNYCH_H
#define SUROWCOW_NATURALNYCH_H

#include "Elektrownia.h"
#include <string>

class Surowcow_Naturalnych : public Elektrownie
{
private:
	std::string m_lokalizacja{};
protected:
	std::string m_typ_surowca{};
public:
	Surowcow_Naturalnych(const std::string& nazwa, const double moc,
		const std::string& lokalizacja, const std::string& typ_surowca);

	void setLokalizacja(const std::string& lokalizacja);
	void setTypSurowca(const std::string& typ_surowca);

	virtual std::ostream& wypiszInformacje(std::ostream& out) const = 0;
	virtual void modyfikuj() = 0;
	virtual void wypiszDoPliku(std::ostream& plik) const = 0;
	virtual ~Surowcow_Naturalnych() = default;

	std::string getTypSurowca() const;
	std::string getLokalizacja() const;
};

#endif // !SUROWCOW_NATURALNYCH_H