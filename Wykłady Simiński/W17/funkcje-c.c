/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład  
 
 */

// #include <stdio.h>

#include "funkcje-c.h"


int dekrementuj (int a)
{
//     printf("C: %s\n", __FUNCTION__);
    return --a;
}

int roznica_bezwzgledna (int a, int b)
{
//     printf("C: %s\n", __FUNCTION__);
    return a > b ? a - b : b - a;
}
