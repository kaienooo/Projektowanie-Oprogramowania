#pragma once
#include <string>

class DaneProblemu
{
public:							// pelni role struktury wiec wszystko public
	size_t *idPowUzytkownikow;
	char iloscPowUzytkownikow;

	std::string opis;
	int status;
	char priorytet;

public:
	DaneProblemu(size_t* idPowUzytkownikow, int iloscPowUzytkownikow, std::string opis, int status, char priorytet);
	~DaneProblemu();
};

