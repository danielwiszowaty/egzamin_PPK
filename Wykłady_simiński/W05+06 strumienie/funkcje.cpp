/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 5: strumienie   
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl


#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>

#include "funkcje.h"

std::vector<std::vector<int> > wczytaj_macierz(std::istream& strumien)
{
    std::vector<std::vector<int>>  macierz;  
    
    int liczba;
    std::string linia;
    while (getline(strumien, linia))  // dopóki da się przeczytać całą linię ze strumienia 
    {
//         std::cout << "test: " << linia << std::endl;
        std::stringstream ss;
        ss << linia;  // zapisuję linię do stringstreama
        
        std::vector<int> wiersz_macierzy; 
        while (ss >> liczba) // dopóki da się przeczytać liczby we strumienia łańcuchowego (stringstream)
        {
//             std::cout << liczba << std::endl;
            wiersz_macierzy.push_back(liczba); // dodaj liczbę do wiersza macierzy
        }
        
        macierz.push_back(wiersz_macierzy);  // gotowy wiersz dodaj do macierzy
    }
    
    return macierz; // gotową macierz po prostu wzróć
}


void generuj_liczby_do_strumienia(std::ostream & strumien, const int W, const int K)
{
    std::default_random_engine silnik;
    silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> rozklad (-10, 10);
    
    //-----------------
    
    for (int w = 0; w < W; w++) // dla kazdego wiersza
    {
        for (int k = 0; k < K; k++) // dla kazdej kolumny w wierszu
        {
            strumien << std::setw(5) << rozklad(silnik);
        }
        strumien << std::endl;
    }
}

 
std::vector<double> wczytaj(std::istream& strumien)
{
    std::vector<double> wczytane_liczby;
    double liczba;
    while(strumien >> liczba)
    {
        wczytane_liczby.push_back(liczba);
    }
    return wczytane_liczby;
}
 

void wypisz(std::ostream& s, const std::string& tekst)
{
    s << tekst;
}
 
