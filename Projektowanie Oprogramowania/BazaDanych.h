#pragma once
#include <string>
#include "jdbc/mysql_connection.h"
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/prepared_statement.h>

class BazaDanych
{
	sql::Driver* driver;
	sql::Connection* con;

public:
	BazaDanych();
	~BazaDanych();

	void inicjalizuj(std::string username, std::string password, std::string server);
	void wybierzBaze(std::string nazwa);

	int sprowadzalneDoInt(std::string napis);

	void uruchomPolecenie(std::string polecenie);
	// pola podaj w postaci np. "name, quantity"
	void wprowadzDane(std::string nazwaTabeli, std::string argumenty, int argc);
	//std::string dane - arg1 ; arg2; arg3; ... ;arg{argc}; arg21; arg22; arg23; ... ; arg2{argc}. Ilosc takich blokow oddzielonych ; ma byc wielokorotnoscia argc
	//najpierw argumenty 1,2,3,...,c dla pierwszego wiersza, potem drugiego wiersza 1,2,3,...,c
	void zapiszDoBazy(std::string nazwaTabeli, std::string argumenty, int argc, std::string dane);
};

