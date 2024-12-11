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

	void uruchomPolecenie(std::string polecenie);
	// pola podaj w postaci np. "name, quantity"
	void wprowadzDane(std::string nazwaTabeli, std::string argumenty);
};

