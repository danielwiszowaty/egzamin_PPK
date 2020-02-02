/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 5: strumienie

 */


#include <vector> 
#include <string>
#include <iostream>
#include <string>

#ifndef FUNKCJE_H
#define FUNKCJE_H


/** Funkcja wczytuje macierz liczb całkowitych ze strumienia. Wiersze macierzy są rozdzielone znakami nowej linii.
  @param s strumien, z którego funkcja czyta 
  @return macierz odczytanych liczb
*/
std::vector<std::vector<int>> 
wczytaj_macierz (std::istream & s);
 

/** Funkcja, która wypisuje podany tekst do strumienia wyjściowego.
  Funkcja dziala dla std::cout, strumieni plikowych i lancuchowych, bo jako pierwszy
  parametr przyjmuje referencję do std::ostream, a std::cout jest std::ostreamem, std::ofstream jest std::ostreamem i std::stringstream jest std::ostreamem. Dlatego to dziala! 
  Korzystamy tutaj z polimorfizmu :-)

  @param s strumień wyjściowy
  @param tekst tekst do wypisania */
void wypisz (std::ostream & s, const std::string & tekst);

/** Funkcja, która zapisuje do przekazanego strumienia N liczb zmiennoprzecinkowych z rozkładu normanego N(0,1).
    Umożliwia zapis do pliku i na ekran dzięki polimorfizmowi.
    @param[in,out] s strumien do zapisu
    @param W liczba wierszy macierzy
    @param K liczba kolumn macierzy
    */
void generuj_liczby_do_strumienia (std::ostream & s, const int W = 5, const int K = 7);


/** Funkcja, która wczytuje macierz ze strumienia
  @param[in,out] s strumień, z którego będą czytane liczby
  @return wektor wczytanych liczb
*/
std::vector<double> wczytaj (std::istream & s);


/** funkcja do wypisywania 
  @param s strumien do wypisywania
  @param liczby wektor liczb do wypisania
*/
void wypisz (std::ostream & s, const std::vector<double> & liczby); 


/** operator wypisywania, bardzo podobny do funkcji wypisz, ale elegantszy w użyciu 
  @param s strumien do wypisywania
  @param liczby wektor liczb do wypisania
  @return strumien, do ktorego zostana wypisane liczby
*/
std::ostream & operator << (std::ostream & s, const std::vector<double> & liczby);

#endif
