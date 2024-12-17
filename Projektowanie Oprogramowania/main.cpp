// Tutaj tylko importujemy klasy z plikow osobnych, i w mainie ma byc jak najmniej rzeczy
// mysle ze funkcja main bedzie miala mniej niz 100 loc


// Jak bedziemy trzymac strukture podobna do tego co pisze z tym problemem to nie powinnismy sobie wchodzic w parede i ladnie powinno sie commitowac
// w sensie ze ja potrzebuje cos co wy robicie i to sie sprowadza do tego ze wpisuje #include "waszaklasa.h" i dzia³a lub nie dzia³a

#include <iostream>
#include <fstream>
#include "BazaDanych.h"


int main()
{
    std::fstream file("C:/passwd/mysql.txt", std::fstream::in);
    if (!file)
    {
        std::cout << "Invalid file\n";
        return -1;
    }


    std::string password;

    file >> password;

    BazaDanych baza;
    baza.inicjalizuj("kaienooomysql.mysql.database.azure.com","kaienooo", password);
    baza.uruchomPolecenie("DROP DATABASE IF EXISTS quickstartdb;");
    baza.uruchomPolecenie("CREATE DATABASE quickstartdb");
    baza.wybierzBaze("quickstartdb");

    baza.uruchomPolecenie("DROP TABLE IF EXISTS inventory");
    baza.uruchomPolecenie("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
    baza.wprowadzDane("inventory", "name, quantity", 2);

    system("pause");

    // zmiana
    return 0;
}