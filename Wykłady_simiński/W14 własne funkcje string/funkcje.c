/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład  
 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "funkcje.h"

int my_strcmp (const char * s, const char * t)
{
    while (*s && (*s == *t)) 
    {
        s++;
        t++;
    }
    
    return (int) *s - (int) *t;
}

void my_strcat (char * cel, const char * zrodlo)
{
    // znalezc zero w string docelowym
    while (*cel)
        cel++;
    // skopiuj ze zrodla do celu
    while (*cel ++ = *zrodlo++)
        ;
}

size_t my_strlen (const char * pNapis)
{
    size_t licznik = 0;
    
    while (*pNapis++)
        licznik++;
    return licznik;
}

void my_strcpy (char * cel, const char * zrodlo)
{
    while(*cel++ = *zrodlo++)
        ;
}
