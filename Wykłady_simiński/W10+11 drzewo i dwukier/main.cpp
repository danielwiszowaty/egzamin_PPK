/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 10 + 11: drzewo poszukiwań binarnych
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

#include <iostream>   
#include <fstream> 
#include <sstream> 
#include <string.h>
#include <iomanip>
#include <ios>
#include <algorithm>
#include <vector>


 
#include "struktury.h"
#include "funkcje.h"
 
int main ()
{
   // LISTA DWUKIERUNKOWA
    
    element * pGlowa = nullptr,
            * pOgon = nullptr;
    
    for (int i : { 5, 2, 8, 1, 0, 6, 3 })
        dodajNaPoczatek(pGlowa, pOgon, i);
    
        
    wypiszOdPoczatku(pGlowa);
    std::cout << std::endl;
    wypiszOdKonca(pOgon);
    std::cout << std::endl;
    
//     return 0;
    
    usunRekurencyjnie(pGlowa, pOgon);
    usunRekurencyjnie(pGlowa, pOgon);
    
//     return 0; 
    
    
    
   // DRZEWO POSZUKIWAŃ BINARNYCH    
   
   wezel * pKorzen = nullptr;      
    
   for (int i : { 5, 2, 8, 1, 0, 6, 3, 1,2,3,4,5,6,7,8,9})
      dodajDoDrzewaRekurencyjnie(pKorzen, i);
//    return 0;   
  
   wypisz (pKorzen);   
   std::cout << std::endl;
   std::cout << "=================" << std::endl;
//    return 0;
//    wypisz (pKorzen, 0); 
    
//    return 0;
   usunDrzewo(pKorzen);
   usunDrzewo(pKorzen);
//    return 0;
   
    for (int i : { 5, 2, 8, 1, 0, 6, 3, 1,2,3,4,5,6,7,8,9 } )
       dodajDoDrzewaIteracyjnie2(pKorzen, i);
 
    wypisz (pKorzen, 0);
    
//     usunDrzewo(pKorzen);
//     return 0;
   
   std::cout << "rekurencyjnie" << std::endl;
   for (int i : { 5, 2, 8, 1, 0, 6, 3, 4, 10, 11, -3, 12, -1, 7, 9 } )
   {
       auto p = znajdzRekurencyjnie(pKorzen, i);
       if (p)
           std::cout << "szukana wartosc: " << i << ", wartosc w znalezionym wezle: " << p->wartosc << std::endl;
       else
           std::cout << "szukana wartosc " << i << " nie wystepuje w drzewie" << std::endl;
   }
   
//    usunDrzewo(pKorzen);
//      return 0;

   std::cout << "iteracyjnie" << std::endl;
   for (int i : { 5, 2, 8, 1, 0, 6, 3, 4, 10, 11, -3, 12, -1, 7, 9 } )
   {
       auto p = znajdzIteracyjnie(pKorzen, i);
       if (p)
           std::cout << "szukana wartosc: " << i << ", wartosc w znalezionym wezle: " << p->wartosc << std::endl;
       else
           std::cout << "szukana wartosc " << i << " nie wystepuje w drzewie" << std::endl;
           
   }
//    usunDrzewo(pKorzen);
   
   
  
   std::cout << std::endl;
   wypisz(pKorzen, 0);
   std::cout << std::endl;
    
   std::cout << "liczba wezlow w drzewie: ";
   std::cout << policzWezly(pKorzen) << std::endl;
    
   std::cout << "suma wartosci w drzewie: ";
   std::cout << zsumujWartosci(pKorzen) << std::endl;
 
   std::cout << "liczba lisci w drzewie: ";
   std::cout << policzLiscie(pKorzen) << std::endl;
  
   while (pKorzen)
   {
        usunLiscie(pKorzen);
        std::cout << "===================" << std::endl;
        std::cout << std::endl;
        wypisz(pKorzen, 0);
        std::cout << std::endl;
//         std::cout << "wysokosc drzewa: ";
//         std::cout << wysokoscDrzewa(pKorzen) << std::endl;
   }
   usunDrzewo(pKorzen);
//     return 0;
   
   for (int i : { 5, 2, 8, 1, 0, 6, 3, 1,2,3,4,5,6,7,8,9 } )
       dodajDoDrzewaIteracyjnie2(pKorzen, i);
  
   std::cout << std::endl;
   wypisz(pKorzen, 0);
   std::cout << std::endl;    
       
   std::cout << "wysokosc drzewa: ";
   std::cout << wysokoscDrzewa(pKorzen) << std::endl;

//     usunDrzewo(pKorzen);
   
   std::cout << "minimalna wartosc w drzewie: ";
   auto pMini = minimalny(pKorzen);
   if (pMini)
       std::cout << pMini->wartosc << std::endl;
   else 
       std::cout << "drzewo puste" << std::endl;

  
   std::vector<int> liczby { 5, 2, 8, 1, 0, 6, 3, 4, 10, 11, -3, 12, -1, 7, 9 };
   for (int i : liczby)
   //for (int i : { 5, 2, 8, 1, 0, 6, 3, 4, 10, 11, -3, 12, -1, 7, 9 } ) // krócej, a efekt ten sam
   {
      auto p = znajdzIteracyjnie(pKorzen, i);
      if (p)
      {
         auto rodzic = znajdzRodzic(pKorzen, p);
         if (rodzic)
            std::cout << "Rodzicem wezla " << p->wartosc << " jest wezel " << rodzic->wartosc << std::endl;
         else
            std::cout << "Wezel " << p->wartosc << " nie ma rodzica!" << std::endl;
      }
   }

 
 
   std::cout << "przejscie drzewa w glab i wypisanie:" << std::endl;
   wypisz(pKorzen, 0);   

   std::cout << "przejscie drzewa wszerz i wypisanie:" << std::endl;
   wypiszDrzewoWszerz(pKorzen);
   std::cout << std::endl;
    
   usunDrzewo(pKorzen);
   usunDrzewo(pKorzen);  // na wszelki wypadek próbuję usunąć drzewo jeszcze raz
   
//    return 0;
   
 

   return 0; 
} 

// Cur non dicitur veritas? (TGM)
