/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 10: drzewo poszukiwań binarnych

 */

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream> 

/** Typ użyty w drzewie poszukiwań binarnych. */
typedef int typ;  // będziemy mogli łatwo zmienić typ przechowywany w liście

/** Element listy dwukierunkowej */
struct element 
{
   typ wartosc;      ///< wartosc przechowywana w elemencie listy
   element * pPrev;  ///< adres elementu poprzedniego
   element * pNext;  ///< adres elementu następnego
};


/** węzeł drzewa poszukiwań binarnych */
struct wezel
{
   typ wartosc;     ///< wartość przechowywana w węźle   
   wezel * pLewy,   ///< wskaźnik na lewy potomek
         * pPrawy;  ///< wskaźnik na prawy potemek
};  // <--- średnik jest niezbędny

 


#endif
