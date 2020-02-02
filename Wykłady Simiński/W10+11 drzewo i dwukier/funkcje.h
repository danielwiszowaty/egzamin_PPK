/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 10 + 11: drzewo poszukiwań binarnych

 */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream> 

#include "struktury.h"

/** Funkcja dodaje element na początek listy dwukierunkowej
@param[in,out] pHead adres pierwszego elementu listy
@param[in,out] pTail adres ostatniego elementu listy
@param wartosc wartosc do dodania do listy */
void dodajNaPoczatek (element * & pHead, element * & pTail, const typ & wartosc);
 
/** Funkcja wypisuje listę od początku.
@param pHead adres pierwszego elementu listy */
void wypiszOdPoczatku (element * pHead);

/** Funkcja wypisuje listę od konca
@param pTail adres ostatniego elementu listy */
void wypiszOdKonca (element * pTail);

/** Funkcja usuwa listę dwukierunkowa z pamięci.
@param[in,out] pHead adres pierwszego elementu listy (po usunięciu ma wartość nullptr)
@param[in,out] pTail adres ostatniego elementu listy (po usunięciu ma wartość nullptr)
 */
void usunRekurencyjnie (element * & pHead, element * & pTail);

/** Funkcja dodaje rekurencyjnie do drzewa element.
 @param[in,out] pRoot korzeń drzewa
 @param wartosc wartość do dodania
 */
void dodajDoDrzewaRekurencyjnie (wezel * & pRoot, const typ & wartosc);

/** Funkcja dodaje iteracyjnie do drzewa element.
 @param[in,out] pRoot korzeń drzewa
 @param wartosc wartość do dodania
 */
void dodajDoDrzewaIteracyjnie (wezel * & pRoot, typ & wartosc);
void dodajDoDrzewaIteracyjnie2 (wezel * & pRoot, typ & wartosc);

/** Funkcja wypisuje w porządku wartości przechowywane w elementach drzewa.
 * Przechodzi drzewo w głąb.
 @param pRoot korzeń drzewa
 */
void wypisz (wezel * pRoot);

/** Funkcja wypisuje w porządku wartości przechowywane w elementach drzewa. Kolejne warstwy drzewa są wypisywane coraz większym wcięciem.
 @param pRoot korzeń drzewa
 @param wciecie początkowe wcięcie
 */
void wypisz (wezel * pRoot, int wciecie);

/** Funkcja usuwa całe drzewo z pamięci.
@param[in,out] pRoot korzeń drzewa do usunięcia, po usunięciu ma wartość nullptr */
void usunDrzewo (wezel * & pRoot);

/** Funkcja wyszukuje (rekurencyjnie) element o podanej wartości w drzewie o podanym korzeniu. 
@param pRoot korzeń drzewa
@param wartosc wartość do wyszukania
@return adres węzła przechowujący szukaną wartość, gdy nie ma takiego węzła, funkcja zwraca nullptr.
*/
wezel * znajdzRekurencyjnie (wezel * pRoot, const typ & wartosc);

/** Funkcja wyszukuje (iteracyjnie) element o podanej wartości w drzewie o podanym korzeniu. 
@param pRoot korzeń drzewa
@param wartosc wartość do wyszukania
@return adres węzła przechowujący szukaną wartość, gdy nie ma takiego węzła, funkcja zwraca nullptr.
*/
wezel * znajdzIteracyjnie (wezel * pRoot, const typ & wartosc);

/** Operator do latwego wypisywania drzewa.
@param ss strumień do zapisu
@param pRoot korzeń drzewa
@return zmodyfikowany strumień */
std::ostream & operator << (std::ostream & ss, wezel * pRoot);

/** Funkcja sumuje wartości wszystkich elementów w drzewie.
@param pRoot korzeń drzewa
@return suma wartości wszystkich elementów w drzewie
*/
typ zsumujWartosci (wezel * pRoot);

/** Funkcja zlicza elementy w drzewie
@param pRoot korzeń drzewa                
@return liczba wszystkich elementów w drzewie */
int policzWezly (wezel * pRoot);

/** Funkcja wyznacza maksymalną wysokość w drzewie. Drzewo puste ma wysokość zerową.
@param pRoot korzeń drzewa                
@return  wysokość drzewa */
int wysokoscDrzewa (wezel * pRoot);


/** Funkcja usuwa liście z drzewa.
@param pRoot korzeń drzewa  */              
void usunLiscie (wezel * & pRoot);

/** Funkcja zlicza liście drzewa.
@param pRoot korzeń drzewa                
@return liczba wszystkich liści w drzewie */
int policzLiscie (wezel * pRoot);

/** Funkcja wyszukuje rodzic wezla. Funkcja rekurencyjna.
@param pRoot korzeń drzewa
@param pPotomek wezel, ktorego rodzica wyszukuje funkcja
@return adres rodzica pPotomka, jeżeli rodzica nie ma (pRoot) zwraca nullptr.
*/
wezel * znajdzRodzic (wezel * pRoot, wezel * pPotomek);

/** Funkcja wyszukuje rodzic wezla. Funkcja iteracyjnie.
@param pRoot korzeń drzewa
@param pPotomek wezel, ktorego rodzica wyszukuje funkcja
@return adres rodzica pPotomka, jeżeli rodzica nie ma (pRoot) zwraca nullptr.
@todo zadanie domowe
*/
wezel * znajdzRodzicIter (wezel * pRoot, wezel * pPotomek);


/** Funkcja zwraca wezel o minimalnej wartosci w drzewie
@param pRoot korzeń drzewa
@return adres wezla zawierajacego minimalną wartosc
*/
wezel * minimalny (wezel * pRoot);

/** Funkcja zwraca wezel o maksymalnej wartosci w drzewie
@param pRoot korzeń drzewa
@return adres wezla zawierajacego minimalną wartosc
@todo zadanie domowe
*/
wezel * maksymalny (wezel * pRoot);

/** Funkcja zwraca wezel o minimalnej wartosci w drzewie
@param pRoot korzeń drzewa
@return adres wezla zawierajacego minimalną wartosc
@todo zadanie domowe
*/
wezel * minimalnyR (wezel * pRoot);

/** Funkcja zwraca wezel o maksymalnej wartosci w drzewie
@param pRoot korzeń drzewa
@return adres wezla zawierajacego minimalną wartosc
@todo zadanie domowe
*/
wezel * maksymalnyR (wezel * pRoot);


/** Funkcja przechodzi drzewo wszerz i wypisuje (na standardowe wyjście) wartości przechowywane w węzłach.
@param pRoot korzeń drzewa */
void wypiszDrzewoWszerz (wezel * pRoot);


#endif
