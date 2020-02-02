/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 8: lista jednokierunkowa

 */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream> 

/** Funkcja alokuje tablicę i zapisuje do niej wszystkie wartości z tablicy t1, a potem wszystkie z tablicy t2.
@param t1 pierwsza tablica wejściowa
@param r1 rozmiar pierwszej tablicy
@param t2 druga tablica wejściowa
@param r2 rozmiar druga tablicy
@return adres tablicy wynikowej
@warning Funkcja alokuje pamięć! */
int * polacz (const int * t1, const int r1, 
              const int * t2, const int r2);


/** Typ użyty w liście jednokierunkowej. */
typedef int typ;  // będziemy mogli łatwo zmienić typ przechowywany w liście


/** element listy jednokierunkowej */
struct element
{
   typ wartosc;       ///< wartosc przechowywana w liście   
   element * pNext;   ///< wskaznik na nastepny element
};  // <--- średnik jest niezbędny


/** Funkcja dodaje liczbe na poczatek listy jednokierunkowej.
@param[in,out] pHead wskaznik na pierwszy element listy – jeżeli element zostanie dododany do listy, wskaźnik zostanie zmodyfikowany. 
@param liczba liczby do dodania na początek listy jednokierunkowej 
*/
void dodajNaPoczatek (element * & pHead, typ liczba);

/** Funkcja wypisuje listę od początku (iteracyjnie).
@param pHead wskaznik na pierwszy element listy
*/
void wypiszOdPoczatkuIteracyjnie (element * pHead);

/** Funkcja wypisuje listę od początku (iteracyjnie).
@param pHead wskaznik na pierwszy element listy
@param[in,out] s strumień do wypisania
*/
void wypiszOdPoczatkuIteracyjnie (element * pHead, std::ostream & ss);

/** Funkcja usuwa listę iteracyjnie.
@param[in,out] pHead wskaznik na pierwszy element listy – po usunięciu listy jest równy nullptr. 
*/
void usunListeIteracyjnie (element * & pHead);

/** Funkcja dodaje liczbe na koniec listy jednokierunkowej (iteracyjnie).
@param[in,out] pHead wskaznik na pierwszy element listy
@param liczba liczby do dodania
*/
void dodajNaKoniecIteracyjnie (element * & pHead, typ liczba);

/** Funkcja dodaje liczbe na koniec listy jednokierunkowej (rekurencyjnie).
@param[in,out] pHead wskaznik na pierwszy element listy
@param liczba liczby do dodania
*/
void dodajNaKoniecRekurencyjnie (element * & pHead, typ liczba);

/** Funkcja wypisuje listę od początku (rekurencyjnie).
@param pHead wskaznik na pierwszy element listy
@param[in,out] s strumień do wypisania
*/
void wypiszOdPoczatkuRekurencyjnie (element * pHead, std::ostream & ss);

/** Funkcja wypisuje listę od końca (rekurencyjnie).
@param pHead wskaznik na pierwszy element listy
@param[in,out] s strumień do wypisania
*/
void wypiszOdKoncaRekurencyjnie (element * pHead, std::ostream & ss);

/** Funkcja usuwa listę rekurencyjnie od poczatku.
@param[in,out] pHead wskaźnik na pierwszy element listy – po usunięciu listy jest równy nullptr. 
@todo zadanie domowe
*/
void usunListeOdPoczatkuRekurencyjnie (element * & pHead);

/** Funkcja usuwa listę rekurencyjnie od konca.
@param[in,out] pHead wskaźnik na pierwszy element listy – po usunięciu listy jest równy nullptr. 
@todo zadanie domowe
*/
void usunListeOdKoncaRekurencyjnie (element * & pHead);

/** Funkcja wyszukuje w liście poprzednik wskazanego elementu w liście.
 * Funkcja iteracyjna.
@param pHead wskaźnik na pierwszy element listy
@param pNastepnik adres elementu, które poprzednik jest szukany
@return adres poprzednika zadanego elementu; jeżeli nie ma takiego elementu, funkcja zwraca wskaźnik zerowy; jeżeli lista jest pusta, funkcja wzraca wskaźnik zerowy. */
element * znajdzPoprzednikIteracyjnie (element * pHead, element * pNastepnik);

/** Funkcja wyszukuje w liście poprzednik wskazanego elementu w liście.
 * Funkcja rekurencyjna.
@param pHead wskaźnik na pierwszy element listy
@param pNastepnik adres elementu, które poprzednik jest szukany
@return adres poprzednika zadanego elementu; jeżeli nie ma takiego elementu, funkcja zwraca wskaźnik zerowy; jeżeli lista jest pusta, funkcja wzraca wskaźnik zerowy.
@todo zadanie domowe */
element * znajdzPoprzednikRekurencyjnie (element * pHead, element * pNastepnik);


/** Funkcja wyszukuje w liście element przechowujący zadaną wartość.
    Funkcja rekurencyjna.
@param pHead wskaźnik na pierwszy element listy
@param liczba wartość przechowywana w szukanym elemencie
@return adres pierwszego elementu przechowującego zadany element; jeżeli nie ma takiego elementu, funkcja zwraca wskaźnik zerowy; jeżeli lista jest pusta, funkcja wzraca wskaźnik zerowy. */
element * znajdzElementRekurencyjnie (element * pHead, typ liczba);

/** Funkcja wyszukuje w liście element przechowujący zadaną wartość.
    Funkcja rekurencyjna.
@param pHead wskaźnik na pierwszy element listy
@param liczba wartość przechowywana w szukanym elemencie
@return adres pierwszego elementu przechowującego zadany element; jeżeli nie ma takiego elementu, funkcja zwraca wskaźnik zerowy; jeżeli lista jest pusta, funkcja wzraca wskaźnik zerowy.
@todo zadanie domowe */
element * znajdzElementIteracyjnie (element * pHead, typ liczba);

#endif
