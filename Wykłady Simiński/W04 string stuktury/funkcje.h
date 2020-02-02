/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 4: std::string, struktury, unie 

 */

// plik nagłówkowy 

// zabezpieczenie przed wielokrotnym dołączaniem pliku nagłówkowego
#ifndef FUNKCJE_H  // jeżeli FUNKCJE_H jest niezdefiniowane ...
                   // jeżeli FUNKCJE_H jest zdefiniowane, to przeskakujemy od razu do #endif 
#define FUNKCJE_H  // ... to zdefiniuj FUNKCJE_H

#include <vector> 
#include <string>

// dołączam deklaracje struktur z pliku struktury.h
#include "struktury.h"
 
// deklaracje funkcji 
// W pliku nagłówkowym trzeba skomentować funkcje, tzn.
// * napisać krótko, co funkcja robi
// * jakie przyjmuje parametry i co one oznaczają
// * co oznaczają wartości zwracane


/** @return odwrócony napis wejściowy (odwrotna kolejność znaków)
 @param napis napis do odwrocenia */
std::string odwroc (const std::string & napis);


/** Funkcja wypisująca studenta na standardowe wyjście.
@param st student do wypisania
@return Funkcja nie zwraca niczego.
*/
void wypisz (const student & st);

/** @param grupa wektor studentów reprezentujący grupę 
 * @return Zwraca srednia grupy studentow. Jezeli grupa jest pusta, zwraca -1. 
 */
double policzSredniaGrupy (const std::vector<student> & grupa);
 


/** Funkcja wyznacza odległość Euklidesa między punktami \f$A = \{x_a, y_z, z_a\}\f$ i \f$B = \{x_b, y_b, z_b\}\f$ zdefiniowana jako \f$  d_{\mathrm{eu}} = \sqrt{ (x_a - x_b)^2 +  (y_a - y_b)^2 +  (z_a - z_b)^2  }  \f$.
@param A pierwszy z punktów
@param B drugi z punktów 
@return odległość Euklidesa
*/
double Euklides (const punkt & A, const punkt & B);

/** Funkcja wyznacza odległość Czebyszowa między punktami między punktami \f$A = \{x_a, y_z, z_a\}\f$ i \f$B = \{x_b, y_b, z_b\}\f$ zdefiniowana jako \f$  d_{\mathrm{cz}} = \max\{ |x_a - x_b|, |y_a - y_b|, |z_a - z_b| \}  \f$.
@param A pierwszy z punktów
@param B drugi z punktów 
@return odległość Czebyszowa
*/
double Czebyszow (const punkt & A, const punkt & B);


#endif  // koniec zabezpieczenia jednokrotnego dołączania pliku nagłówkowego
