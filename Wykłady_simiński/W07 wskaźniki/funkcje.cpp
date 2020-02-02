/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 7: wskazniki  
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl


#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>

#include "funkcje.h"
 
void wypelnij(int tab [], const int ROZMIAR)
{
    for (int i = 0; i < ROZMIAR; i++)
        tab[i] = i * i;
}
 

void wypisz(std::ostream& s, int tab [], const int ROZMIAR)
{
    for (int i = 0; i < ROZMIAR; i++)
        s << tab[i] << " ";
    s << std::endl;
}

void fill(int* tab, const int ROZMIAR)
{
    for (int i = 0; i < ROZMIAR; i++)
        tab[i] = -i;
}

void kwadraty(int* tab, const int ROZMIAR)
{
    for (int i = 0; i < ROZMIAR; i++)
        tab[i] *= tab[i];
}

void negacja(int tab [], const int ROZMIAR)
{
    for (int i = 0; i < ROZMIAR; i++)
        tab[i] *= -1;
}

void odwroc(int * tab, const int ROZMIAR)
{
    int * pLewy = tab;
    int * pPrawy = (tab + ROZMIAR - 1);
    
    while(pLewy < pPrawy)
        std::swap(*pLewy++, *pPrawy--);
}
