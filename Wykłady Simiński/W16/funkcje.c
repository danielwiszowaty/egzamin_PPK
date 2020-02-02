/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład  
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl
#ifdef __cplusplus
#include <iostream>
#endif 
#include "struktury.h"

void print (const 
#ifdef __cplusplus
#else 
                   struct  
#endif 
                          przyklad 
#ifdef __cplusplus
                                  &  
#endif
                                      ex)
{
#ifdef __cplusplus
    std::cout << "(" << ex.a << ", " << ex.c << ") : " << ex.x << std::endl;
#else
    printf("(%d, %c): $f\n", ex.a, ex.c, ex.x);
#endif
}
