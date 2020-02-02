#include <iostream>

#include "funkcje.hpp"

void wypiszListe (element * pHead, element * pTail)
{
    while(pHead)
    {
        std::cout << pHead->wartosc << " ";
        pHead = pHead->pNext;
    }
    std::cout << std::endl;
}

void dodajNaPoczatek (element * & pHead, element * & pTail, const T & wartosc )
{
    pHead = new element {wartosc, nullptr, pHead};
    //jesli nowy ma nastepnika, ustaw wskaznik z tego elementu na nowy
    if(pHead->pNext)
        pHead->pNext->pPrev = pHead;
    //w innym przypadku nowy jest tez ogonem
    else
        pTail = pHead;
}

void dodajNaKoniec (element * & pHead, element * & pTail, const T & wartosc )
{
    pTail = new element {wartosc, pTail, nullptr};
    //jesli nowy ma nastepnika (poprzednika), ustaw wskaznik z tego poprzednika na nowy
    if(pTail->pPrev)
        pTail->pPrev->pNext = pTail;
    //w innym przypadku nowy jest tez glowa
    else
        pHead = pTail;
}

void posortujListe (element * & pHead, element * & pTail)
{
    for(element * tmp = pHead; tmp->pNext != nullptr; tmp = tmp->pNext)
        for(element * tmp2 = tmp->pNext; tmp2 != nullptr; tmp2 = tmp2->pNext)
            if(tmp->wartosc >= tmp2->wartosc)
                std::swap (tmp->wartosc, tmp2->wartosc);
}

void dodajDoListyPosortowanej ( element * & pHead, element * & pTail, const T & wartosc)
{
    element * current = pHead;
    
    if (pHead == nullptr){
        pHead = new element {wartosc, nullptr, pHead};
        pTail = pHead;
    }
    
    // nowy wskaźnik będzie dodany na początek listy
    else if (pHead->wartosc >= wartosc){
        dodajNaPoczatek(pHead, pTail, wartosc);
    }
    
    else {
        //szukamy miejsca do umieszczenia elementu
        while (current->pNext != nullptr && current->pNext->wartosc < wartosc)
            current = current->pNext;
        
        //element należy dodać na koniec- korzystamy z uprzednio zdefiniowanej funkcji
        if (current->pNext == nullptr){
            dodajNaKoniec(current, pTail, wartosc);
        }
        else{
            //poprzednikiem nowego elementu jest current, a następnikiem to, na co wskazywał current
            element * newElem = new element {wartosc, current, current->pNext};
            //poprzedni teraz wskazuje na nowy
            current->pNext = newElem;
            //następnik nowego wskazuje pPrevem na nowy (już nie na current)
            newElem->pNext->pPrev = newElem;
        }
    }
}

void przesunListe (element * & pHead, element * & pTail) {
    
    element * current = pHead;
    
    if (current == nullptr)
        return;
    
    element * first = current;
    //current staje sie ostatnim elementem listy i bedzie pierwszym elementem nowej listy
    while (current->pNext != nullptr){
        current = current->pNext;
    }
    
    //pierwszy staje sie drugim i oddaje głowę
    current->pNext = first;
    pHead->pPrev = current;
    
    //current jest nową głową
    pHead = current->pPrev->pNext;
    //usuwamy wskaźnik z przedostatniego elementu na current i tworzymy ogon równy nullptr
    current->pPrev->pNext = nullptr;
    pHead->pPrev = nullptr;
    
}

void odwrocListe (element * & pHead, element * & pTail)
{
    for(element * tmp = pHead; tmp->pNext != nullptr; tmp = tmp->pNext)
    {
        for(element * tmp2 = tmp->pNext; tmp2 != nullptr; tmp2 = tmp2->pNext){
            std::swap (tmp->wartosc, tmp2->wartosc);
        }
    }
}

element * znajdz ( element * pHead, const T & wartosc )
{
    element * tmp = pHead;
    while(tmp)
    {
        if(tmp->wartosc == wartosc)
            return tmp;
        else
            tmp = tmp->pNext;
    }
    return nullptr;
}

element * przenies ( element * & pHeadWej, element * pTailWej, const T & wartosc, element * & pHeadWyj, element * & pTailWyj)
{
    while(znajdz(pHeadWej, wartosc)!=nullptr){
        element * wyszukany = znajdz(pHeadWej, wartosc);
        dodajNaPoczatek(pHeadWyj, pTailWyj, wartosc);
        //element do usunięcia jest głową
        if(znajdz(pHeadWej, wartosc)==pHeadWej)
            pHeadWej = znajdz(pHeadWej, wartosc)->pNext;
        //element do usunięcia ma następnika
        if(znajdz(pHeadWej, wartosc)->pNext!=nullptr)
            znajdz(pHeadWej, wartosc)->pNext->pPrev=znajdz(pHeadWej, wartosc)->pPrev;
        //element do usunięcia ma poprzednika
        if(znajdz(pHeadWej, wartosc)->pPrev!=nullptr)
            znajdz(pHeadWej, wartosc)->pPrev->pNext=znajdz(pHeadWej, wartosc)->pNext;
        delete wyszukany;
    }
    return nullptr;
}

void usunElementy (element * & pHead, element * & pTail , const T & wartosc )
{
    if (pHead == NULL)
        return;
    
    element *tmp = pHead;
    while(tmp)
    {
        if(tmp->wartosc == wartosc) {
            if(tmp == pHead)
                pHead = tmp->pNext;
            if(tmp == pTail)
                pTail = tmp->pPrev;
            if(tmp->pNext!=nullptr)
                tmp->pNext->pPrev=tmp->pPrev;
            if(tmp->pPrev!=nullptr)
                tmp->pPrev->pNext=tmp->pNext;
            element * nast = tmp->pNext;
            delete tmp;
            tmp = nast;

        }
        else
            tmp = tmp->pNext;
    }
}

void usunListe (element * & pHead, element * & pTail)
{
    while(pHead)
    {
        element * pNastepnik = pHead->pNext;
        delete pHead;
        pHead = pNastepnik;
    }
//    while(pTail)
//    {
//        element * pPoprzednik = pTail->pPrev;
//        delete pTail;
//        pTail = pPoprzednik;
//    }
}
