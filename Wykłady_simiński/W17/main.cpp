/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład :  

*/

#include <iostream>

#include "funkcje-c.h"
#include "funkcje-c++.hpp"
#include "funkcje-fortran.h"  
 
int main ()
{
 
    int pierwsza = 5;
    int druga = 17;
    double zmp = 3.1415;
    
    std::cout << pierwsza << std::endl;
    
    std::cout << "funkcje zaimplementowane w C:" << std::endl;
    std::cout << dekrementuj(pierwsza) << std::endl;
    std::cout << roznica_bezwzgledna(pierwsza, druga) << std::endl;
    std::cout << std::endl;
    
    std::cout << "funkcje zaimplementowane w C++:" << std::endl;
    
    std::cout << inkrementuj(pierwsza) << std::endl;
    std::cout << inkrementuj(zmp) << std::endl;
    std::cout << przeciwna(druga) << std::endl;
    std::cout << dodaj(pierwsza, zmp) << std::endl;
    std::cout << std::endl;
    
    std::cout << "funkcja zaimplementowana w fortranie:" << std::endl;
    std::cout << sens_tego_wszystkiego () << std::endl; 
    
    return 0; 
} 

// Cur non dicitur veritas? (TGM)
