    /** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
 wykład 5: strumienie  
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

#include <iostream>   // biblioteka dla strumieni wejscia/wyjscia (input/output)
#include <fstream>    // biblioteka dla strumieni plikowych
#include <sstream>    // biblioteka dla strumieni napisowych
#include <vector>
#include <string>    
#include <iomanip>    // manipulatory strumieni
#include <ios>
#include <string.h>


#include "funkcje.h"
 
 
 
 
int main ()
{
    // standardowe strumienie wyjsciowe 
    std::cout << "standardowy strumien wyjsciowy std::cout" << std::endl;
    std::cerr << "standardowy powiazany z std::cout strumien bledow std::cerr" << std::endl;
    std::clog << "standardowy niepowiazany strumien bledow std::clog" << std::endl;
//     return 0;
    // strumien wejsciowy:
   
    // operacje sformatowane
    char znak; 
    int liczba;
    double zmp;
    
//     std::cin >> liczba >> znak >> zmp;   
    
    
    std::cout << liczba << std::endl;
    std::cout << znak << std::endl;
    std::cout << zmp << std::endl;
//     return 0;
    
    
    // manipulatory:  setw -- szerokość pola
    liczba = 12345;
    std::cout << '|' << liczba << '|' << std::endl;
    std::cout << "-------------------" << std::endl;
    for (int i = 0; i < 15; i++)
        std::cout << '|' << std::setw(i) <<  liczba << '|' << std::endl;
    
//     return 0;
    std::cout << "-------------------" << std::endl;
    
    zmp = 1.2345678901234567890;
    std::cout << '|' << zmp << '|' << std::endl;
    std::cout << "-------------------" << std::endl;
    for (int i = 0; i < 15; i++)
        std::cout << '|' << std::setw(i) <<  zmp << '|' << std::endl;
//     return 0;
    
    // setprecision -- ustalenie liczby cyfr po przecinku w liczbie zmiennoprzecinkowej
    std::cout << "-------------------" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 25; i++)
        std::cout << '|' << std::setw(20) << std::setprecision(i) <<  zmp << '|' << std::endl;
    
//     return 0;
    
    // wyrównanie tresci pola do lewej lub prawej
    std::cout << "-------------------" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << '|' << std::left << std::setw(20) << std::setprecision(i) <<  zmp << '|' << '\t'
                  << '|' << std::right << std::setw(20) << std::setprecision(i) <<  zmp << '|' 
                  << std::endl;
    
//     return 0;
    // zawsze pokazuj kropkę dziesiętną w liczbach zmiennoprzecinkowych              
    std::cout << "-------------------" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << '|' << std::showpoint << std::left << std::setw(20) << std::setprecision(i) <<  zmp << '|' << '\t'
                  << '|' << std::right << std::setw(20) << std::setprecision(i) <<  zmp << '|' 
                  << std::endl;
   
    std::cout << std::endl;
    
//     return 0;
    zmp = 1.2345678901234567890;
    std::cout << '|' << zmp << '|' << std::endl;
    for (int i = 0; i < 15; i++)
        std::cout << '|' << (zmp *= 10) << '|' << std::endl;

    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    
//     return 0;
    
    // nie używaj zapisu wykładniczego
    zmp = 1.2345678901234567890;
    std::cout << '|' << zmp << '|' << std::endl;
//      std::cout << std::setprecision(50);
    for (int i = 0; i < 20; i++)
        std::cout << '|' << std::fixed << (zmp *= 10) << '|' << std::endl;
 
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    
//     return 0;
    zmp = 1.2345678901234567890;
    // użyj zapisu wykładniczego
    std::cout << '|' << zmp << '|' << std::endl;
    for (int i = 0; i < 15; i++)
        std::cout << '|' << std::scientific << (zmp *= 10) << '|' << std::endl;
 
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
//     return 0;
    
    std::cout << "ustawiona wartosc precision dla std::cout == " << std::cout.precision() << std::endl;
    // różne formaty zapisu liczby zmiennoprzecinkowej
    zmp = 123.456;
    std::cout << "std::defaultfloat  " << std::defaultfloat << zmp << std::endl
              << "std::scientific    " << std::scientific   << zmp << std::endl
              << "std::hexfloat      " << std::hexfloat     << zmp << std::endl
              << "std::fixed         " << std::fixed        << zmp << std::endl
              << "std::defaultfloat  " << std::defaultfloat << zmp << std::endl << std::endl; 
    std::cout << "ustawiona wartosc precision dla std::cout == " << std::cout.precision() << std::endl;
    // uzycie manipulatorów std::defaultfloat, std::scientific, std::hexfloat, std::fixed nie zmienia wartosci prezycji (precision)
    
    std::cout << std::endl;
//     return 0;                 
    
    
    // różne podstawy zapisu liczby całkowitej
    std::cout << std::setw(5) << "dec" << std::setw(5) << "oct" 
              << std::setw(5) << "hex" << std::setw(5) << "HEX" << std::endl;
    for (int i = 0 ; i < 30; i++)
       std::cout << std::setw(5) << std::dec << i                       // dziesiętna
                 << std::setw(5) << std::oct << i                       // ósemkowa
                 << std::setw(5) << std::nouppercase << std::hex << i   // szesnastkowa (małymi literami)
                 << std::setw(5) << std::uppercase << std::hex << i     // szesnastkowa (wielkimi literami)
                 << std::endl;

    std::cout << std::endl;
//     return 0;
    
    // wypisanie szesnastkowo liczb całkowitych ujemnych i dodatnich
    for (int i = -10; i < 10 + 1; i++)
       std::cout << i << std::endl;
//     return 0;
    
    
    std::cout << std::dec;  // wróc do wypisywania dziesiątkowego
    
    std::cout << std::showpos;  // wypisuj znak '+' dla liczb dodatnich
    for (int i = -10; i < 10 + 1; i++)
       std::cout << i << std::endl;
//     return 0;
         
    // wypełnij przestrzeń między znakiem a liczbą znakami wypełniającymi
    for (int i = -10; i < 10 + 1; i++)
       std::cout << std::internal << std::setw(5) << i << std::endl;
    
//     return 0;
    
    std::cout.unsetf (std::ios_base::showpos);  // wyłącz flagę 
    std::cout << +10 << std::endl;
    
//     return 0;
    
    bool pf = true;
    
    std::cout << pf << " " << std::endl;  // wypisanie bool jako 0 lub 1
    std::cout << std::boolalpha << pf << std::endl; // wypisz bool jako false lub true
    std::cout << std::endl;

//     return 0;
    
    std::cout << "BANK" << std::endl;
    std::vector<double> konta { -4.3, 45.438, 876.76, 54.65, 1234 };
    
    std::cout << std::fixed << std::right;
    
    // setfill: ustaw znak wypełniający
    for (auto d : konta)
       std::cout << std::setw (10) << std::setprecision(2) << std::setfill ('*') << d << std::endl;
       
//     return 0;
    
    std::cout << std::setfill(' ');
     
    
    // strumienie plikowe 
    
    std::ofstream plikWy; // ("tekst" /*, std::ios_base::app*/);  
    plikWy.open("tekst");                                                      
    
    if (plikWy)   // sprawdzenie, czy plik jest otwarty
    {
        plikWy << "Strumienia plikowego uzywa sie dokladnie tak samo jak strumienia std::cout."; // << std::endl;
//         exit(0);   // Jaka jest zawartość pliku po odkomentowaniu tej linii? 
        plikWy << std::flush;
        plikWy.close();  
        
    }
    
