#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<conio.h>
#include<sstream>
#include<algorithm>
#include<cctype>
using namespace std;

class Profil
{
protected:
    string imie, haslo, uid;
public:
    virtual int logowanie(string) = 0;
    virtual void menu() = 0;
    virtual void zobacz_dane_konta() = 0;
    virtual void rejestracja_uzytkownika() = 0;
};

//----------------------------------------------------------------------------------------------(Nowa klasa)

class Mieszkaniec : public Profil
{
    vector<string> info_nieruchomosci;
    vector<string>::iterator i;
    string szczego造_nieruchomosci;
public:
    void menu();
    int logowanie(string);
    void rejestracja_uzytkownika();
    void zobacz_nieruchomosci();
    void zobacz_dane_konta();
    string long_to_string(long);
    void wybor_uzytkownika(string, string, ifstream&);
    string na_male(string s);
};

void Mieszkaniec::menu()
{
    int wybor, a;
    system("CLS");
    cout << "WITAMY W SYSTEMIE ZARZADZANIA NIERUCHOMOSCIAMI" << endl;
    cout << "1. Rejestracja uzytkownika" << endl;
    cout << "2. Zobacz dostepne nieruchomosci" << endl;
    cout << "3. Powrot do menu g這wnego" << endl;
    cin >> wybor;
    switch (wybor)
    {
    case 1:
    {
        cout << "1. Zarejestruj sie" << endl;
        cout << "2. Zobacz swoje dane" << endl;
        cout << "3. Powrot do poprzedniego menu" << endl;
        cin >> a;
        if (a == 1)
        {
            rejestracja_uzytkownika();
            break;
        }
        else if (a == 2)
        {
            zobacz_dane_konta();
            break;
        }
        else
        {
            break;
        }
    }
    case 2:
    {
        zobacz_nieruchomosci();
        break;
    }
    default:
    {
        break;
    }
    }
}

void Mieszkaniec::rejestracja_uzytkownika()
{
    char ch;
    long uid_demo;
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    system("CLS");
    cout << "Wprowadz swoje dane :-" << endl;
    cout << "Imie" << endl;
    cin >> imie;
    cout << "Wprowadz has這:" << endl;
    ch = _getch();
    while (ch != 13)
    {
        haslo.push_back(ch);
        cout << "*";
        ch = _getch();
    }
    cout << endl;
    srand(time(NULL));
    uid_demo = rand() % 9999999999 + 1; // stworz dowolna liczbe
    uid = long_to_string(uid_demo);

    ofstream data("database_mieszka鎍y.csv", ios::app);
    data << uid << "," << imie << "," << haslo << "," << datetime.tm_year + 1900 << "/" << datetime.tm_mon + 1 << "/" << datetime.tm_mday << ",0,Niezameldowany" << endl;
    // UID, IMIE, HASLO, ROK/MIESIAC/DZIEN ZAMELDOWANIA, SALDO, STATUS ZAMELDOWANIA (UID NIERUCHOMOI LUB NIEZAMELDOWANY)
    cout << "----- Twoj unikalny kod identyfikacyjny to: " << uid << endl;
    data.close();
}

int Mieszkaniec::logowanie(string) {
    string _uid, pass;
    char ch;
    int count = 0; // Inicjalizuj count na 0

    cout << "Wprowadz unikalny kod identyfikacyjny " << endl;
    cin >> _uid;
    cout << "Wprowadz has這:" << endl;
    ch = _getch();
    while (ch != 13) {
        pass.push_back(ch);
        cout << "*";
        ch = _getch();
    }
    cout << endl;

    ifstream check("database_mieszka鎍y.csv");
    while (check.good()) {
        getline(check, uid, ',');
        getline(check, imie, ',');
        getline(check, haslo, ',');

        if (uid == _uid && haslo == pass) {
            count = 1;
            break; // Wyjdz z petli, jesli znaleziono
        }
    }
    check.close(); // Zamknij plik przed zwroceniem

    return count; // Zwroc count bezposrednio
}

void Mieszkaniec::zobacz_nieruchomosci()
{
    system("CLS");
    string city1, demo_city;
    string type1, demo_type;
    int choice;
    int _log;
    _log = logowanie("1");
    if (_log == 1)
    {
        cout << "WITAMY W SEKCJI ZARZADZANIA NIERUCHOMOSCIAMI" << endl;
        
        cout << "Wprowadz miasto" << endl;
        cin >> city1;
        cout << "Wprowadz typ nieruchomosci:" << endl;
        cin >> type1;
        ifstream r1("real_rent.csv");
        wybor_uzytkownika(city1, type1, r1);
        r1.close();
        cout << "\n\tJesli chcesz zglosic kandytature wynajmu, podaj uid nieruchomosci, ktora jestes zainteresowany" << endl;
        cout << "\tW innym wypadku, wcisnij 0" << endl;
        cin >> choice;

        if (choice == 0)
            return;
        else
        {
            return;
        }


    }
    else
    {
        cout << "Twoje konto nie znajduje sie w bazie danych" << endl;
    }
}

