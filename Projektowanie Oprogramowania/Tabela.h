#pragma once
#include <string>

class Tabela
{
public:
	int iloscTabel;
	char** tabele;

	Tabela();
	Tabela(int iloscTabel);
	~Tabela();

	void inicjalizuj(std::string tabele, int tabc);

	
};

