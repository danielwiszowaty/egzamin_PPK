/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 8: lista jednokierunkowa 
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl


#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>

#include "funkcje.h"
#include "memory/nvwa/debug_new.h"

element * znajdzPoprzednikIteracyjnie(element* pHead, element* pNastepnik)
{
    if (not pHead or pNastepnik == pHead)
        return nullptr;
    
    auto p = pHead;
    while (p and p->pNext != pNastepnik)
        p = p->pNext;
    
    return p;
}


element * znajdzElementRekurencyjnie(element* pHead, typ liczba)
{
    if (pHead)
    {
        if (pHead->wartosc == liczba)
            return pHead;
        else
            return /*!!*/ znajdzElementRekurencyjnie(pHead->pNext, liczba);
    }
    else // lista pusta
        return nullptr;
}


void usunListeOdKoncaRekurencyjnie(element *& pHead)
{
    if (pHead)
    {
        usunListeOdKoncaRekurencyjnie(pHead->pNext);
        delete pHead;
        pHead = nullptr;
    }
}


void usunListeOdPoczatkuRekurencyjnie(element *& pHead)
{
    if (pHead)
    {
        auto p = pHead->pNext;
        delete pHead;
        pHead = nullptr;
        usunListeOdPoczatkuRekurencyjnie(p);
    }    
}


void dodajNaKoniecRekurencyjnie(element *& pHead, typ liczba)
{
    if (not pHead) // lista pusta
        pHead = new element { liczba, nullptr };
    else
        dodajNaKoniecRekurencyjnie(pHead->pNext, liczba);
}


void dodajNaKoniecIteracyjnie(element *& pHead, typ liczba)
{
    if (not pHead) // lista pusta
        pHead = new element { liczba, nullptr };
    else 
    {
        auto p = pHead; 
        while (p->pNext)
           p = p->pNext;

        // p wskazuje ostatni element listy
        p->pNext = new element { liczba, nullptr};        
    }
}


void usunListeIteracyjnie(element *& pHead)
{
    while (pHead)
    {
        auto p = pHead->pNext;
        delete pHead;
        pHead = p;
    }   
}

void wypiszOdPoczatkuRekurencyjnie(element* pHead, std::ostream& ss)
{
    if (pHead)
    {
        ss << pHead->wartosc << ' ';
        wypiszOdPoczatkuRekurencyjnie(pHead->pNext, ss);
    }
}

void wypiszOdKoncaRekurencyjnie(element* pHead, std::ostream& ss)
{
    if (pHead)
    {
        wypiszOdKoncaRekurencyjnie(pHead->pNext, ss);
        ss << pHead->wartosc << ' ';
    }    
}


void wypiszOdPoczatkuIteracyjnie(element* pHead)
{
// wersja 1
    //     auto p = pHead;
//     
//     while ( p != nullptr )
//     {
//         std::cout << p->wartosc << ' ';
//         p = p->pNext;
//     }

    // wersja 2
    
    while (pHead)
    {
        std::cout << pHead->wartosc << ' ';
        pHead = pHead->pNext;
    }

}


void dodajNaPoczatek(element * & pHead, typ liczba)
{
    // wersja oryginalna
//     if (pHead == nullptr) // lista pusta
//     {
//         element * pNowy = new element;
//         (*pNowy).wartosc = liczba;
//         pNowy->pNext = nullptr;
//         pHead = pNowy;
//     }
//     else // lista niepusta
//     {
//         element * pNowy = new element;
//         (*pNowy).wartosc = liczba;
//         pNowy->pNext = pHead;
//         pHead = pNowy;
//     }

    // ufikuśnianie, wersja 2:
    
//     if (pHead == nullptr) // lista pusta
//     {
//         element * pNowy = new element;
//         (*pNowy).wartosc = liczba;
//         pNowy->pNext = pHead;
//         pHead = pNowy;
//     }
//     else // lista niepusta
//     {
//         element * pNowy = new element;
//         (*pNowy).wartosc = liczba;
//         pNowy->pNext = pHead;
//         pHead = pNowy;
//     }
    
    
    //     
    // ufikuśnianie, wersja 3:
    
//     element * pNowy = new element;
//     (*pNowy).wartosc = liczba;
//     pNowy->pNext = pHead;
//     pHead = pNowy;
    
    // ufikuśnianie, wersja 4:
    
//     element * pNowy = new element { liczba, pHead };
//     pHead = pNowy;

    // ufikuśnianie, wersja 5:

    pHead = new element { liczba, pHead };
}


int * polacz(const int* t1, const int r1, const int* t2, const int r2)
{
    int * ptab = new int [r1 + r2];
    
    for (int i = 0; i < r1; i++)
        ptab[i] = t1[i];
    
    for (int i = 0; i < r2; i++)
        ptab[r1 + i] = t2[i];
    
    return ptab;
}