void Mieszkaniec::zobacz_dane_konta()
{
    string _uid, pass;
    char ch;
    int count = 0;

    cout << "Wprowadz unikalny kod identyfikacyjny " << endl;
    cin >> _uid;
    cout << "Wprowadz has這:" << endl;
    ch = _getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << "*";
        ch = _getch();
    }
    cout << endl;
    ifstream check("database_mieszka鎍y.csv");
    while (check.good())
    {
        getline(check, uid, ',');
        getline(check, imie, ',');
        getline(check, haslo, '\n');
        if (uid == _uid && haslo == pass)
        {
            cout << "Twoje konto zosta這 wykryte" << endl;
            cout << "UID\t\tIMIE\t\tHASΜ" << endl;
            cout << uid << "\t\t" << imie << "\t\t" << haslo << endl;
            count = 1;
        }
    }
    check.close();
    if (count == 0)
    {
        cout << "TWOJE KONTO NIE JEST W BAZIE DANYCH" << endl;
        count = 0;
    }
}

string Mieszkaniec::long_to_string(long a)
{
    ostringstream outstr;
    outstr << a;
    return outstr.str();
}

void Mieszkaniec::wybor_uzytkownika(string city1, string type1, ifstream& r1)
{
    int it, it1;
    it = it1 = 0;
    system("CLS");
    cout << "WITAMY W SILNIKU WYSZUKIWANIA NIERUCHOMOSCI" << endl;
    cout << "Dostepne opcje nieruchomosci to\n" << endl;
    cout << "ID NIERUCHOMOSCI\tMIASTO\tPOWIERZCHNIA\tTYP\tCENA\tADRES" << endl; // rzeczy do dodania
    while (r1.good())
    {
        getline(r1, szczego造_nieruchomosci, ','); // -1
        getline(r1, szczego造_nieruchomosci, ','); // 0
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 1
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 2
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 3
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 4
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 5
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 6
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 7
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 8
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 9
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 10
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, ','); // 11
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        getline(r1, szczego造_nieruchomosci, '\n'); // 12
        info_nieruchomosci.push_back(szczego造_nieruchomosci);
        i = find(info_nieruchomosci.begin(), info_nieruchomosci.end(), city1);
        if (i != info_nieruchomosci.end())
            it++;

        i = find(info_nieruchomosci.begin(), info_nieruchomosci.end(), type1);
        if (i != info_nieruchomosci.end())
            it1++;

        if (it == 1 && it1 == 1)
        {
            for (i = info_nieruchomosci.begin(); i != info_nieruchomosci.end(); ++i)
            {
                cout << *i << "\t";
            }
            cout << endl;
        }
        it = it1 = 0;
        info_nieruchomosci.clear();
    }
}

string Mieszkaniec::na_male(string s)
{
    string r = s;
    for (int i = 0; i < r.length(); i++)
        r[i] = tolower(r[i]);
    return r;
}

//----------------------------------------------------------------------------------------------(nowa klasa)
class Zarzadca : public Profil
{
    vector<string> info_zarzadcy;
    vector<string> info_nieruchomosci;
    vector<string>::iterator i;
    string szczego造_nieruchomosci;
public:
    void menu();
    int logowanie(string);
    void wprowadz_dane_nieruchomosci();
    void zobacz_dane_konta();
    void rejestracja_uzytkownika();
    string long_to_string(long);
    string na_male(string s);
    void wybor_nieruchomosci(string _uid, ifstream& r1);
};

void Zarzadca::menu()
{
    int wybor, a;
    system("CLS");
    cout << "WITAMY W SYSTEMIE ZARZADZANIA NIERUCHOMOSCIAMI" << endl;
    cout << "1. Rejestracja uzytkownika" << endl;
    cout << "2. Wprowadz szczego造 nieruchomosci, ktora chcesz sprzedac" << endl;
    cout << "3. Powrot do menu g這wnego" << endl;
    cin >> wybor;
    switch (wybor)
    {
    case 1:
    {
        cout << "1. Zarejestruj sie" << endl;
        cout << "2. Zobacz swoje dane" << endl;
        cout << "3. Powrot do poprzedniego menu" << endl;
        cin >> a;
        if (a == 1)
        {
            cout << endl;
            rejestracja_uzytkownika();
            break;
        }
        else if (a == 2)
        {
            cout << endl;
            zobacz_dane_konta();
            break;
        }
        else
        {
            break;
        }
    }
    case 2:
    {
        cout << endl;
        wprowadz_dane_nieruchomosci();
        break;
    }
    default:
    {
        break;
    }
    }
}

