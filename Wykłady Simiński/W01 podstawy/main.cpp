

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
 Krzysztof Simiński 
 krzysztof.siminski@polsl.pl (w nagłówku mejla proszę dodać [PPK-SSI-G])
 https://platforma.polsl.pl/rau2/course/view.php?id=116 
 
 
 * układ przedmiotu:
   wykład:       30h
   laboratorium: 30h
   język:        C++ (przynajmniej w standardzie 11)
                 C   (przynajmniej w standardzie 11)
   
   
 * strona przedmiotu na platformie zdalnej edukacji  
   login + hasło do platformy jak do SOTS-a

   https://platforma.polsl.pl/rau2/course/view.php?id=909         Katowice
   https://platforma.polsl.pl/rau2/course/view.php?id=44          Gliwice
   
   Każda sekcja laboratoryjna ma swoje własne hasło na platformie.
   
   - zapisani na platformę
   - konto na github.com 
   
   Na stronie:
   - regulamin przedmiotu
   - oceny
   - materiały dodatkowe
 
 * zaliczenie:
                                     minimum
                                   
   zadanie programistyczne      0-5     3
   10 kartkówek                 0-1
   egzamin                      0-5     3
   
   wzór na wyznacznie oceny końcowej w regulaminie przemiotu
   
   
*  kompilator i środowisko: dowolne, byle spełniało standard przynajmniej C++11 i C11
   
   C++
   - język wysokiego poziomu
   - przenośny, kompilatory na bardzo wiele platform
   - wszechstronny pod względem sprzętu i paradygmatów programowania
   - kompilowany do szybkiego kodu maszynowego (wysoka wydajność niskopoziomowa)
   - wysoce niezawodny
   - starannie zaprojektowany i starannie standardyzowany
   - biblioteka standardowa (z algorytmami i strukturami danych)
   - trudny :-) język dla myślących

   zastosowania C++:
   - programowanie większości systemów operacyjnych (Linux, Windows, Apple)
   - zastosowania komercyjne (Amazon, Amadeus, Google, Facebook, ...)
   - interpretery Javascriptu, maszyny wirtualne Javy, szkielet .NET-u)
   - ciekawostka: przeglądarki internetowe (IE, Firefox, Safari, Chrome)
   - obsługa dalekich połączeń telefonicznych (0-800...)
   - łaziki marsjańskie NASA, CERN, silniki okrętowe MAN, skanery CAT, kontrola lotów Lockheed-Martin)
   
 
 */

// pomocnicza makrodefinicja do wypisywania wartosci
#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

// dolaczone biblioteki standardowe
#include <iostream>   // operacje wejscia/wyjscia
#include <vector>     // tablica o zmiennym rozmiarze
#include <string>     // lancuchy znakowe
#include <cstring>    // memcpy 
#include <limits>     // limity typow

// deklaracje funkcji: 
std::string bits2string (const std::vector<bool> & bits);
template <class T>
std::vector<bool> type2bits (T t);
 

// najprostszy program w C++:

// int main () {} 




