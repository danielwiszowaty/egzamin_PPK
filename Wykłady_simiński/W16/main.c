/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład :  

*/

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struktury.h"
#include "funkcje.h"
 
#ifndef __cplusplus 
int suma (a, b)
int a; int b;
{
    return a + b;
}
#endif

#ifndef __cplusplus 
iloczyn (a, b)
int a;
int b;
{
    return a * b;
}
#endif 
 
#ifndef __cplusplus 
struct zespolona { double re; double im; } foo ()
{
    struct zespolona wynik;
    wynik.re = 2;
    wynik.im = 2;
    return wynik;
}
#endif

#ifndef __cplusplus 
void wypisz ( struct zespolona { double re; double im; } z )
{
    printf ("%f + %fi\n", z.re, z.im);
}
#endif
 
int main ()
{
#if __cplusplus
    printf ("C++\n");
#else
    printf ("C\n");
#endif  
    
    

//     return 0;
    
    printf ("sizeof(char) == %lu\n",  sizeof(char));
    printf ("sizeof(\'a\') == %lu\n", sizeof('a'));
    

//     return 0;
 
//     //-------------------

    int x[10];
    {
        struct x
        {
            int a;
        };
     
        printf ("sizeof(x) == %lu\n",  sizeof(x));
        printf ("sizeof(struct x) == %lu\n",  sizeof(struct x));
    }
    
//     return 0;
    
    {
        auto N = 100; 
//         const M = 1000;
        
        enum kierunek { polnoc, poludnie, wschod, zachod };
        enum kierunek kompas = polnoc;
//         enum kierunek azymut = 3;
        
        
    }
    
//      return 0;
    
//     
    {
        int * p = (int *) malloc (sizeof(int) * 10);
        
        free (p);
        
        
        char c;
        void * pvoid = & c;
        int * pint = (int *) pvoid;
        
        *pint = 1234; // !!!!!!
    }
//     
//     const int stala; 
//     printf("%d\n", stala);
//     
    {
//         struct uchwyt  { };
//         typedef int uchwyt;
//         
//         printf ("%lu\n", sizeof(struct uchwyt));
//         printf ("%lu\n", sizeof(uchwyt));
        
    }
    
    {
        char napis[10] = "Szumia jodly na gor szczycie.";
        printf ("%lu\n", strlen(napis));
        printf ("%s\n",  napis);
    }
    
    return 0; 
} 

// Cur non dicitur veritas? (TGM)