int Zarzadca::logowanie(string _uid)
{
    string pass;
    char ch;
    int count = 0;

    cout << "Wprowadz has這:" << endl;
    ch = _getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << "*";
        ch = _getch();
    }
    ifstream check("database_zarzadcy.csv");
    while (check.good())
    {
        getline(check, uid, ',');
        getline(check, imie, ',');
        getline(check, haslo, '\n');

        if (uid == _uid && haslo == pass)
        {
            count = 1;
            break;
        }
    }
    check.close();
    if (count == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Zarzadca::wprowadz_dane_nieruchomosci()
{
    int ch;
    string _uid, a, city1, type1;
    long real_id;
    int _log;

    system("CLS");

    cout << "Wprowadz unikalny kod identyfikacyjny" << endl;
    cout << " " << endl;
    cin >> _uid;
    _log = logowanie(_uid);
    cout << endl;
    if (_log == 1)
    {
        a = _uid;
        info_zarzadcy.push_back(a);

        cout << "Wprowadz informacje o nieruchomosci" << endl;
        srand(time(NULL));
        real_id = rand() % 999999999 + 1;

        a = long_to_string(real_id);
        info_zarzadcy.push_back(a);
        cout << "Wprowadz MIASTO" << endl;
        cin.ignore();
        getline(cin, a);
        city1 = na_male(a);
        info_zarzadcy.push_back(city1);
        cout << "Typ dostepnej nieruchomosci:" << endl; // np. dom jednorodzinny, bungalow, mieszkanie itp.
        cin.ignore();
        getline(cin, a);
        type1 = na_male(a);
        info_zarzadcy.push_back(type1);
        cout << "Wprowadz POWIERZCHNIE (w sqft) nieruchomosci:" << endl;
        cin >> a;
        info_zarzadcy.push_back(a);
        cout << "Wprowadz ADRES nieruchomosci:" << endl;
        cout << "Wprowadz numer domu" << endl;
        cin.ignore();
        getline(cin, a);
        info_zarzadcy.push_back(a);
        cout << "Wprowadz ulice" << endl;
        cin.ignore();
        getline(cin, a);
        info_zarzadcy.push_back(a);
        a = "Aktywna";
        info_zarzadcy.push_back(a);
        cout << "Wprowadz rok budowy:" << endl;
        cin >> a;
        info_zarzadcy.push_back(a);
        cout << "Wprowadz odleg這sc (w km) do najblizszej szko造:" << endl;
        cin >> a;
        info_zarzadcy.push_back(a);
        cout << "Wprowadz odleg這sc (w km) do najblizszego szpitala:" << endl;
        cin >> a;
        info_zarzadcy.push_back(a);
        cout << "Wprowadz dodatkowe informacje o swojej nieruchomosci" << endl;
        cin.ignore();
        getline(cin, a);
        info_zarzadcy.push_back(a);
        cout << "Wprowadz lokalne informacje o swojej nieruchomosci" << endl;
        cin.ignore();
        getline(cin, a);
        info_zarzadcy.push_back(a);

        cout << "Wprowadz cene, za ktora chcesz wynajac (za miesiac)" << endl;
        cin >> a;
        info_zarzadcy.push_back(a);
        ofstream real("real_rent.csv", ios::app);
        for (i = info_zarzadcy.begin(); i != info_zarzadcy.end(); ++i)
        {
            real << *i << ",";
        }
        real << endl;
        real.close();

        cout << "Twoje dane zosta造 pomyslnie dodane do bazy danych" << endl;
    }
    else
    {
        cout << "Twoje konto nie znajduje sie w bazie danych" << endl;
    }
}

void Zarzadca::zobacz_dane_konta()
{
    string _uid, pass;
    char ch;
    int count = 0;

    cout << "Wprowadz unikalny kod identyfikacyjny " << endl;
    cin >> _uid;
    cout << "Wprowadz has這:" << endl;
    ch = _getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << "*";
        ch = _getch();
    }
    cout << endl;
    ifstream check("database_zarzadcy.csv");
    while (check.good())
    {
        getline(check, uid, ',');
        getline(check, imie, ',');
        getline(check, haslo, '\n');
        if (uid == _uid && haslo == pass)
        {
            ifstream r1("real_rent.csv");
            cout << "Twoje konto zosta這 wykryte" << endl;
            cout << "UID\t\tIMIE\t\tHASΜ" << endl;
            cout << uid << "\t\t" << imie << "\t\t" << haslo << endl;
            count = 1;
            wybor_nieruchomosci(_uid, r1);
        }
    }
    check.close();
    if (count == 0)
    {
        cout << "TWOJE KONTO NIE JEST W BAZIE DANYCH" << endl;
        count = 0;
    }
}