//     return 0;
    
    // zapiszmy liczby 0 1 ... 9 do pliku liczby
    
    const std::string nazwa_pliku_z_liczbami ("plik_z_liczbami");
    std::ofstream liczby (nazwa_pliku_z_liczbami /*, std::ios_base::app */);
    if (liczby)   // sprawdzenie, czy plik jest otwarty
    {
        for (int i = 0; i < 10; i++)
            liczby << std::setw(3) << i << std::endl; 
        
        liczby.close();
    }
    
//     return 0;
    
    // wczytajmy liczby z pliku liczby
    {    
        std::ifstream strumien_liczby_wejscie (nazwa_pliku_z_liczbami);
        if (strumien_liczby_wejscie)   // sprawdzenie, czy plik jest otwarty
        {
            int liczba;
            while (not strumien_liczby_wejscie.eof())
            {
                strumien_liczby_wejscie >> liczba; 
                std::cout << std::setw(3) << liczba;
            }
            
            // Problem: ostatnia wartość z pliku została wypisana dwa razy. Jest to spowodowane tym, że flaga 
            // konca strumienia eof jest ustawiana nie po dotarciu na koniec strumienia (tu: pliku), ale do próbie 
            // odczytu z końca pliku.
            
            std::cout << std::endl;
            strumien_liczby_wejscie.close();
        }
    }
    
    {    
        std::ifstream strumien_liczby_wejscie (nazwa_pliku_z_liczbami);
        if (strumien_liczby_wejscie)   // sprawdzenie, czy plik jest otwarty
        {
            int liczba;
            while (strumien_liczby_wejscie >> liczba) // jeżeli odczyt nie powiedzie, warunek ma wartość false
            {
                std::cout << std::setw(3) << liczba;
            }
            
            std::cout << std::endl;
            strumien_liczby_wejscie.close();
        }
    }
