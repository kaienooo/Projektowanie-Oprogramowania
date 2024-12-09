#include "Problem.h"
#include <iostream>

Problem::Problem(DaneProblemu dane) : dane(dane)
{}

Problem::~Problem()
{
	delete this;
}

void Problem::aktualizuj(int nowyStatus)
{
	dane.status = nowyStatus;
	powiadomOAktualizacji();
}

void Problem::powiadomOAktualizacji()
{
	// jak narazie taka prowizorka

	std::cout << "\nPowiadamiam uzytkownikow:\n";

	for (int i = 0; i < dane.iloscPowUzytkownikow; i++)
	{
		std::cout << "Powiadomiono uzytkownika o id " << dane.idPowUzytkownikow[i] << std::endl;
	}
}
