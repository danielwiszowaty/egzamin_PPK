/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 10 + 11: drzewo poszukiwań binarnych
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl


#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>
#include <deque>

#include "struktury.h"
#include "funkcje.h"

void wypiszDrzewoWszerz (wezel * pRoot)
{
    if (pRoot)
    {
        std::deque<wezel *> potomki;
        potomki.push_front(pRoot);
    
        while (not potomki.empty())
        {
            // wyjmij z kolejki adres wezla
            
            auto p = potomki.back(); // odczytanie wartosci 
            potomki.pop_back(); // usuniecie z konca
//             auto p = potomki.front(); // odczytanie wartosci 
//             potomki.pop_front(); // usuniecie z konca
            
            // wypisz wartosc schowana w wezle
            
            std::cout << p->wartosc << ' ';
            // zapisz do kolejki adresy potomkow:
            
            if (p->pLewy)
               potomki.push_front(p->pLewy);
            if (p->pPrawy)
               potomki.push_front(p->pPrawy);
        }
    }
    
    
}

wezel * znajdzRodzic (wezel * pRoot, wezel * pPotomek)
{
    if (not pRoot or not pPotomek)
        return nullptr;
    if (pRoot == pPotomek)
        return nullptr;
    
    if (pPotomek->wartosc < pRoot->wartosc)
    {
        if (pPotomek == pRoot->pLewy)
            return pRoot;
        else
            return znajdzRodzic(pRoot->pLewy, pPotomek);
    }
    else
    {
        if (pPotomek == pRoot->pPrawy)
            return pRoot;
        else
            return znajdzRodzic(pRoot->pPrawy, pPotomek);
    }    
    
    
}

wezel * minimalny (wezel * pRoot)
{
    while (pRoot and pRoot->pLewy)
        pRoot = pRoot->pLewy;
    return pRoot;
}

int wysokoscDrzewa(wezel* pRoot)
{
    return pRoot ? 1 + std::max(wysokoscDrzewa(pRoot->pLewy), wysokoscDrzewa(pRoot->pPrawy)) : 0;
}


void usunLiscie(wezel *& pRoot)
{
    if (pRoot)
    {
        if (not pRoot->pLewy and not pRoot->pPrawy)
        {
            // pRoot wskazuje na lisc
            delete pRoot;
            pRoot = 0;
        }
        else
        {
            usunLiscie(pRoot->pLewy);
            usunLiscie(pRoot->pPrawy);
        }
    }
}


int policzLiscie(wezel* pRoot)
{
    if (pRoot)
    {
        if (not pRoot->pLewy and not pRoot->pPrawy)
            return 1; // wezel nie ma potomkow, jest zatem lisciem
        else
            return policzLiscie(pRoot->pLewy) + policzLiscie(pRoot->pPrawy);
    }
    else
        return 0;
}


typ zsumujWartosci(wezel* pRoot)
{
    if (pRoot)
        return pRoot->wartosc + zsumujWartosci(pRoot->pLewy) + zsumujWartosci(pRoot->pPrawy);
    else
        return  typ { } ; // domyslna wartosc dla typu
}


int policzWezly(wezel* pRoot)
{
    if (pRoot)
        return 1 + policzWezly(pRoot->pLewy) + policzWezly(pRoot->pPrawy);
    return 0;
}


wezel *
znajdzIteracyjnie (wezel * pRoot, const typ & wartosc)
{
    while (pRoot)
    {
        if (pRoot->wartosc == wartosc)
            return pRoot;
        if (wartosc < pRoot->wartosc)
            pRoot = pRoot->pLewy;
        else
            pRoot = pRoot->pPrawy;
    }
    return nullptr;
}

wezel * znajdzRekurencyjnie (wezel * pRoot, const typ & wartosc)
{
    if (pRoot)
    {
        if (pRoot->wartosc == wartosc)
            return pRoot;
        
        if (wartosc < pRoot->wartosc)
            return znajdzRekurencyjnie(pRoot->pLewy, wartosc);
        else
            return znajdzRekurencyjnie(pRoot->pPrawy, wartosc);
    }
    else
        return nullptr;
}

