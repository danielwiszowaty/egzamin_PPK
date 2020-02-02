/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 8: lista jednokierunkowa
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

#include <iostream>   // biblioteka dla strumienie wejscia/wyjscia (input/output)
#include <fstream> 
#include <sstream> 
#include <vector>
#include <string>
#include <string.h>
#include <iomanip>
#include <ios>

#include "funkcje.h"
#include "memory/nvwa/debug_new.h"
 
 
 
int main ()
{
   // ZMIENNE NA STERCIE
   
    {
        int zmienna_na_stosie; // zmienna automatyczna
    }
    
    
   int * p = new int;          // alokacja zmiennej na stercie
   *p = 5; 
   
   
//     p = nullptr;
   
   debug(*p);
   
//    return 0;
   delete p;                   // zwolnienie zmiennej ze sterty
   p = 0; //nullptr;
   delete p;
   
//    return 0;
//     debug(*p);
   
//     *p = 45;
 
    
//    return 0;
   int zmienna = 12;
   int * ptab = new int [zmienna];  // alokacja tablicy na stercie
   delete [] ptab;             // zwolnienie tablicy ze sterty
   ptab = 0;
   
//    return 0;
   const int r = 5;
   int t1 [] = { 1 ,2 ,3 ,4 ,5};
   int t2 [] = { -1 ,-2 ,-3 ,-4 ,-5};
   
   int * polaczona = polacz(t1, r, t2, r);
   
   for (int i = 0; i < r + r; i++)
       std::cout << polaczona[i] << " ";
   std::cout << std::endl;
   
   delete [] polaczona;  // trzeba zwolnić pamięć!
   
//    return 0;
   

   // LISTA JEDNOKIERUNKOWA   
   
   debug(sizeof(typ) + sizeof (element *));
   debug(sizeof(element));
   
//    return 0;
   
   element * pGlowa = nullptr;  // wskaznik na glowe listy
   
    
   for (int i : { 5, 2, 8, 1, 0, 6, 3 } )
      dodajNaPoczatek (pGlowa, i);
    
      
    wypiszOdPoczatkuIteracyjnie(pGlowa);   
    std::cout << std::endl;
   
    std::cout << pGlowa << std::endl; 
    wypiszOdPoczatkuIteracyjnie(pGlowa);   
    std::cout << std::endl;

    //    
    debug(pGlowa);
    usunListeIteracyjnie(pGlowa);
    debug(pGlowa);
    usunListeIteracyjnie(pGlowa);
 
    for (int i : { 5, 2, 8, 1, 0, 6, 3 } )
       dodajNaKoniecIteracyjnie (pGlowa, i);
//     
    wypiszOdPoczatkuIteracyjnie(pGlowa);      
    std::cout << std::endl;      
    usunListeIteracyjnie(pGlowa);
 
    // 
    for (int i : { 5, 2, 8, 1, 0, 6, 3 } )
       dodajNaKoniecRekurencyjnie (pGlowa, i);
    wypiszOdPoczatkuIteracyjnie(pGlowa);      
    std::cout << std::endl;      
// 
//     usunListeIteracyjnie(pGlowa);


    wypiszOdPoczatkuRekurencyjnie(pGlowa, std::cout);
    std::cout << std::endl;      
//     return 0;   

    wypiszOdKoncaRekurencyjnie(pGlowa, std::cout);      
    std::cout << std::endl; 
    
//     usunListeIteracyjnie(pGlowa);
//     return 0;
    
    std::ofstream strumien_plikowy ("liczby-z-listy");
    if (strumien_plikowy)
    {
        strumien_plikowy << "liczby od poczatku:" << std::endl;
        wypiszOdPoczatkuRekurencyjnie(pGlowa, strumien_plikowy);
        strumien_plikowy << std::endl;
        strumien_plikowy << "liczby od konca:" << std::endl;
        wypiszOdKoncaRekurencyjnie(pGlowa, strumien_plikowy);
        strumien_plikowy.close();
    }
        
    usunListeIteracyjnie(pGlowa);
    
//     return 0;
    
   for (int i : { 15, 12, 18, 11, 10, 16, 13 } )
      dodajNaKoniecRekurencyjnie (pGlowa, i);

   wypiszOdPoczatkuIteracyjnie(pGlowa); 
   std::cout << std::endl;
   usunListeOdPoczatkuRekurencyjnie(pGlowa);
   usunListeOdPoczatkuRekurencyjnie(pGlowa);

   for (int i : { 25, 22, 28, 21, 20, 26, 23 } )
      dodajNaKoniecRekurencyjnie (pGlowa, i);
   
   wypiszOdPoczatkuIteracyjnie(pGlowa);   
   std::cout << std::endl;
   usunListeOdKoncaRekurencyjnie(pGlowa);
   usunListeOdKoncaRekurencyjnie(pGlowa);
   
   
   for (int i : { 25, 22, 28, 21, 20, 26, 23 } )
      dodajNaKoniecRekurencyjnie (pGlowa, i);
   
   auto q = znajdzElementRekurencyjnie(pGlowa, 25);
   if (q)
       debug(q->wartosc);
   
   q = nullptr;
   auto pPoprzenikQ = znajdzPoprzednikIteracyjnie(pGlowa, q);
   if (pPoprzenikQ)
       debug(pPoprzenikQ->wartosc);
   else 
       debug(pPoprzenikQ);
   
   usunListeOdKoncaRekurencyjnie(pGlowa);
   return 0; 
   
} 

// Ubi sunt qui ante nos fuerunt?
