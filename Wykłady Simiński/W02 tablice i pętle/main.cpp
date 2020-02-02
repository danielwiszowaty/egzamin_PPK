/** @file */

/*
 PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 2: Tablice i petle

 */



#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

// dolaczam biblioteki:
#include <iostream>   // biblioteka dla operacji wejscia/wyjscia
#include <vector>     // tablica o zmiennym rozmiarze
#include <random>     // biblioteka do generowania liczb pseudolosowych
#include <chrono>     // biblioteka do obslugi czasu 


int main ()
{
   // operator trojargumentowy:
   int zmienna = 5;
   debug(zmienna);
   
   bool zwieksz = false;
   int zmieniona = zwieksz ? zmienna + 1 : zmienna - 1;
   
   
//  To samo, inaczej:   
//    int zmieniona;
//    if (zwieksz)
//        zmieniona = zmienna + 1;
//    else 
//        zmieniona = zmienna - 1;
   
   debug(zmieniona);
   
//     return 0;
   
   // typ wyliczeniowy:   
   enum kolor { pik = 5, kier, karo, trefl = 1, joker };
   
   kolor karta; // karta jest zmienna typu kolor
   
   karta = pik;
   debug(karta);
   karta = kier;
   debug(karta);
//    karta = 3; // error: invalid conversion from ‘int’ to ‘main()::kolor’

   debug(karta);  
   
//    return 0;
   karta = joker;
   switch (karta)  // int, char, enum; nie moze byc double, float
   {
      case pik  : std::cout << "Gra w piki daje wyniki." << std::endl;
                 break; 
      case kier : std::cout << "Kto gra w kiera, ten szuka frajera." << std::endl;
                 break;
      case karo: std::cout << "Kto gra w karo, przegra zaro." << std::endl;
                 break;
      case trefl: std::cout << "Trefelki kolorek niewielki." << std::endl;
                 break;
      default : std::cout << "cos innego..." << std::endl;  
                 break;
   }
   
//    return 0;
   
   switch (karta)  // int, char, enum
   {
      case pik :   // bez break! przechodzimy do następnej etykiety
      case trefl: std::cout << "kolor czarny" << std::endl;
                 break;
      case kier:   // bez break! przechodzimy do następnej etykiety
      case karo: std::cout << "kolor czerwony" << std::endl;
                 break;
   }

//    return 0;
   
   debug(trefl - pik);
   debug(karo + 1 == trefl);
   
//    return 0;
    
   enum class figura { walet, dama, krol, as };
   
   figura _karta = figura::krol;
   
   switch (_karta)
   {
      case figura::walet : std::cout << "Co wy wiecie o walecie?" << std::endl;
                           break;
      case figura::dama  : std::cout << "Dama bierze sama." << std::endl;
                           break;
      case figura::as    : std::cout << "As bierze raz." << std::endl;
                           break;
      default:             std::cout << "Figur na figur, mawial swiety Igor." << std::endl;
                           break;
   }
  
//    return 0;
   
//    debug(_karta);   

//    debug(figura::as - figura::walet);  

   
   enum class woj { wojewoda, ksiaze, krol };
//     figura::krol
//     woj::krol
//     return 0;

   // TABLICE
   
    const int rozmiar = 5;   
    int tablica[rozmiar];    
    
//     return 0;    
    
    debug(sizeof(tablica));
    debug(sizeof(tablica) / sizeof(int));
   
//     return 0;
    
    tablica[0] = 5;             
    tablica[rozmiar - 1] = 10;   // odwolanie do ostatniego elementu tablicy
    
    // odwolanie do elemen
    tablica[4] = 12;
    debug(tablica[4]);
    
//     return 0;
    
    tablica[3] = 5; 
    3[tablica] = 123;   // OK, to samo, co linijke wyzej
    
    debug(tablica[3]);
    debug(3[tablica]);
    
    
//     return 0;
    
    
    tablica[0] = 5;
    tablica[-1] = 5;  // kompilator nie sprawdza poprawnosci uzytych indeksow
    debug(tablica[-1]);
    
    debug(tablica[-10]);  
    debug(tablica[1000]);
//     
//     return 0;
    
    // PETLE
    
    int i = 0;
    debug(i);
    while (i < rozmiar /* warunek */)
    {
       tablica[i] = i;
       debug(tablica[i]);
       i++;
    }

//     return 0;
    
   
//     while (std::cin >> i)   
//     {
//        debug(i);
//     }
    
//     return 0;
   
    i = 0;
//     i = 1000;
    
    do 
    {
        debug(tablica[i++]);   
    } while (i < rozmiar);
    
//     return 0;
    
    std::cout << "wypisanie tablicy:" << std::endl;
    for (int i = 0; i < rozmiar; i++)
       debug(tablica[i]);
    
//     return 0;
   
    const int N = 10;   
   // zapisanie for jako while
   for (/* instrukcja */ int i = 0; /* warunek */ i < N; /* instrukcja */ i++)
      std::cout<< i << std::endl;
   
   // for zapisany jako while
      {
        int i = 0;
        while (i < N)
        {
            std::cout<< i << std::endl;
            i++;
        }
      }
 
//     return 0;
   
  
   {
       int i = 1;            // <------------- i zaczyna istniec  <----+                
       {                     //                                        |
           int a;            // <------ a zaczyna istniec              |   <------------+
           i = 2;            // modyfikacja i zdefiniowanego tutaj-----+                |
           int i = -1;       // <------ i zaczyna istniec  <----+    <----------+  <----+
           {                 //                                 |               |       |
               i = 3;        // modyfikacja ostatniego i   -----+               |       |
               int i = 4;    // <------ i zaczyna istniec  <-------+            |       |
                             //                                    |            |       |
           }                 // przestaje istniec i  >-------------+            |       |
           i = 5;            // modyfikacja i zdefiniowanego tutaj -------------+       |
       }                     // przestaja istniec --------------------------------------+       
       std::cout << i << std::endl;  // i ma wartosc 2 
   }                                

//        return 0;
    i = 0;
    for (std::cout << "wypisuje tablice w sposob fikusny" << std::endl /* instrukcja */; 
         rozmiar - i;                                                  /* warunek    */
         std::cout << tablica[i++] << " "                              /* instrukcja */ ) 
        ;  
    
//     return 0;
  
    i = 0; 
    for ( std::cout << "wypisuje tablice w sposob fikusny" << std::endl ; 
          rozmiar - i; 
          std::cout << i++[tablica] << " ") 
        ;   
    
//    for (;;)   // petla nieskonczona
//        debug(1);
   
//    return 0; 
   
   

   std::cout << std::endl; 
   for (auto element : tablica)        // dla kazdego elementu w tablicy
      std::cout << element << " ";     // wypisz element
   std::cout << std::endl;
   
//     return 0;
   
   
   // tablice wielowymiarowe
   const int W = 5;
   const int K = 9;
   int tab2d[W][K];   // tablica niezaincjowana (zawiera wartosci smieciowe)

   for (int w = 0; w < W; w++)       // dla kazdego wiersza
   {  
       for (int k = 0 ; k < K; k++)    // dla kazdego elementu w wierszu   
           std::cout << tab2d[w][k] << " ";   // wypisz wartosc elementu
       std::cout << std::endl;     // po wypisaniu wszystkich elementow wiersza, nowa linia
   }

//    return 0;   
   for (int w = 0; w < W; w++)         
       for (int k = 0 ; k < K; k++)    
           tab2d[w][k] = 10 * w + k;   
       
   for (int w = 0; w < W; w++)    
   {
       for (int k = 0 ; k < K; k++)   
           std::cout << tab2d[w][k] << " ";
       std::cout << std::endl;  
   }
   
//    return 0;
   int zainicjowana [] =  { 21, 22, 23, 24, 25 };   // kompilator domysli sie, jaki ma byc rozmiar tablicy
   for (auto element : zainicjowana)
      std::cout << element << " ";
   std::cout << std::endl;
//    return 0;   
   
   int czesciowo_zainicjowana [15] = { 4, 5 };    // dwie wartosci inicjujace, pozostale 13 elementow wyzerowane
   for (auto element : czesciowo_zainicjowana)
      std::cout << element << " ";
   std::cout << std::endl;
//    return 0;   
   
   int wyzerowana [15] = { };  // cala tablica wyzerowana    
   for (auto element : wyzerowana)
      std::cout << element << " ";
   std::cout << std::endl;
//    return 0;   
   
   
   int t2d [][2] = { {1, 2},    // mozna pominac pierwszy rozmiar tablicy wielowymiarowe, jezeli jest od razu
                     {3, 4},    // inicjowana
                     {5, 6}};
                     
   // tablica trójwymiarowa
   int tab3d[2][3][4] = {
                            { { 1, 2, 3, 4}, { 5, 6, 7, 8}, { 3, 5, 7, 9}  },
                            { { 5, 7, 8, 0}, { 0, 6, 5, 6}, { 3, 4, 5, 6}  }
                      } ;
                       
   // tablica czterowymiarowa
   int czasoprzestrzen[2][3][4][2] = {
                                    {
                                        { { 1, 2 }, { 1, 2 }, { 1, 2 } }, 
                                        { { 5, 6 }, { 7, 8 }, { 3, 5 } },
                                        { { 5, 6 }, { 3, 5 }, { 7, 9 } }
                                    },
                                    { 
                                        { { 1, 2 }, { 1, 2 }, { 1, 2 } }, 
                                        { { 5, 6 }, { 7, 8 }, { 3, 5 } },
                                        { { 5, 6 }, { 3, 5 }, { 7, 9 } }
                                    }
                               } ;     
                               
                               
   czasoprzestrzen[0][1][2][1] = 4;                            
                  
                    
   // nie zadziala dla zwyklej tablicy                 
//    for (auto wiersz : t2d)
//    {
//        for (auto element : wiersz)
//           std::cout << element << " ";
//        std::cout << std::endl;
//    }
      
   
   return 0;
    
} 


// Omnia suum finem habent.