void Zarzadca::rejestracja_uzytkownika()
{
    char ch;
    long uid_demo;

    system("CLS");
    cout << "Wprowadz swoje dane :-" << endl;
    cout << "Imie" << endl;
    cin >> imie;
    cout << "Wprowadz has這:" << endl;
    ch = _getch();
    while (ch != 13)
    {
        haslo.push_back(ch);
        cout << "*";
        ch = _getch();
    }
    cout << endl;

    srand(time(NULL));
    uid_demo = rand() % 9999999999 + 1;
    uid = long_to_string(uid_demo);

    ofstream data("database_zarzadcy.csv", ios::app);
    data << uid << "," << imie << "," << haslo << endl;
    cout << "----- Twoj unikalny kod identyfikacyjny to: " << uid << endl;
    data.close();
}

void Zarzadca::wybor_nieruchomosci(string _uid, ifstream& r1)
{
    int it;
    it = 0;
    system("CLS");
    cout << "WITAMY W SILNIKU WYSZUKIWANIA NIERUCHOMOSCI" << endl;
    cout << "Dostepne opcje nieruchomosci to\n" << endl;
    cout << "ID NIERUCHOMOSCI\tMIASTO\tPOWIERZCHNIA\tTYP\tCENA\tADRES" << endl; // rzeczy do dodania
    while (r1.good())
    {
        getline(r1, szczegoły_nieruchomosci, ','); // -1
        if (szczegoły_nieruchomosci == _uid)
        {
            it++;
        }
        getline(r1, szczegoły_nieruchomosci, ','); // 0
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 1
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 2
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 3
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 4
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 5
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 6
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 7
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 8
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 9
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 10
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, ','); // 11
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);
        getline(r1, szczegoły_nieruchomosci, '\n'); // 12
        info_nieruchomosci.push_back(szczegoły_nieruchomosci);

        if (it == 1)
        {
            for (string j: info_nieruchomosci)
            {
                cout << j << "\t";
            }
            cout << endl;
        }
        it = 0;
        info_nieruchomosci.clear();
    }
}

string Zarzadca::long_to_string(long a)
{
    ostringstream outstr;
    outstr << a;
    return outstr.str();
}

string Zarzadca::na_male(string s)
{
    string r = s;
    for (int i = 0; i < r.length(); i++)
        r[i] = tolower(r[i]);
    return r;
}

//---------------------------------------------------------------------------------------------(nowa klasa)
class Administrator // do manipulacji danymi mieszka鎍ow i zarzadcow
{
    string haslo;
public:
    Administrator()
    {
        haslo = "angelpriya";
    }
    void menu();
    void pokaz_dane_uzytkownikow();
    void pokaz_nieruchomosci();
};

void Administrator::menu()
{
    string haslo_demo;
    int wybor;
    char ch;
    cout << "Wprowadz has這 ADMINA" << endl;
    ch = _getch();
    while (ch != 13)
    {
        haslo_demo.push_back(ch);
        cout << "*";
        ch = _getch();
    }
    cout << endl;

    if (haslo == haslo_demo)
    {
        system("CLS");
        cout << "---------- WITAMY W STREFIE ADMINISTRATORA --------" << endl;
        cout << "1. POKAZ DANE AKTUALNYCH UZYTKOWNIKOW" << endl;
        cout << "2. POKAZ NIERUCHOMOSCI W BAZIE DANYCH" << endl;
        cout << "3. Powrot do menu g這wnego" << endl;
        cin >> wybor;
        switch (wybor)
        {
        case 1:
        {
            pokaz_dane_uzytkownikow();
            break;
        }
        case 2:
        {
            pokaz_nieruchomosci();
            break;
        }
        default:
            break;
        }
    }
    else
    {
        cout << "Nie jestes administratorem" << endl;
    }
}

