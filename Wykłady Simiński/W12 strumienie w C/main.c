/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład: strumienie w C  

*/


#   include <stdio.h>
#   include <stdlib.h>
#   include <string.h>  
#   include <time.h>

int main ()
{
    printf ("C\n");
    
    int znak; // !!!
/*
    while ((znak = getchar()) != EOF)
        putchar(znak);
*/

    
    // formatowane wyjscie: printf
    
    // int printf (char * format, ...);
    
    int a = 1234;
    char c = 'k';
    char * s = "I ty mu wierzysz, bieda dziewczyno, ze cie nie zwodzi, ty wierzysz mu?";
    double d = -1.234567890;
    int * p = & a; 
    
    printf("%d", a);
    printf("\n");
    printf("%d\n", a);
    printf("%d\t%d\n", a, a);

//     return 0;

    
    printf("%%\n");
    
    printf("%%i %i\n", a);
    printf("%%o %o\n", a);
    printf("%%x %x\n", a);
    
    printf("%%c %c\n", c);
    printf("%%s %s\n", s);
    printf("%%f %f\n", d);
    printf("%%e %e\n", d);
    printf("%%g %g\n", d);
    printf("%%g %g\n", 1000 * d);
    printf("%%g %g\n", 1000000 * d);
    
    printf("%%p %p\n", p);
  
//   return 0;    
    char * student = "Jan Kowalski";
    
    printf("[%s]\n", student);
    printf("[%25s]\n", student);
    printf("[%-25s]\n", student);
    printf("[%5s]\n", student);
    printf("[%.5s]\n", student);
    printf("[%25s]\n", student);
    printf("[%.25s]\n", student);
    printf("[%20.5s]\n", student);
    printf("[%-20.5s]\n", student);
    printf("[%.-5s]\n", student);
   
    printf("[%f]\n", d);
    printf("[%20f]\n", d);
    printf("[%-20f]\n", d);
    printf("[%.10f]\n", d);
    printf("[%20.10f]\n", d);
    printf("[%-20.10f]\n", d);
  
    size_t rozmiar = 123456789;
    printf("[%zu]\n", rozmiar);
    
    printf("[%li]\n", 123456789123456);  // long
    printf("[%hi]\n", 123456789);  // short
    
//     return 0;     
  
    char tekst[100];
    sprintf(tekst, "Jontek (z wyrzutem): \"%s\"\n", s);
    printf("%s\n", tekst);
    
    
    // sformatowane wejscie
 /*  
    int lewa = -10, prawa = 10;
    int ile = scanf ("%d %d", & lewa, & prawa);
    printf ("lewa == %d, prawa == %d (liczba wczytanych danych: %i)\n", lewa, prawa, ile);
    if (ile == EOF)
        printf ("odczytany koniec pliku EOF (%d)\n", EOF);
  */ 
 /*   
    int dzien, rok;
    char nazwa_miesiaca [15];
    
    scanf  ("%d %s %d"  , & dzien, nazwa_miesiaca, & rok); 
//     scanf  ("%d %s %d"  , & dzien, & nazwa_miesiaca, & rok); 
    printf ("%d %s %d\n",   dzien, nazwa_miesiaca,   rok);
  */
   
//     return 0;    
   
   
    // pliki
    
    int K = 5;
    
  
    
    
    srand(time(0));
    
    {
        FILE * plik = fopen ("nazwa.pliku", "w");
        if (plik)
        {
            for (int k = 0; k < K; k++)
            {
                fprintf (plik, "%5d", rand() % 100);
//                 fprintf (stdout, "%5d", rand() % 100);  // stdout jest plikiem :-)
            }
            fprintf(plik, "\n");
            
            fclose(plik);
        }
    }
    
       
     
    
    // wczytanie z pliku:
    {
        FILE * plik = fopen ("nazwa.pliku", "r");
        if (plik)
        {
            int liczba;
            while ( fscanf (plik, "%d", & liczba) == 1)
                printf ("%d\n", liczba);
            
            fclose(plik);
        }
    }
    
//      return 0;
    
    // niesformatowane wejscie
    
    {
        FILE * plik = fopen ("nazwa.pliku", "r");
        if (plik)
        {
            int znak;
            while ( (znak = getc (plik)) != EOF)
                putc (znak, stdout);
              
            
            fclose(plik);
        }
    }
    
//          return 0;
    // zapis blokami:
    {
        char * jontek[4];
        jontek [0] = "Szumia jodly na gor szczycie,";
        jontek [1] = "szumia sobie w dal.";
        jontek [2] = "A mlodemu smutne zycie,";
        jontek [3] = "bo ma w sercu zal.";
        
        
        FILE * plik = fopen ("dumka-jontka", "w");
        if (plik)
        {
            for (int i = 0; i < 4; i++)
            {
                fputs (jontek[i], plik); // nie dopisuje '\n'
                puts (jontek[i]); // dopisuje '\n'
            }  
            
            fclose(plik);
        }
        
    }
    // odczyt blokami
    {
        const int LICZBA_BLOKOW = 10;
        const int DLUGOSC = 20;
        char bloki[LICZBA_BLOKOW][DLUGOSC];
        for (int i = 0; i < LICZBA_BLOKOW; i++)
            bloki[i][0] = '\0';
        
        FILE * plik = fopen ("dumka-jontka", "r");
        if (plik)
        {
            int i = 0;
            while (fgets(bloki[i++], DLUGOSC, plik))
                ;
            
            fclose(plik);
            
            for (int i = 0; i < LICZBA_BLOKOW; i++)
                printf("blok %i: [%s]\n", i, bloki[i]);
            
        }
        
        
    }
   return 0;    
    
    // pliki binarne:
    
    {
        FILE * plik = fopen ("liczby-calkowite", "wb");
        if (plik)
        {
            const int N = 5;
            int liczby [5] = {7, 12, 0, -1, 5};
            
            fwrite (liczby, sizeof(int), 5, plik);
            
            fclose(plik);
        }
    }
      
    {
        FILE * plik = fopen ("liczby-calkowite", "rb");
        if (plik)
        {
            const int N = 5;
            int liczby [5];
            
            fread (liczby, sizeof(int), 5, plik);
            
            fclose(plik);
            
            for (int i = 0; i < N; i++)
                printf("%d ", liczby[i]);
            printf ("\n");
        }
    }
  
      
    return 0;
    
} 

// Cur non dicitur veritas? (TGM)
