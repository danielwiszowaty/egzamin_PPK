#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool palindrom (const char* str){
	int poczatek = 0;
	int len = strlen(str) - 1;
	while(len > poczatek){
		if(str[poczatek++] != str[len--])
			return false;
	}
	return true;
}

bool palindrom2(const char* str){
	int len = strlen(str);
	const char* nowy = str+len-1;
	while(str<nowy){
		if(*str != *nowy)
			return false;
		str++;	
		nowy--;
	}
	return true;
}

void odwroc(char* str){
	int len = strlen(str);
	char* t = str + len -1;
	char c;
	while(str<t){
		c = *str;
		*str = *t;
		*t = c;
		str++;
		t--;
	}
}

size_t zamien(char * str, const char old_char, const char new_char){
	size_t licznik=0;
	while(str++){
		if(*str == old_char)
		{
			++licznik;
			*str = new_char;
		}
	}
	return licznik;
}

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
    while ((*cel ++ = *zrodlo++))
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
    while((*cel++ = *zrodlo++))
        ;
}


int main(){

	printf("%d\n", palindrom2("abba"));
	printf("%d\n", palindrom2("abcba"));
	printf("%zu\n", zamien("abcd", 'c' , 'a'));

	return 0;
}
