/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 7: wskaźniki
 */


#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <vector> 
#include <string>
#include <iostream>
#include <string>

/** Funkcja wypisuje tablicę do strumienia.
  @param s strumień wyjściowy
  @param tab tablica do wypisania
  @param ROZMIAR rozmiar tablicy do wypisania
  */
void wypisz (std::ostream & s, int tab [], const int ROZMIAR);

/** Funkcja wypełnia tablicę liczbami całkowitymi.
  @param tab tablica do wypełnienia
  @param ROZMIAR rozmiar tablicy
*/
void wypelnij (int tab [], const int ROZMIAR);

/** Funkcja wypełnia tablicę kolejnymi wartościami o 1 do ROZMIAR.
  @param tab tablica do wypełnienia
  @param ROZMIAR rozmiar tablicy
*/
void fill (int* tab, const int ROZMIAR);

/** Funkcja podnosi wszystkie wartości do kwadratu.
  @param tab tablica do podniesienia do kwadratu
  @param ROZMIAR rozmiar tablicy
*/
void kwadraty (int * tab, const int ROZMIAR);

/** Funkcja neguje wszystkie wartości do kwadratu.
  @param tab tablica
  @param ROZMIAR rozmiar tablicy
*/
void negacja (int tab [], const int ROZMIAR);

/** Funkcja odwraca kolejność elementów w tablicy
  @param tab tablica
  @param ROZMIAR rozmiar tablicy
*/
void odwroc (int tab [], const int ROZMIAR);


#endif
