#include "pch.h"


int sprowadzalneDoInt(std::string napis)
{
    int integerValue = 0;
    for (int i = 0; i < napis.length(); i++)
    {
        if (napis[i] < '0' || napis[i] > '9')
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

TEST(SprowadzanieDoInt, literyNaPoczatku) {
  EXPECT_EQ(sprowadzalneDoInt("avd132"),0);
}


TEST(SprowadzanieDoInt, literyNaKoncu) {
    EXPECT_EQ(sprowadzalneDoInt("132avd"), 0);
}

TEST(SprowadzanieDoInt, liczby) {
    EXPECT_EQ(sprowadzalneDoInt("15632"), 15632);
}