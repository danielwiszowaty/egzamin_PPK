/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
 wykład 4: std::string, struktury, unie 
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl


#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <string>
#include <cmath>


#include "funkcje.h"
 
 
// definicje funkcji

double policzSredniaGrupy(const std::vector<student>& grupa)
{
    if (grupa.empty())
        return -1;
    
    double suma = 0;
    for (const auto & os : grupa)
        suma += os.srednia;
    
    return suma / grupa.size();
}


void wypisz (const student & st)
{
    std::cout << st.imie << " " << st.nazwisko << " (" << st.indeks << ") " << st.srednia << std::endl;
}


std::string odwroc(const std::string & napis)
{
    if (napis.empty())
        return napis;
   
    std::string odwrocony;
    
    for (std::size_t i = napis.size(); i > 0; i--)
        odwrocony.push_back(napis[i - 1]);
    
    return odwrocony;
}



double Euklides (const punkt & A, const punkt & B)
{
    return std::sqrt (std::pow(A.x - B.x, 2) + std::pow(A.y - B.y, 2) + std::pow(A.z - B.z, 2));
}

double Czebyszow (const punkt & A, const punkt & B)
{
    return std::max (std::max(std::fabs(A.x - B.x), std::fabs(A.y - B.y)), std::fabs(A.z - B.z));
}