//     return 0;
    
    const std::string jodly ("Szumia jodly na gor szczycie, szumia sobie w dal. A mlodemu smutne zycie, bo ma w sercu zal.");
    
    
    wypisz(std::cout, jodly);  // dziala dla std::cout
    std::cout << std::endl;
    
    std::ofstream strumien_dumka ("dumka");
    if (strumien_dumka)
    {
        wypisz(strumien_dumka, jodly);  // dziala dla std::ofsteam
        strumien_dumka.close();
    }
    
    std::stringstream ss;
    
    ss << jodly;
    std::cout << ss.str() << std::endl;
    
    std::string slowo;
    while (ss >> slowo)
        std::cout << slowo << std::endl;
    
    std::stringstream ss_dumka;
    wypisz(ss_dumka, jodly);   // dziala dla std::stringstream
    debug(ss_dumka.str());
    
//     return 0;
    
    // std::ostream, std::istream
    
//     auto liczby_z_konsoli = wczytaj(std::cin); // dziala dla std::cin
//     for (auto d : liczby_z_konsoli)
//         std::cout << std::setw(8) << d;
//     std::cout << std::endl;

    std::ifstream strumien_z_liczbami ("liczby");
    if (strumien_z_liczbami)
    {
        auto liczby_z_konsoli = wczytaj(strumien_z_liczbami);  // dziala dla std::ifstream
        for (auto d : liczby_z_konsoli)
            std::cout << std::setw(10) << d;
        std::cout << std::endl;
        
        strumien_z_liczbami.close();
    }
    
//     return 0;

    // zadanie domowe:
    // Proszę sprawdzić, czy funkcja wczytaj zadziala dla std::stringstream.
    
    
    // zapis macierzy
    
    generuj_liczby_do_strumienia(std::cout);
    
    std::ofstream strumien_macierz ("macierz");
    if (strumien_macierz)
    {
        generuj_liczby_do_strumienia(strumien_macierz, 5, 10);
        
        strumien_macierz.close();
    }
    
//     return 0;    
    
    // odczyt macierzy
    
    std::ifstream strumien_z_macierza ("macierz");
    if (strumien_z_macierza)
    {
       auto wczytana_macierz = wczytaj_macierz(strumien_z_macierza);
       
       for (auto wiersz : wczytana_macierz)  // dla kazdego wiersza macierzy
       {
           for (auto wartosc : wiersz)  // dla kazdej wartosci w wierszu
               std::cout << std::setw (4) << wartosc;
           std::cout << std::endl;
       }
       
       strumien_z_macierza.close();
    }
//     return 0;
    
    
    
        /*  FLAGI BLEDOW
     
     flaga    | przyczyna             | good() | eof() | fail() | bad()
     ---------+-----------------------+ -------+-------+--------+--------
     goodbit  | brak błędów           | true   | false | false  | false 
     eofbit   | koniec strumienia     | false  | true  | false  | false
     failbit  | błąd logiczny         | false  | false | true   | false
     badbit   | błąd odczytu / zapisu | false  | false | true   | true 
    
     */
    
    {
      std::stringstream s;
      std::string napis {"Litwo, ojczyzno moja!"};
      debug(napis);
      
      s << napis;
      
      double liczba;
      
      s >> liczba;
      
      debug(s.rdstate());  // 4
      debug(s.fail());     // true -- blad logiczny, ale mozna uzywac strumienia!
      debug(s.bad());      // false
      s.clear();           // clear flags
      
//       return 0;
      std::cout << std::endl;
      
      char c;
      s >> c;   // 'L'
      debug(c);
//       return 0;
//       while (not s.eof())
//          s >> c;
      
//       while (s >> c)
//          ;
      
      debug(s.rdstate());  // 6
      debug(s.eof());      // true
      debug(s.fail());     // true
      debug(s.bad());      // false
      debug(s.good());     // false
      s.clear();
      
//       return 0;
      std::cout << std::endl;
      
      std::ifstream p ("nie-istniejacy-plik");
      debug(p.rdstate());  // 4
      debug(p.fail());     // true
      debug(p.bad());      
      debug(p.good());     
      debug(p.eof());
      
      
//       return 0;
      std::cout << std::endl;
      
      char * ptr = nullptr;
      
      s << ptr;
      debug(s.rdstate());  // 1
      debug(s.fail());     // true
      debug(s.bad());      // true  
      debug(s.good());     
      debug(s.eof());
      
      return 0;
      
    }    
  
    return 0;
} 

// Finem suum omnia habent.
