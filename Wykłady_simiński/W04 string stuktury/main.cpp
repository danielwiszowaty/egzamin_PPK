/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
 wykład 4: std::string, struktury, unie 
   
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

// najpierw biblioteki standardowe
#include <iostream>  // std::cout, std::cin, std::cerr, ...
#include <iomanip>   // std::precision
#include <vector>    // std::vector<>
#include <string>    // std::string
#include <utility>   // std::pair

// potem własne pliki
#include "struktury.h"
#include "funkcje.h"

 
int main ()
{
   
   // NAPISY: std::string 
   
   std::string napis ("Litwo, ojczyzno moja!"); // inicjalizacja napisu
   
   std::cout << napis << std::endl;  // wypisane napisu
   
   debug(napis.size());    // długość (liczba znaków)
   debug(napis.length());  // to samo co size() 

//       return 0; 

   // operator [ ] dla napisu
   for (std::size_t i = 0; i < napis.size(); i++)
       std::cout << "znak " << i << ": " << napis[i] << std::endl;
   
//    return 0;
   
   for (int i = 0; i < napis.size(); i++)
   if (napis[i] == '!')
      std::cout << "Wykrzyknik wystapił na pozycji " << i << std::endl;

   for (int i = 0; i < napis.length(); i++)
   if (napis[i] == 'o')
      std::cout << "\"o\" wystapiło na pozycji " << i << std::endl; // \"  backslash to znak ucieczki
      
      
   
//    return 0; 
   
   int licznik = 0;
   for (auto znak : napis)  // dla kazdego znaku w napisie, znak jest kopia!
      if (znak == 'o')
         licznik++;
      
   debug(licznik);

//    return 0;   
   
   debug(napis);
   for (auto & znak : napis)   // znak nie jest kopia!
      if (std::islower(znak))    
         znak = std::toupper(znak);  // modyfikacja oryginalu
   debug(napis);
   
//    return 0;
   
   debug(napis);
   napis.push_back(' ');  // dodanie znaku na koniec (jak w wektorze)
   napis.push_back('T');
   napis.push_back('y');
   debug(napis);
   
//    return 0;
   
   napis.pop_back();   // usunięcie elementu z końca (jak w wektorze)
   napis.pop_back();
   napis.pop_back();
   
   debug(napis.size());
   debug(napis.capacity());    
   
//    return 0;
   
   napis.shrink_to_fit();    // capacity jest zmniejszone do size
   debug(napis.size());
   debug(napis.capacity());
   
//    return 0;
   
   napis.back() = '.';   // dostep do ostatniego elementu (możliwość modyfikacji)    
   debug(napis.front()); // dostęp do pierwszego elementu (możliwość modyfikacji)    
   
   debug(napis);
   
//    return 0;
   
   std::string fragment ("cz");
   std::size_t miejsce = napis.find(fragment);   // wyszukanie, gdzie szukany fragment się zaczyna
   debug(napis);
   debug(miejsce);
   
//    return 0;
   
   if (miejsce == std::string::npos)   // not a position -- nie znaleziono wzorca
      std::cout << "nie znaleziono!" << std::endl;
//       return 0;
   
   fragment = std::string ("CZ");
   miejsce = napis.find(fragment);
   debug(napis);
   debug(miejsce);
   
//    return 0;
   
   auto indeks_przecinek = napis.find(',');  // zwraca indeks, jaki ma przecinek
   debug(indeks_przecinek);
   auto litwa = napis.substr(0, indeks_przecinek);  // kopiuję od zerowego elementu do 5, bo taką wartość ma przecinek
   debug(litwa);
   
   
//    return 0;
//    napis.clear();  // usuń znaki z napisu

  debug(napis);
  debug(napis.capacity());
   
//     return 0;

   auto nowy = odwroc(napis);   // odwróć kolejność znaków w napisie
   debug(nowy);   
   
//    return 0;

   
   
   // STRUKTURY 
   
    student Kowalski;
    Kowalski.imie = "Jan";   // dostęp do składowych struktury przez .
    Kowalski.nazwisko = "Kowalski";
    Kowalski.indeks = 12345;
    Kowalski.srednia = 4.5;
    
    
//      std::cout << Kowalski;  
//     return 0;
    wypisz(Kowalski);    
    
//     return 0;
    debug (sizeof(std::string));
    debug (sizeof(int));
    debug (sizeof(double));
    
    debug (2 * sizeof(std::string) + sizeof(int) + sizeof(double));   
    debug (sizeof(student));      

//     return 0;
    
    student EMatianek {"Ewa", "Matianek", 43255, 4.67};  // inicjalizacja struktury 
    wypisz(EMatianek);
//     return 0; 
    
    student dwoje [2] = { Kowalski, EMatianek};   // tablica dwóch studentów
    
    for (int i = 0; i < 2; i++)
        wypisz(dwoje[i]);
    
//     return 0;
    
    std::vector<student> grupa;  // wektor studentów
    grupa.push_back (EMatianek); // dodanie Ewy Matianek do grupy 
    grupa.push_back (Kowalski); 
    
    for (const auto & osoba : grupa)
        wypisz(osoba);
    
//     return 0;
    
    std::vector<student> w_dwoje { Kowalski, EMatianek};   // utworzenie zmiennej i jej inicjalizacja
    
    
    for (const auto & st : grupa)   
       wypisz(st);
//     return 0;
    
    debug(policzSredniaGrupy(grupa));    
    
//     return 0;
    
    // struktura anonimowa
    struct  /* tu nie ma identyfikatora: zdefiniowany nowy typ, ale bez nazwy */
    { 
        int liczba;
        char znak;
    } anonimowa;    // Struktura może być zdefiniowana w funkcji.
    
    anonimowa.liczba = 5;
    anonimowa.znak = 'g';
  
//     return 0;

//     struct punkt  // struktura przeniesiona do pliku struktury.h
//     {
//        double x, y, z;
//     };  
//     
    punkt A { 2, 3, 4 };
    punkt B { 4, 5, 6 };
    
//     return 0;

    double odleglosc_Euklidesowa = Euklides (A, B);
    debug(odleglosc_Euklidesowa);
    double odleglosc_Czebyszowa  = Czebyszow (A, B);
    debug(odleglosc_Czebyszowa);
    
    
    
//     return 0;

    // UNIE
    
    union unia
    {
       int liczba;
       char znak;
       float zmp;
    } mojaUnia;

    debug(sizeof(int));
    debug(sizeof(char));
    debug(sizeof(float));       
    debug(sizeof(int) + sizeof(char) + sizeof(float));
    debug(sizeof(unia));
       
//     return 0;
    mojaUnia.liczba = 123;
    debug(mojaUnia.liczba);
    debug(mojaUnia.zmp);
    debug(mojaUnia.znak);
    
    
//     return 0;
    
    union my_union_type
    {
       int integer;
       char character;
       double floating;
       bool bools[8];  
        
    } testowa;

         
//     return 0;


    testowa.floating = 0.7; // zapisane 8 bajtow
    std::cerr << "(" << __LINE__ << ") integer == " << testowa.integer
                                 << " floating == " << std::setprecision(20) << testowa.floating
                                 << " character == " << testowa.character 
                                 << std::endl;
    
    // wypiszmy bajty
    for (int i = 0; i < 8; i++)
        std::cout  << testowa.bools[i] << " ";
    std::cout << std::endl;
    
    testowa.integer = 23123; // tylko 4 bajty nadpisane
    std::cerr << "(" << __LINE__ << ") integer == " << testowa.integer
                                 << " floating == " << std::setprecision(20) << testowa.floating
                                 << " character == " << testowa.character 
                                 << std::endl;
    
    // wypiszmy bajty
    for (int i = 0; i < 8; i++)
        std::cout << testowa.bools[i] << " ";
    std::cout << std::endl;

    testowa.character = 'w'; // jeden bajt nadpisany
    std::cerr << "(" << __LINE__ << ") integer == " << testowa.integer
                                 << " floating == " << std::setprecision(20) << testowa.floating
                                 << " character == " << testowa.character 
                                 << std::endl;
    
    // wypiszmy bajty
    for (int i = 0; i < 8; i++)
        std::cout << testowa.bools[i] << " ";
    std::cout << std::endl;
    

//     return 0;
    
    
    
//     return 0;
    
//     union test
//     {
//         std::string napis;  // w unii nie może być string 
//         double liczba;
//     } t;
    
     
    
    
    
    samochod wisla;
    
    wisla._nadwozie._nosnosc = nosnosc::samonosne;
    wisla._nadwozie.liczba_bryl = 3;
    wisla._nadwozie.liczba_drzwi = 5;
    wisla._podwozie.szerokosc = 200;
    wisla._podwozie.srednica = 780;
    wisla._silnik.numer_seryjny = "VBP34345NDSIE9934DD";
    wisla._silnik.moc = 35.4; 
    wisla._silnik._paliwo = paliwo::wodor;
    
    samochod odra { 
                    {"3434LJ34LJ34L534", 56.6, paliwo::metan},   
                    {170, 670},  // podwozie
                    {3, 2, nosnosc::ramowe} 
                  };
                  
                  
    // i ostatnia rzecz:
   
    // para: dwa elementy, mogą być różnych typów 
                  
    std::pair<char, double> para { 'j', 33.4343}; // para zbudowana z char i double
    debug(para.first);   // pierwszy element 
    debug(para.second);  // drugi element 
   
    auto /* std::pair<int, samochod>*/  ad_hoc = std::make_pair(23.56, wisla);  // szybkie tworzenie pary z dwóch elementów
    ad_hoc.first = 34;
    ad_hoc.second._nadwozie._nosnosc = nosnosc::ramowe;
   
    return 0;   
    
} 

// Fugit irreparabile tempus.
