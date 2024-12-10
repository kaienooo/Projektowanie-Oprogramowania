#include "DaneProblemu.h"

DaneProblemu::DaneProblemu(size_t* idPowUzytkownikow, int iloscPowUzytkownikow, std::string opis, int status, char priorytet) : opis(opis), status(status), priorytet(priorytet)
{

	if (iloscPowUzytkownikow > 255)
	{
		this->iloscPowUzytkownikow = 255;
	}
	else if (iloscPowUzytkownikow < 1)
	{
		this->iloscPowUzytkownikow = 1;
	}
	else
	{
		this->iloscPowUzytkownikow = iloscPowUzytkownikow;
	}

	iloscPowUzytkownikow = this->iloscPowUzytkownikow;

	this->idPowUzytkownikow = new size_t[iloscPowUzytkownikow];

	for (int i = 0; i < iloscPowUzytkownikow; i++)
	{
		this->idPowUzytkownikow[i] = idPowUzytkownikow[i];
	}

	delete[] idPowUzytkownikow;
}

DaneProblemu::~DaneProblemu()
{
	delete[] idPowUzytkownikow;
	delete this;
}
