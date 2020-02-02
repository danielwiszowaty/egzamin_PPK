    /** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład :  preprocesor

*/ 




#ifdef __cplusplus
#  include <iostream>
#  include <vector>
#  include <deque>

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl
#else
??=include <stdio.h>
#include <string.h>
#include <math.h>
#endif
 
#include "funkcje.h"
 
inline int maks (int a, int b)
{
    return a > b ? a : b;
}
 
int main (int ile, char ** params)
{

    // trojznaki:
//     ??= #
//     ??/ \
//     ??' ^
//     ??( [
//     ??) ]
//     ??! |
//     ??< {
//     ??> }
//     ??- ~
    
    
??=define MAX 5
    
    int tab ??(MAX??);
    for (int i = 0; i < MAX; i++)
    ??<
        tab??(i??) = i;  
        printf("%i ", tab??(i??));
    ??>
    printf("\n");
    
    
//     return 0;
    
    // dolaczenie plikow
    
    // makrodefinicje
    
#undef MAX
    
    //int a = MAX;
    
#define MAX 5   
    int a = MAX;    // to widzi preprocesor
//     int a = 5;   // to widzi kompilator


#undef MAX

#undef COS_DZIWNEGO

#ifdef MAX
   printf("MAX zdefiniowany\n");
   dj;adsjfkads;fja ;jads;fjadsj asjd fadsjf; alk
#endif 
    
   
#define MAX 5  //;  
    int tablica[MAX]; // to widzi preprocesor
 // to widzi kompilator   int tablica[5;];  // to widzi kompilator

//    return 0;
#undef NIEZDEFINIOWANY
    
#define BEZWGL(a)  a > 0 ? a : -a 

   int b = -5 + 1;
   printf("b == %i, BEZWGL(b) == %i\n", b, BEZWGL(b));  // to widzi preprocesor
   printf("b == %i, BEZWGL(b) == %i\n", b, b > 0 ? b : -b); // to widzi kompilator 
   
   
   int c = BEZWGL(b) * 3;
   printf("c == %i\n", c);
   
//    return 0;
   
   
#define SUMA(a, b)  (a + b)

   
   printf("%i + %i == %i\n", b, c, SUMA(b, c));   
//    return 0;
//    int d = 3;
//    int e = 2;
   printf("%i\n", SUMA(b, c));   
   printf("%i\n", SUMA(b, c) * 3);  
   printf("%i\n", (b + c) * 3);  
   
   
#define MNOZ(a,b) ((a) * (b))
   
   printf("%i\n", MNOZ(5, 2));
   printf("%i\n", MNOZ(2 + 3, 2));
   printf("%i\n", (2 + 3 * 2));
   
//    return 0;
  
   
#define SUMA2(a, b)  (a + b)
    
   printf("%i\n", SUMA2(b, c));   
   printf("%i\n", SUMA2(b, c) * 3);   

#define NAZWA(x) #x 
   
   int indeks = MAX;
   printf("%s == %i\n", NAZWA(indeks), indeks);
   
//    return 0;
   
#define SCAL(x, y)  x ## y
   printf("%d\n", SCAL(1, 2));
   printf("%d\n", 12); 
//    printf("%d\n", SCAL(SCAL(1, 2), 3));
  
//   return 0;  
   
#define VARIABLE(t, a)  t t##a
   
   VARIABLE (int, zmienna);
//    int intzmienna ;
   
   intzmienna = 5;
      
//   return 0;  
   
#define ZSCAL(x,y)  SCAL(x,y)
   printf("%d\n", ZSCAL(1, 2));
   printf("%d\n", ZSCAL(ZSCAL(1, 2), 3));

//    return 0;

   

#define ZMIENNA(t, a)  t a
    
   ZMIENNA (int, licznik);  // to widzi preprocesor
//    int licznik;             // to widzi kompilator

   licznik = 4;

   printf("%i\n", licznik);
   
 
#define ZMIENNA_TYP(t, a) t SCAL(t, a)
   
   ZMIENNA_TYP(int, licznik);
   intlicznik = 5;
   
   ZMIENNA_TYP(char, znak);
   charznak = 'a';
   
   ZMIENNA_TYP(double, zmp);
   doublezmp = 2.15;
   
//    return 0;

   
#define MAKS(a,b)  ((a) > (b) ? (a) : (b))
   
   b = 4;
   c = 9;

   printf("%s == %i\n", NAZWA(b), b);
   printf("%s == %i\n", NAZWA(c), c);
   
   printf("%i\n", MAKS(b, c));
   
   printf("%i\n", MAKS(++b, --c));
//    printf("%i\n", ((++b) > (--c) ? (++b) : (--c))));
  
   printf("%s == %i\n", NAZWA(b), b);
   printf("%s == %i\n", NAZWA(c), c);
   
  
   b = 4;
   c = 9;

   printf("%s == %i\n", NAZWA(b), b);
   printf("%s == %i\n", NAZWA(c), c);
   
   printf("%i\n", maks(++b, --c));  // lepiej uzyc funkcji inline
   printf("%s == %i\n", NAZWA(b), b);
   printf("%s == %i\n", NAZWA(c), c);

   
// kompilacja warunkowa

#define TEST

   printf("%i\n", __LINE__);   // numer linii
   
#ifdef TEST 
   printf("%i\n", __LINE__);   
 
#endif

#ifndef TEST
   printf("%i\n", __LINE__);   
#endif

#ifdef TEST
   printf("%i\n", __LINE__);   
#else
   printf("%i\n", __LINE__);   
#endif

// sprawdzenie systemu operacyjnego 
#if defined WIN32  || defined _WIN32  || defined __WIN32__ || defined __NT__
   printf("windows ");
   #ifdef _WIN64
      printf("64b");
   #else
      printf("32b");
   #endif
#elif __APPLE__
    printf("apple");
#elif __linux__
    printf("linux");
#elif __unix__ 
    printf("unix");
#elif defined(_POSIX_VERSION)
    printf("unix");
#else
#   error "nieznany system operacyjny"
#endif   
    
    printf("\n");

// wywolanie bledu kompilacji    
// #error "No koniec juz, przeciez jest juz po czasie..." 
    
//     return 0;
   
// #line 45678
//    int 
   
//      return 0;
// #error "cos poszlo nie tak..."    
    
#
#
#
    
    
#    define SWAP(a, b, typ) do { typ p = a; a = b; b = p; } while(0)  
   
   int aa = 9;
   int bb = 4;
   
   printf("aa == %d\nbb == %d\n", aa, bb);
   SWAP(aa, bb, int);
//    { int p = aa; aa = bb; bb = p; }  
   printf("aa == %d\nbb == %d\n", aa, bb);
   
   
   if (aa > bb)
       SWAP (aa, bb, int);
   else 
       printf("nie zamieniamy\n");
   printf("aa == %d\nbb == %d\n", aa, bb);
   
//    if (aa > bb)
//        { int p = aa; aa = bb; bb = p; };
//    else 
//        printf("nie zamieniamy\n");
//    printf("aa == %d\nbb == %d\n", aa, bb);
                            
   
//    return 0;
    
    
    
#ifdef __cplusplus
    std::cout << "CPP" << std::endl;
#else
    printf("C\n");
#endif
   
    
    
    printf ("%i\n", __LINE__);
    printf ("%s\n", __FILE__);
    printf ("%s\n", __DATE__);
    printf ("%s\n", __TIME__);
    printf ("%i\n", __STDC__);  
    
    printf ("%s\n", __func__);

//     printf ("%s\n", __PRETTY_FUNCTION__);
    
 
    
#ifdef __cplusplus
    std::cout << __LINE__ << std::endl;
    std::cout << __func__ << std::endl;
    std::cout << __FUNCTION__ << std::endl;

#   ifdef __GNUC__  // gcc, g++
    std::cout << __STDC__ << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    
#   elif defined _MSC_VER // visual studio
    std::cout << __STDC__ << std::endl;
    std::cout << __FUNCSIG__ << std::endl;
#   endif
#endif
//        return 0;
//    
//     
    
#define ROZMIAR 1000 
    
#if ROZMIAR > 1000
#error "za duzy rozmiar"
#elif ROZMIAR < 500
#error "za maly rozmiar"
#endif
    
  
    
#define ROZMIAR_TABLICY(x) (sizeof(x) / sizeof(x[0])) 
    
    int t[ROZMIAR];
    
    printf("%lu\n", ROZMIAR_TABLICY(t));
    
//   return 0;

#define STRNCMP( s1, rel, s2, n ) (strncmp( s1, s2, n ) rel 0)
    char * jontek1 = "Szumia jodly na gor szczycie.";
    char * jontek2 = "Szumia sobie w dal.";
    
    printf("%i\n", STRNCMP(jontek1, <, jontek2, 5));
    printf("%i\n", STRNCMP(jontek1, >, jontek2, 30));
    printf("%i\n", STRNCMP(jontek1, ==, jontek2, 5));
    
    
// return 0;    
    
// // X macro

#define LISTA \
    X(a1);    \
    X(a2);    \
    X(a3);    \
    X(b1);    \
    X(b2);    \
//     
#define X(a)   int a
    LISTA ;
#undef X
//     
    int licz = 1;
#define X(a)  a = licz++
    LISTA;
#undef X
//     
#define X(a)  printf("%s == %i\n", #a, a)
    LISTA;
#undef X
//     
#define X(a)  a++
    LISTA;
#undef X   
// 
#define X(a)  printf("%s == %i\n", #a, a)
    LISTA;
#undef X
//     
//     
#define KOLORY               \
    X(czerwony, turkusowy)   \
    X(turkusowy, czerwony)   \
    X(zielony, anilinowy)    \
    X(anilinowy, zielony)    \
    X(niebieski, zolty)      \
    X(zolty, niebieski)      \
    X(czarny, bialy)         \
    X(bialy, czarny)         \
    
    enum kolor 
    {
#define X(a,b)   a,
        KOLORY
#undef X
    };
    
    enum kolor barwa = zielony;  //bialy; //niebieski; //turkusowy;
//     
    switch (barwa)
    {
#define X(a,b)   case a: printf("%s\n", #b); break;
        KOLORY
#undef X
        default: printf("nieznany kolor\n");
    }
//     
    
    
   
   return 0; 
} 

// Cur non dicitur veritas? (TGM)
