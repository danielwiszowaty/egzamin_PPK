/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 

 */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <stdlib.h>

/** @return liczba znakow w napisie (bez koncowego zera */
size_t my_strlen (const char * pNapis);

/** Funkcja kopiuje napis ze zrodla do celu (nadpisuje napis w tablicy docelowej).
@param cel adres tablicy docelowej, do ktorej kopiowany jest lancuch ze zrodla
@param zrodlo tablica, ktora jest kopiowana do celu */
void my_strcpy (char * cel, const char * zrodlo);


/** 
 * Funkcja kopiuje napisz z tablicy zrodlowej i zapisuje na koncu napisu w tablicy docelowej
@param cel adres tablicy docelowej
@param zrodlo tablica, ktora jest kopiowana do celu */
void my_strcat (char * cel, const char * zrodlo);

/** 
@return  mniej niz 0, gdy napis s jest mniejszy od t
                   0, gdy napis s jest rowny t
        wiecej niz 0, gdy napis s jest wiekszy od t
*/
int my_strcmp (const char * s, const char * t);

/** 
@param s string to search in
@param p patter to search for 
@return an address of the first character of found pattern or 0 if pattern not found */
char * my_strstr (char * s, char * p);

/** szyfrowanie napisu metoda Cezara
@param s napis do zaszyfrowania
@param przesuniecie przesuniecie :-)
*/
void cezar (char * s, int przesuniecie);

#endif

