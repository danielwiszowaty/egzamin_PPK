/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład :  

*/

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

#ifdef __cplusplus
#  include <iostream>
#  include <iomanip>
#  include <vector>
#else
#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#endif 


 
int main ()
{
#if __cplusplus
    std::cout << "            CCC    +      +   " << std::endl;
    std::cout << "           C       +      +   " << std::endl;
    std::cout << "           C     +++++  +++++ " << std::endl;
    std::cout << "           C       +      +   " << std::endl;
    std::cout << "            CCC    +      +   " << std::endl;
#else
    printf      ("            CCC               \n");
    printf      ("           C                  \n");
    printf      ("           C                  \n");
    printf      ("           C                  \n");
    printf      ("            CCC               \n");
#endif    
    
//     return 0;
      
#if __cplusplus

    // alokacja zmiennej 
    int * pint = new int;
    *pint = 4;
    std::cout << " pint: " <<  pint << std::endl;
    std::cout << "*pint: " << *pint << std::endl;
    
    
    delete pint;
    pint = nullptr;
    
    // alokacja tablicy jednowymiarowej:
    int rozmiar = 12; // zmienna;
    int * tab = new int [rozmiar];
    
    // wypelnienie tablicy 
    for (int i = 0; i < rozmiar; i++)
        tab[i] = i * i;
    
    // wypisanie tablicy:
    for (int i = 0; i < rozmiar; i++)
        std::cout << *(tab + i) << std::endl;
    
    // usuniecie tablicy:
    delete [] tab;
    tab = nullptr;
    
    
    
    // alokacja tablicy dwuwymiarowej
    
    int nWierszy = 6;
    int nKolumn  = 12;
    
    // alokacja tablicy 
    // tab2d 
    
    int ** tab2d = new int * [nWierszy];
    for (int i = 0; i < nWierszy; i++)
        tab2d[i] = new int [i + 1];
    
    
    // wypelnienie tablicy 
    for (int w = 0; w < nWierszy; w++)
    {
        for (int k = 0; k < w + 1; k++)
            tab2d[w][k] = 20 * w + k;
    }

    
    int szer = 4;
    for (int w = 0; w < nWierszy; w++)
    {
        for (int k = 0; k < w + 1; k++)
            std::cout << std::setw(szer) << tab2d[w][k];
        std::cout << std::endl;
    }
    std::cout << std::setw(0);

    
    
    // usuniecie tablicy     
    for (int w = 0; w < nWierszy; w++)
        delete [] tab2d[w];
    delete [] tab2d;
    
    
    // tablica dwywymiarowa z wykorzystaniem wektorow
    
    std::vector<std::vector<int>> wek2d(nWierszy/*, std::vector<int> (nKolumn)*/);
    for (int w = 0; w < nWierszy; w++)
        wek2d[w] = std::vector<int> (nKolumn);
    
    for (int w = 0; w < nWierszy; w++)
    {
        for (int k = 0; k < nKolumn; k++)
            wek2d[w][k] = 20 * w + k;
    }

    for (int w = 0; w < nWierszy; w++)
    {
        for (int k = 0; k < nKolumn; k++)
            std::cout << std::setw(szer) << wek2d[w][k];
        std::cout << std::endl;
    }
    std::cout << std::setw(0); 
    
    for (auto & wiersz : wek2d)
    {
        for (auto wartosc : wiersz)
            std::cout << std::setw(szer) << wartosc;
        std::cout << std::endl;
    }
    std::cout << std::setw(0); 
    
#else
    
    // alokacja zmiennej 
    int * pint = malloc (sizeof(int));
    printf("*pint: %d\n", *pint);
   
    *pint = 4;
    printf(" pint: %p\n",  pint);
    printf("*pint: %d\n", *pint);
    
    
    free(pint);
    pint = 0;
    
   
    // alokacja tablicy jednowymiarowej:
    int rozmiar = 12; // zmienna;
    int * tab = calloc (rozmiar, sizeof(int));
//     int * tab = malloc (rozmiar * sizeof (int));
    
    for (int i = 0; i < rozmiar; i++)
        tab[i] = i * i;
    
    for (int i = 0; i < rozmiar; i++)
        printf("%d\n", *(tab + i));
    
    free(tab);
     
    // alokacja tablicy dwuwymiarowej
    
    int nWierszy = 6;
    int nKolumn  = 12;
    
    
    // tab2d 
    int ** tab2d = calloc (nWierszy, sizeof (int *));
    for (int w = 0; w < nWierszy; w++)
    {
        tab2d[w] = calloc (nKolumn, sizeof (int));
    }
    
    for (int w = 0; w < nWierszy; w++)
    {
        for (int k = 0; k < nKolumn; k++)
            tab2d[w][k] = 20 * w + k;
    }

    for (int w = 0; w < nWierszy; w++)
    {
        for (int k = 0; k < nKolumn; k++)
            printf("%4d", tab2d[w][k]);
        printf("\n");
    }
    
    // zwolnienie pamieci
    for (int w = 0; w < nWierszy; w++)
        free(tab2d[w]);
    free(tab2d);
    
    
    // realloc 
    
    int * pt = calloc (5, sizeof(int));
    for (int i = 0; i < 5; i++)
        pt[i] = i+1;
    
    for (int i = 0; i < 5; i++)
        printf("%4d", pt[i]);
    printf("\n");
    
    int * pu = realloc (pt, 10 * sizeof(int));
    
    for (int i = 0; i < 10; i++)
        printf("%4d", pu[i]);
    printf("\n");
    
    printf("pt == %p\npu == %p\n", pt, pu);
    
    //free(pu);
    
//     wskaznik = realloc (0, 123); // malloc
//     wskaznik = realloc (adres, 0); // jak free do 98 roku (zwraca wskaznik zerowy), a potem zwalnia pamiec, ale nie musi zwracac zerowego wskaznika (jezeli jest niezerowy, to nie nalezy go uzywac)
    
    pu = realloc (pu, 0); // u mnie dziala jak free :-)
    if (pu == 0)
        printf ("wzraca zerowy wskaznik: %p\n", pu);
    

    
#endif     
    
    return 0; 
} 

// Cur non dicitur veritas? (TGM)