void dodajDoDrzewaIteracyjnie2(wezel *& pRoot, typ& wartosc)
{
    if (not pRoot)
        pRoot = new wezel { wartosc, nullptr, nullptr };
    else 
    {
        auto p = pRoot;
        while (true)
        {
            
            if (wartosc < p->wartosc)
            {
                if (p->pLewy)
                    p = p->pLewy;
                else
                {
                    p->pLewy = new wezel { wartosc, 0, 0 };
                    return;
                }
            }
            else
            {
                if (p->pPrawy)
                    p = p->pPrawy;
                else
                {
                    p->pPrawy = new wezel { wartosc, 0, 0 };
                    return;
                }
            }
        }
    }
}

void dodajDoDrzewaIteracyjnie(wezel *& pRoot, typ& wartosc)
{
    if (not pRoot)
        pRoot = new wezel { wartosc, nullptr, nullptr };
    else 
    {
        auto p = pRoot;
        while (
                ( wartosc < p->wartosc /* mamy isc w lewo */ and p->pLewy /* sciezka w lewo istnieje */  )
                 or 
                ( wartosc >= p->wartosc /* mamy isc w prawo */ and p->pPrawy /* sciezka w prawo istnieje */   )
              )
        {
            // przesuniecie na nastepny wezel
            if (wartosc < p->wartosc)
                p = p->pLewy;
            else
                p = p->pPrawy;
        }
        
        // p wskazuje na poprzednik elementu do wstawienia
        if (wartosc < p->wartosc)
            p->pLewy = new wezel { wartosc, 0, 0 };
        else
            p->pPrawy = new wezel { wartosc, 0, 0};
        
    }
        
}


void usunDrzewo(wezel *& pRoot)
{
    if (pRoot)
    {
        usunDrzewo(pRoot->pLewy);
        usunDrzewo(pRoot->pPrawy);
        delete pRoot;
        pRoot = nullptr;
    }
}


void wypisz(wezel* pRoot, int wciecie)
{
    if (pRoot) // jezeli jest co wypisac
    {
        wypisz(pRoot->pLewy, wciecie + 1);
        std::cout << std::setw(wciecie * 4) << pRoot->wartosc << std::endl << std::setw(0);
        wypisz(pRoot->pPrawy, wciecie + 1);
    }
}


void wypisz(wezel* pRoot)
{
    if (pRoot) // jezeli jest co wypisac
    {
        wypisz(pRoot->pLewy);
        std::cout << pRoot->wartosc << std::endl;
        wypisz(pRoot->pPrawy);
    }
}


void dodajDoDrzewaRekurencyjnie(wezel *& pRoot, const typ& wartosc)
{
    if (not pRoot)  // drzewo puste
        pRoot = new wezel {wartosc, nullptr, nullptr};
    else
    {
        if (wartosc < pRoot->wartosc) // idziemy w lewo
            dodajDoDrzewaRekurencyjnie(pRoot->pLewy, wartosc);
        else 
            dodajDoDrzewaRekurencyjnie(pRoot->pPrawy, wartosc);
    }
}


void usunRekurencyjnie(element *& pHead, element *& pTail)
{
    if (pHead)
    {
        usunRekurencyjnie(pHead->pNext, pTail);
        delete pHead;
        pHead = pTail = nullptr;
    }
}


void wypiszOdKonca(element* pTail)
{
    if (pTail)
    {
        std::cout << pTail->wartosc << ' ';
        wypiszOdKonca(pTail->pPrev);
    }
}


void wypiszOdPoczatku(element* pHead)
{
    while (pHead)
    {
        std::cout << pHead->wartosc << ' ';
        pHead = pHead->pNext;
    }
}


void dodajNaPoczatek(element *& pHead, element *& pTail, const typ& wartosc)
{
    if (not pHead) // lista pusta
       pHead = pTail = new element { wartosc, nullptr, nullptr };
    else
    {
        auto pNowy = new element { wartosc, nullptr, pHead };
        pNowy->pNext->pPrev = pNowy;
        pHead = pNowy;
    }        
}

 
 
