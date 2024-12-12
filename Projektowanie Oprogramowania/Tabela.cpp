#include "Tabela.h"

Tabela::Tabela() : iloscTabel(0), tabele(0)
{
}

Tabela::Tabela(int iloscTabel) : iloscTabel(iloscTabel), tabele(0)
{
}

Tabela::~Tabela()
{
	for (int i = 0; i < iloscTabel; i++)
	{
		delete[] tabele[i];
	}
	delete[] tabele;
}

void Tabela::inicjalizuj(std::string tabeleStr, int tabc)
{
	iloscTabel = tabc;

	tabele = new char* [iloscTabel];

	for (int i = 0; i < tabeleStr.length(); i++)
	{

	}
}