void Administrator::pokaz_dane_uzytkownikow()
{
    string uid, imie, haslo;
    int wybor;
    cout << "------- WITAMY ADMINISTRATORA -------" << endl;
    cout << "1. ZOBACZ DANE ZARZADCOW" << endl;
    cout << "2. ZOBACZ DANE MIESZKA哸OW" << endl;
    cout << "3. POWROT DO MENU GΜWNEGO" << endl;
    cin >> wybor;
    switch (wybor)
    {
    case 1:
    {
        ifstream check("database_zarzadcy.csv");
        cout << "DANE UZYTKOWNIKOW ZAREJESTROWANYCH W SEKCJI ZARZADCOW" << endl;
        cout << "UID\t\tIMIE\t\tHASΜ" << endl;
        while (getline(check, uid, ','))
        {
            getline(check, imie, ',');
            getline(check, haslo, '\n');

            cout << uid << "\t\t" << imie << "\t\t" << haslo << endl;
        }
        check.close();
        break;
    }
    case 2:
    {
        ifstream check("database_mieszka鎍y.csv");
        cout << "DANE UZYTKOWNIKOW ZAREJESTROWANYCH W SEKCJI MIESZKA哸OW" << endl;
        cout << "UID\t\tIMIE\t\tHASΜ" << endl;
        while (getline(check, uid, ','))
        {
            getline(check, imie, ',');
            getline(check, haslo, '\n');

            cout << uid << "\t\t" << imie << "\t\t" << haslo << endl;
        }
        check.close();
        break;
    }
    default:
    {
        break;
    }
    }
}

void Administrator::pokaz_nieruchomosci()
{
    vector<string> info_nieruchomosci;
    vector<string>::iterator i;
    string szczego造_nieruchomosci;
    int wybor;
    cout << "------- WITAMY ADMINISTRATORA -------" << endl;
    cout << "1. ZOBACZ NIERUCHOMOSCI W SEKCJI SPRZEDAZY" << endl;
    cout << "2. ZOBACZ NIERUCHOMOSCI W SEKCJI WYNAJMU" << endl;
    cout << "3. POWROT DO MENU GΜWNEGO" << endl;
    cin >> wybor;
    switch (wybor)
    {
    case 1:
    {
        ifstream check("real_buy.csv");
        cout << "DANE NIERUCHOMOSCI W SEKCJI SPRZEDAZY" << endl;
        cout << "UID\t\tIMIE\t\tHASΜ" << endl; // do dodania
        while (check.good())
        {
            getline(check, szczego造_nieruchomosci, ','); // 0
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 1
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 2
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 3
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 4
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 5
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 6
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 7
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 8
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 9
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 10
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 11
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, '\n'); // 12
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            for (i = info_nieruchomosci.begin(); i != info_nieruchomosci.end(); ++i)
            {
                cout << *i << "\t";
            }
            cout << endl;
            info_nieruchomosci.clear();
        }
        check.close();
        break;
    }
    case 2:
    {
        ifstream check("real_rent.csv");
        cout << "DANE NIERUCHOMOSCI W SEKCJI WYNAJMU" << endl;
        cout << "UID\t\tIMIE\t\tHASΜ" << endl; // do dodania
        while (check.good())
        {
            getline(check, szczego造_nieruchomosci, ','); // 0
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 1
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 2
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 3
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 4
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 5
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 6
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 7
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 8
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 9
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 10
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, ','); // 11
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            getline(check, szczego造_nieruchomosci, '\n'); // 12
            info_nieruchomosci.push_back(szczego造_nieruchomosci);
            for (i = info_nieruchomosci.begin(); i != info_nieruchomosci.end(); ++i)
            {
                cout << *i << "\t";
            }
            cout << endl;
            info_nieruchomosci.clear();
        }
        check.close();
        break;
    }
    default:
    {
        break;
    }
    }
}

//----------------------------------------------------------------------------------------------(main)
int main()
{
    Profil* p;
    int a;
    while (1)
    {
        cout << "-------- Witaj w Systemie Zarzadzania Nieruchomosciami --------" << endl;
        cout << "1. ZARZADCA" << endl;
        cout << "2. MIESZKANIEC" << endl;
        cout << "3. ADMINISTRATOR" << endl;
        cout << "4. WYJDZ" << endl;
        cin >> a;
        if (a == 1)
        {
            system("CLS");
            p = new Zarzadca;
            p->menu();
            delete p;
        }
        else if (a == 2)
        {
            system("CLS");
            p = new Mieszkaniec;
            p->menu();
            delete p;
        }
        else if (a == 3)
        {
            system("CLS");
            Administrator admin;
            admin.menu();
        }
        else
            exit(0);
    }
    return 0;
}