int main ()
{
   // C++ język wysokiego poziomu
   
   // język silnie typowany:
   
   int licznik;   // warto nadawac zmiennym sensowne nazwy
   char _01010110110010101Ol111l1l10011011O0I1l0 = 'z';
   debug(_01010110110010101Ol111l1l10011011O0I1l0);
   double __________________________  = 34.54; 
   float _X = 12.34;

//    return 0;
   
   std::cout << "rozmiary zmiennych:" << std::endl;   
   // typ całkowitoliczbowy:
   
   std::cout << "int             " << sizeof (int)           << "B" << std::endl;
   std::cout << "long int        " << sizeof (long int)      << "B" << std::endl;
   std::cout << "long long int   " << sizeof (long long int) << "B" << std::endl;
   std::cout << "unsigned int    " << sizeof (unsigned int)  << "B" << std::endl;
   
   // typ znakowy:
   std::cout << "char            " << sizeof (char)          << "B" << std::endl;
   
   // typ logiczny:
   std::cout << "bool            " << sizeof (bool)          << "B" << std::endl;
   
   // typy zmiennoprzecinkowe:
   std::cout << "float           " << sizeof (float)         << "B" << std::endl;
   std::cout << "double          " << sizeof (double)        << "B" << std::endl;
   std::cout << "long double     " << sizeof (long double)   << "B" << std::endl;

//    return 0; 
   
   debug(std::numeric_limits<double>::max());     // maksimum
   debug(std::numeric_limits<double>::lowest());  // minimum
   debug(std::numeric_limits<double>::min());     // dodatnie minimum
   debug(std::numeric_limits<double>::is_exact);  // czy reprezentacja dokladna?
   debug(std::numeric_limits<double>::epsilon()); // roznica miedzy 1 a nastepna wartoscia
   debug(std::numeric_limits<double>::infinity()); // reprezentacja nieskonczonosci
   
   debug(std::numeric_limits<int>::max());     // maksimum
   debug(std::numeric_limits<int>::lowest());  // minimum
   debug(std::numeric_limits<int>::min());     // dodatnie minimum
   debug(std::numeric_limits<int>::is_exact);  // czy reprezentacja dokladna?
   
//    return 0; 
   
   
   int calkowita = 12;
   float zmp     = 12;
   
   debug(bits2string(type2bits(calkowita)));  // po prostu 4 bajty
   debug(bits2string(type2bits(zmp)));        //  1 bit:    znak
                                              //  8 bitów:  wykładnik (przesunięty o 127)
                                              // 23 bity:   mantysa 
  
//    return 0;
   
   double jedna_dziesiata = 0.1;
   debug(bits2string(type2bits(jedna_dziesiata)));
   
   
//    return 0;
   
   int zmp2int = *((int *) (void *)(& zmp));
   debug(bits2string(type2bits(zmp2int)));
   debug(zmp2int);

//    return 0;
   
   debug(bits2string(type2bits(calkowita)));
   float calkowita2float = *((float *) (void *) (& calkowita));
   debug(bits2string(type2bits(calkowita2float)));
   debug(calkowita);
   debug(calkowita2float);
   
//    return 0;
   
   // dwa zera 
   float zero = 0.0;
   float minus_zero = -0.0;
   
   debug(bits2string(type2bits(zero)));
   debug(bits2string(type2bits(minus_zero)));
   
//    return 0;
   
   
   std::cout << licznik << std::endl;
   
//    return 0;
   
   // inicjalizacja zmiennych:
   int a = 5;
   int b { 10 };
   
//    return 0;
   
   debug(a);
   debug(b);
   debug(a + b);
   debug(a - b);
   debug(a * b);
   debug(a / b);
   
//    return 0;
   
   
   debug((double) a / b);
   debug(1.0 * a / b);
   debug(a % b);
   
   int parzysta = 4;
   int nieparzysta = 5;
   
   debug(parzysta % 2);
   debug(nieparzysta % 2);

//    return 0;
   
   debug(a);
   debug(a++);
   debug(a);
   
   debug(++a);
   debug(a);
//    debug(++a++);
   
   debug(--a);
   debug(a--);
   debug(a);
   
//    return 0;
   
   debug(a == b);
   debug(a != b);
   debug(a > b);
   debug(a >= b);
    
//    return 0;
   
   char znak = 'a'; 
   debug(znak);
   debug(++znak);
   znak = 'a' + 5;
   debug(znak);
   debug('z' - 'a' + 1);
   
   const int ALFABET = 'z' - 'a' + 1;
   debug(ALFABET);
   
//    return 0;
     
   auto z = 12;
   const auto PI = 3.1415;
   debug(PI);
//    PI++;
   
   const int N = 100;
   //N = 12;
   
   constexpr int A = 100;
   

//    return 0;
   
   
   auto s = true;
   auto t {false};
   debug(s);
   debug(t);
   
   a = 0;
   debug(a);
   debug(b);
   
   debug(a and b);
   
   
   debug(s && t);
   debug(s and t);
   debug(s || t);
   debug(s or t);
   debug(!s);
   debug (not s);
   debug (~s);  // negacja bitowa
   
    debug(bits2string(type2bits(s)));
    debug(bits2string(type2bits(~s)));
   
//    return 0;

   debug(a);
   debug(b);
   
   debug(a && b);
   debug(a and b);
   debug(a || b);
   debug(a or b);
   debug (not a);
   debug (~a);
   
   debug(-0 == true);

//    return 0;
   
   int zmienna = 1;
   debug(zmienna << 1);
   debug(zmienna << 2); 
   debug(zmienna << 4);
   
//    return 0;
   
   auto wynik = zmienna << 4 bitor zmienna;
   debug(wynik);

//    return 0;
   
   
   /*
       if (warunek)
          instrukcjaA;
   */
   
   if (true)
      std::cout << "warunek prawdziwy" << std::endl;
      
//    return 0;   

   if (not true)
      std::cout << "warunek prawdziwy" << std::endl;
   else
      std::cout << "warunek nieprawdziwy" << std::endl;
      
      
//    return 0;  
   
   if (1.2345)
       std::cout << "warunek prawdziwy" << std::endl;
      
   if (zmienna == 1)
      std::cout << "zmienna ma wartosc 1" << std::endl;

//    return 0;
   
   if (zmienna++ == 1)
      std::cout << "Jaka wartosc ma zmienna? " << zmienna << std::endl;
   
   debug(zmienna);
//    return 0;
   zmienna = 0;
   a = 4;
   if (zmienna++)
      debug(zmienna);

   debug(zmienna);
//    return 0;
   
   
   zmienna = 0;
   if (zmienna == 1 and ++zmienna)
      debug(zmienna); 
   debug(zmienna); 
//    return 0;   
   zmienna = 0;
   if (zmienna != 1 | zmienna++)
      debug(zmienna); 
   debug(zmienna); 
//    return 0;
   
 
   
   zmienna = 9;
   if (zmienna = 1)
      std::cout << "jedyneczka" << std::endl;
   else 
      std::cout << "cos innego" << std::endl;

//    return 0;
   
   if (zmienna > 5)
      if (zmienna > 10)
          std::cout << "wiecej niz 10" << std::endl;
   else
      std::cout << "czego dotyczy else?" << std::endl; 

//    return 0;

      
   if (zmienna % 2)
      std::cout << "zmienna jest nieparzysta" << std::endl;
   else 
      std::cout << "zmienna jest parzysta" << std::endl;
   
//    return 0;
   
   zmienna = 5;
   
   bool wieksza_niz_5 = zmienna > 5;
   debug(wieksza_niz_5);
   
   return 0;
      
} 

///////////////////


/** @return Returns a vector of bits representing a value of the t variable.
 *  @param t a value to print bits of 
 */

template <class T>
std::vector<bool> type2bits (T t)
{
   std::vector<bool> bits; 
   const int BITS = 8;
   const unsigned int LENGTH = sizeof(T);
   unsigned char bytes [LENGTH];
   memcpy(bytes, (void *) & t, LENGTH);
   for (int i = LENGTH - 1 ; i >= 0; i--)
   {
      unsigned char mask = 0x80;  // 1000 0000
      for (int j = 0; j < BITS; j++)
      {
         if (bytes[i] & mask)
            bits.push_back(true);
         else 
            bits.push_back(false);
         mask >>= 1;
      }
   }
   return bits;    
}

/** @return Returns a string of 0's and 1's of bools in a vector.
 *  @param bits a vector of bits to print
 */ 
std::string bits2string (const std::vector<bool> & bits)
{
   std::string s;
   const int BITS = 8;
   
   int counter = 0;
   for (bool b : bits)
   {
      if (b)
         s += "1";
      else
         s += "0";
      counter++;
      if (counter == BITS)
      {
         s += " ";
         counter = 0;
      }
   }
   return s;
}


// Finis coronat opus.
