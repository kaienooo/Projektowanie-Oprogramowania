#include "BazaDanych.h"
#include <iostream>
#include <format>


BazaDanych::BazaDanych() : con(0)
{
    try
    {
        driver = get_driver_instance();
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        system("pause");
    }
}

BazaDanych::~BazaDanych()
{
    delete con;
}

void BazaDanych::inicjalizuj(std::string server, std::string username, std::string password)
{
    try
    {
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        system("pause");
    }
}

void BazaDanych::wybierzBaze(std::string nazwa)
{
    con->setSchema(nazwa);
}

void BazaDanych::uruchomPolecenie(std::string polecenie)
{
    sql::Statement* stmt;

    stmt = con->createStatement();
    stmt->execute(polecenie);
    delete stmt;
}

void BazaDanych::wprowadzDane(std::string nazwaTabeli, std::string argumenty)
{
    sql::PreparedStatement* pstmt;

    pstmt = con->prepareStatement(std::format("INSERT INTO {}({}) VALUES(?,?)",nazwaTabeli,argumenty));
    pstmt->setString(1, "banana");
    pstmt->setInt(2, 150);
    pstmt->execute();

    delete pstmt;
}
