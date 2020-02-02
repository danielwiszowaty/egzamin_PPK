/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład  
 
 */

//#include <iostream>

#include "funkcje-c++.hpp"

int inkrementuj(int a)
{
//     std::cout << "C++: " << __FUNCTION__ << std::endl;
    return ++a;
}

double inkrementuj (double a)
{
    return a + 1;
}

int przeciwna(int a)
{
//     std::cout << "C++: " << __FUNCTION__ << std::endl;
    return -a;
}

double dodaj(int a, double d)
{
    return d + a;
}



