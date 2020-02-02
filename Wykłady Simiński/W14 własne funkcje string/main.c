/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


 
#include "funkcje.h"
 
int main ()
{

    char * jodly = "Szumia jodly na gor szczycie.";
    printf("%p\n", jodly);
    printf("%s\n", jodly);
    
//     return 0;
    
    char * szumia = "Szumia sobie w dal.";
    char * mlody  = "A mlodemu smutne zycie, bo ma w sercu zal.";
    
    printf("dlugosc napisu \'%s\': %lu\n", jodly, strlen(jodly));
    printf("dlugosc napisu \'%s\': %lu\n", jodly, my_strlen(jodly));

    
    printf("dlugosc napisu \'%s\': %lu\n", szumia, strlen(szumia));
    printf("dlugosc napisu \'%s\': %lu\n", mlody, strlen(mlody));
 
 
    char * dumka_Jontka = malloc (sizeof (char) * (strlen(jodly) + strlen(szumia) + strlen(mlody) + 1));
    
    my_strcpy(dumka_Jontka, jodly);
    printf("(%d) dlugosc napisu \'%s\': %lu\n", __LINE__, dumka_Jontka, strlen(dumka_Jontka));
    
    strcat(dumka_Jontka, szumia);
    printf("(%d) dlugosc napisu \'%s\': %lu\n", __LINE__, dumka_Jontka, strlen(dumka_Jontka));
  
    my_strcat(dumka_Jontka, mlody);
    printf("(%d) dlugosc napisu \'%s\': %lu\n", __LINE__, dumka_Jontka, strlen(dumka_Jontka));
  
    printf("(%d) dlugosc napisu \'%s\': %lu\n", __LINE__, dumka_Jontka, my_strlen(dumka_Jontka));
  
//     return 0;
    
    free(dumka_Jontka);
    dumka_Jontka = 0;
//     return 0;
    
    char * tekst = "Zawszem tobie najwonniejszych kwiatow przyniosl     z pol.";
    char * jontek = (char *) malloc (sizeof (char) * my_strlen(tekst));
    my_strcpy (jontek, tekst);
    printf("%s\n", tekst);
    printf("%s\n", jontek);
    
//     return 0;
    printf("%p\n", tekst);
    printf("%p\n", jontek);
    
    if (jontek == tekst)
        printf("ten sam adres\n");
    else
        printf("rozne adresy\n");
    
//     return 0;
    if (strcmp (jontek, tekst) == 0) // if (!strcmp (jontek, tekst))
        printf("ten sam tekst\n");
    else
        printf("rozne teksty\n");

    if (my_strcmp (jontek, tekst) == 0)
        printf("to samo\n");
    else
        printf("rozne\n");
    
//     return 0;
    char * a = "william";
    char * b = "williama";
    
    printf("porownaj(\"%s\", \"%s\") == %d\n", a, b, my_strcmp(a, b));
    printf("porownaj(\"%s\", \"%s\") == %d\n", b, a, my_strcmp(b, a));
    printf("porownaj(\"%s\", \"%s\") == %d\n", a, a, my_strcmp(a, a));
    printf("porownaj(\"\", \"\") == %d\n", my_strcmp("", ""));
    
    
    printf("strcmp(\"%s\", \"%s\") == %d\n", a, b, strcmp(a, b));
    printf("strcmp(\"%s\", \"%s\") == %d\n", b, a, strcmp(b, a));
    printf("strcmp(\"%s\", \"%s\") == %d\n", a, a, strcmp(a, a));
    printf("porownaj(\"\", \"\") == %d\n", strcmp("", ""));
    
    
    
    
    {
        char * k = strstr (jontek, "sz");
        while (k)
        {
            printf("%d\n", k - jontek);
            k = strstr(k + 1, "sz");
        }
    }
    
    return 0;
    {
        char * k = my_strstr (jontek, "sz");
        while (k)
        {
            printf("%d\n", k - jontek);
            k = strstr(k + 1, "sz");
        }
    }

    printf("%s\n", jontek);
    int przesuniecie = 5;
    cezar(jontek, przesuniecie);
    printf("%s\n", jontek);
    cezar(jontek, -przesuniecie);
    printf("%s\n", jontek);
        
    
    free (jontek);
    jontek = 0;
    

    
    return 0; 
} 

// Cur non dicitur veritas? (TGM)
