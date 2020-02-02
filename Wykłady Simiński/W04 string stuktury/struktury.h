/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
 wykład 4: std::string, struktury, unie 

 */

#ifndef STRUKTURY_H  // zabezpieczenie przed wielokrotnym dołączaniem pliku nagłówkowego
#define STRUKTURY_H

#include <vector> 
#include <string>


/**
 Struktura opisująca studenta.
 */
struct student
{
    std::string imie,      ///< imię
                nazwisko;  ///< nazwisko
    /** numer indeksu */            
    int indeks;
    /** średnia ocen studenta */
    double srednia;
    
};  // <-- średnik jest niezbędny!
 
/** Struktura reprezentująca punkt w przestrzeni trójwymiarowej. */ 
struct punkt 
{
   double x, y, z;
};

/** rodzaje paliwa dla pojazdu */
enum class paliwo { benzyna, 
                    olej_napedowy,  ///< diesel 
                    propan,         ///< LPG
                    metan,       
                    wodor, 
                    prad            ///< tramwaj :-)
                  };

/** struktura reprezentująca silnik */
struct silnik
{
    std::string numer_seryjny;  ///< numer seryjny może zawierać litery
    double moc;                 ///< moc silnika w kW
    paliwo _paliwo;             ///< rodzaj paliwa
};
/** podwozie pojazdu */    
struct podwozie
{
    /** szerokość opony w mm */
    float szerokosc; 
    /** średnica koła w mm */
    float srednica;
};

/** Klasy nadwozia */
enum class nosnosc { samonosne,   ///< jak w większości samochodów osobowych 
                     ramowe       ///< jak w ciężarowych
                   };
                  
/** Opis nadwozia */                   
struct nadwozie
{
    int liczba_drzwi;
    int liczba_bryl;   
    nosnosc _nosnosc;
};

/** Samochód */
struct samochod
{
    silnik _silnik;         
    podwozie _podwozie;
    nadwozie _nadwozie;
};

#endif
