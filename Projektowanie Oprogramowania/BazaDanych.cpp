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

int BazaDanych::sprowadzalneDoInt(std::string napis)
{
    int integerValue = 0;
    for (int i = 0; i < napis.length(); i++)
    {
        if (napis[i] < '0' or napis[i] > '9')
        {
            return 0;
        }
        else
        {
            integerValue = integerValue * 10 + napis[i] - '0';
        }
    }
    return integerValue;
}

void BazaDanych::uruchomPolecenie(std::string polecenie)
{
    sql::Statement* stmt;

    stmt = con->createStatement();
    stmt->execute(polecenie);
    delete stmt;
}

void BazaDanych::wprowadzDane(std::string nazwaTabeli, std::string argumenty, int argc)
{
    sql::PreparedStatement* pstmt;
    std::string temp;
    int temp_int = 0;

    pstmt = con->prepareStatement(std::format("INSERT INTO {}({}) VALUES(?,?)",nazwaTabeli,argumenty));
    while (true)
    {
        for (int i = 0; i < argc; i++)
        {
            std::cout << "Podaj wartosc dla argumentu " << i << ":" << std::endl;
            std::cin >> temp;

            if (temp_int = sprowadzalneDoInt(temp))
            {
                pstmt->setInt(i + 1, temp_int);
            }
            else
            {
                pstmt->setString(i + 1, temp);
            }
        }
        pstmt->execute();
    }

    delete pstmt;
}

void BazaDanych::zapiszDoBazy(std::string nazwaTabeli, std::string argumenty, int argc, std::string dane)
{
    sql::PreparedStatement* pstmt;

    pstmt = con->prepareStatement(std::format("INSERT INTO {}({}) VALUES(?,?)", nazwaTabeli, argumenty));

}
