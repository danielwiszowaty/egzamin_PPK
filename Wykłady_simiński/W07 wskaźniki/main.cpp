/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
 wykład 7: wskazniki
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

#include <iostream>   // biblioteka dla strumienie wejscia/wyjscia (input/output)
#include <fstream> 
#include <sstream> 
#include <vector>
#include <string>
#include <string.h>
#include <iomanip>
#include <ios>

#include "funkcje.h"
 
 
 
 
int main (int ile, char * params[])
{
   int a;
   int * pa;
   
   debug(sizeof(a));
   debug(sizeof(pa)); 
   
   {
    long double zmp;
    long double * pzmp;
    
    debug(sizeof(zmp));
    debug(sizeof(pzmp));
   }
//    return 0;
   
   long double zmp, * pzmp;
   
   debug(sizeof(zmp));
   debug(sizeof(pzmp)); // rozmiar wskaźnika jest taki jak rozmiar słowa maszynowego bez względu na typ wskazywany

//    return 0;
   
   
//    int * w,  p;  
   int * w, * p;  
   w = & a;  
   p = & a;  // w i p wskazują na tę samą zmienną a
   
   debug(w);
   debug(p);
//    return 0;
   
   a = 5;
   debug(*w);
   a = 6;
   debug(*w);
   *w = 23;
   debug(a);
   
//    return 0;
   debug(*(w + 1));  
//    *(w + 1) = 123;
    debug(*(w + 1));  
   
//    return 0;
  
//  return 0;
   
   
   
   int * wsk = nullptr;   // wskaźnik do zmiennej 
   const int STALA = 5;   // stała  
//    wsk = & STALA;   // error: invalid conversion from ‘const int*’ to ‘int*’ 
   
//    return 0;
   
   
   const int * pconst = & STALA;   // wskaznik do stałej 
   pconst = wsk;    // wskaźnik do stałej wskazuje stałą - OK 
   //*pconst = 4; // error: assignment of read-only location ‘* pconst’


//    return 0;
   
   int const * constp = & STALA;    // wskaźnik do stałej zapisany trochę inaczej niż poprzednio
   constp = wsk;
   //*constp = 4;

//    return 0;
   
   int * const constpint = & a;   // stały wskaźnik do zmiennej - OK
//    constpint++; // nie można modyfikować stałego wskaźnika
   
//    int * const intpconst = & STALA; // stały wskaźnik do zmiennej użyty do stałej - błąd: error: invalid conversion from ‘const int*’ to ‘int*’ 

   
   const int * const constintpconst = & STALA;  // staly wskaźnik do stałej 
//    constintpconst++;
//     return 0;
   

   //------------------------------------------------
   // TABLICE 
   
   const int N = 10;
   int tab[N];
   
   
   tab[5] = 4321;   
   
   
   // arytmetyka wskaznikow
   
   pa = & a;
   debug(pa);
   pa += 1;   // adres większy o sizeof(int), tutaj o 4 
   debug(pa);
   {
        double zmp, *pzmp;
        pzmp = & zmp;
        
        debug(pzmp);
        pzmp++;   // adres większy o sizeof(double) 
        debug(pzmp);
   }
//    return 0;
   
   // odwołanie do tablic przy użyciu wskaźników
   
   debug(tab);
   debug(*tab);
   debug(tab[0]);
   
//    return 0;
   
   // wypisanie adresow komorek tablicy:
   
   for (int i = 0; i < N; i++)
       std::cout << tab + i << '\t' << *(tab + i) << std::endl;
   
   tab[5] = 125;
   std::cout << tab[5] << '\t' << *(tab + 5) << std::endl;
   
//    return 0;
   
   
   // dlaczego 5[tab] dziala jak tab[5]?
   
   std::cout << tab[5] << std::endl;
   std::cout << *(tab + 5) << std::endl; // kompilator dostęp do elementu tablicy przez [ ] przekształca na zapis wskaźnikowy
   std::cout << *(5 + tab) << std::endl;
   std::cout << 5[tab] << std::endl;
   
   
//    return 0;
   
   // jeszcze raz odwołujemy się do elementów tablicy na dwa sposoby:
   
   for (int i = 0; i < N; i++)
       std::cout << tab[i] << '\t' << *(tab + i) << std::endl;
   
//    return 0;
   
   // przekazywanie tablic do funkcji
   
//    return 0;
      {
        const int ROZMIAR = 14;
        int tablica [ROZMIAR];
        
        // przekazywanie tablicy do funkcji
        wypelnij(tablica, ROZMIAR); 
        wypisz(std::cout, tablica, ROZMIAR);
        fill(tablica, ROZMIAR);
        wypisz(std::cout, tablica, ROZMIAR);
        
      }
      
   *pa = 9;   
   debug(*pa);
   debug(pa[4]);   
//    pa[4] = 123;  // stąpanie po cieńkim lodzie (kodzie :-)
      
//    return 0;
   
 
   
   // tablice wielowymiarowe:
   
   const int X = 10;
   const int Y = 20;
   const int Z = 30;
   const int U = 40;
   
   int x = 3;
   int y = 5;
   int z = 8;
   int u = 9;
   
   int tab1D[X];
   tab1D[x] = 1;
   debug(*(tab1D + x));
   
//    return 0;
   
   int tab2D[X][Y];
   tab2D[x][y] = 12;
   int x_tab2D = *(*(tab2D + x) + y);
   debug(x_tab2D);
   
//    retur n 0;
   
   
   int tab3D[X][Y][Z];
   tab3D[x][y][z] = 123;
   int x_tab3D = *(*(*(tab3D + x) + y) + z);
   debug (x_tab3D);
//    return 0;
   
   int tab4D[X][Y][Z][U];
   tab4D[x][y][z][u] = 1234;
   int x_tab4D = *(*(*(*(tab4D + x) + y) + z) + u);
   debug(x_tab4D);
   
//    return 0;
   
   
   // wskazniki do funkcji
   
   debug((void *) wypisz);     // nazwa funkcji jest jej adresem w pamięci
   debug((void *) kwadraty);
   debug((void *) negacja);
   debug((void *) odwroc);
   
   wypelnij(tab, N);
   wypisz(std::cout, tab, N);
   kwadraty(tab, N);
   wypisz(std::cout, tab, N);
   negacja(tab, N);
   wypisz(std::cout, tab, N);
   odwroc(tab, N);
   wypisz(std::cout, tab, N);
   
   
   
//    return 0;
   
   // wskazniki na funkcje
   
   
   void (*pf) (int [], const int);   // pf jest wskaznikiem do funkcji przyjmujacej jako listę parametrów: tablicę intów i stałą intową, a niezwracającej niczego.

   pf = wypelnij; // przypisanie adresu funkcji wypelnij do wskaznika
       
//    pf = negacja;
//    pf = odwroc; 
   
   wypisz(std::cout, tab, N);   
   pf (tab, N);   // to samo co wypelnij(tab, N);
   pf = kwadraty;
   pf (tab, N);   // to samo co kwadraty(tab, N);  używam funkcji wskazywanej przez zmienną pf, czyli funkcji kwadraty
   wypisz(std::cout, tab, N);   
//    debug(pf);
   
//    return 0;
   
   pf = kwadraty;   
   pf(tab, N);     
   wypisz(std::cout, tab, N);
//    return 0;
   
   pf = negacja;    
   pf(tab, N);     
   wypisz(std::cout, tab, N);
//    return 0;
   
   
   pf = odwroc;    
   pf(tab, N);     
   wypisz(std::cout, tab, N);
//    return 0;
   
   // tablica wskaznikow na funkcje
   void (*tpf []) (int [], const int) = { wypelnij, kwadraty, negacja, odwroc };  // tpf jest tablicą wskaźników na funkcje, które przyjmują dwa parametry i zwracają void, i tablicę inicjuję adresami czterech funkcji. 
  
   for (int i = 0; i < 4; i++)
   {
       std::cout << std::endl;
       wypelnij(tab, N);
       wypisz(std::cout, tab, N);   
       tpf[i] (tab, N);
       wypisz(std::cout, tab, N); 
   }
   
//    return 0;

   
   
   // typedef 
   
   
   // zwykla zmienna
   typedef int calkowita;
   calkowita liczba = 5; // to samo co int liczba = 5;
   debug(liczba);
   
   // wskaznik 
   typedef int * wskaznik_na_int;
   wskaznik_na_int pinteger = & liczba;  // to samo co int * pinteger = & liczba;
   typedef calkowita * wskaznik_na_calkowita;
   wskaznik_na_calkowita pppp = & liczba;
   
   // tablica 
   typedef int tabInt [10];
   
   tabInt tablica_intow;
   tablica_intow[0] = 12;
   debug(*(tablica_intow));
   
//    return 0;
   
   
   // wskaznik na funkcje
   
   typedef  void (* wskaznik_na_funkcje ) (int [], const int); // wskaznik_na_funkcje jest typem, nie zmienna!
   
   
   wskaznik_na_funkcje pKwadraty = kwadraty;

//    void (*tpf []) (int [], const int) = { wypelnij, kwadraty, negacja, odwroc };  
   
   wskaznik_na_funkcje tablica_wskaznikow[ ]  = {wypelnij, kwadraty, negacja, odwroc}; // co samo co 
   //    void (*tpf []) (int [], const int) = { wypelnij, kwadraty, negacja, odwroc };    
   
   
    // wektor wskaznikow na funkcje
   std::vector<void (*) (int [], const int)> wpf = { wypelnij, kwadraty, negacja, odwroc };
   
   for (auto & p : wpf)
      p(tab, N);
   wypisz (std::cout, tab, N);
//    return 0;

   
   typedef void (*wsf) (int [], const int);  
   
   
   std::vector<wsf> tablicaWskaznikow = { wypelnij, kwadraty, negacja, odwroc };
   for (auto & p : tablicaWskaznikow)
      p(tab, N);
   wypisz (std::cout, tab, N);
   
   return 0;
   
   
   /// dotad
    
   // wskazniki dla niesformatowanych strumieni:
   
   // operacje wyjsciowe:
   {
      std::ofstream plik ("tekst");
      if (plik)
      {
         char napis [] = "Szumia jodly na gor szczycie, szumia sobie w dal.";
         const int len = strlen(napis);
         
         plik.write(napis, len); // zapisuje do strumienia 'len' bajtów (charów)
         plik.close();
      }
   }
   
    return 0;
   
   
    // wejscie niesformatowane:
    {
       std::ifstream plik ("tekst");
       if (plik)
       {  
           while (not plik.eof())
           {
              char znak;
              plik.get(znak);  // czytaj znak
              
              if (plik)   // jeżeli udało się wczytać znak
                 std::cout << znak;
           }
           plik.close();
       }
       std::cout << std::endl;
    }
    return 0;
    
   

    
    {
       std::ifstream plik ("tekst");
       if (plik)
       {
          const int LEN = 100;
          char napis [LEN] = {}; 
          
          plik.read(napis, LEN);  
          plik.close();
          
          debug(napis); 
       }
    }
   
   return 0;
   
    // operacje binarne
    
    {
       std::ofstream plik ("liczby", std::ios_base::binary);
       if (plik)
       {
          const int LEN = 5;
          int liczby [] = { -2, -1, 0, 1, 2 };
          
          plik.write((char *) & liczby, LEN * sizeof(int));   
          
          plik.close();
       }
    }
    return 0;
    
    {
       std::ifstream plik ("liczby", std::ios_base::binary);
       if (plik)
       {
          plik.seekg (0, plik.end);  // ustaw się na końcu pliku
          int ile = plik.tellg();    // ile bajtow od początku?
          debug(ile);
          
          plik.seekg (0, plik.beg);  // ustaw się na początku pliku
          
          const int LEN = 25;
          int liczby [LEN];
          
          plik.read((char *) & liczby, ile);    
          debug(plik.gcount());  
          
          plik.close();
          
          // wypiszmy tablicę:
          wypisz(std::cout, liczby, ile / sizeof(int));  
          
          for (int i = 0; i < ile / sizeof (int); i++)
             std::cout << liczby[i] << " ";
          std::cout << std::endl;
          
          
       }
    }
    
   
    return 0;
} 

// Post iucundam iuventutem nos habebit humus.
