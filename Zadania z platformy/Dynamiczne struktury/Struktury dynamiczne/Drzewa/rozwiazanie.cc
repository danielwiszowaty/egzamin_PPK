#ifndef funkcje_hpp
#define funkcje_hpp

#include <stdio.h>
#include <deque>
#include <iostream>

typedef int T;
struct wezel
 {
    T wartosc;
    wezel * pLewy;
    wezel * pPrawy;
};

/** Funkcja dokonuje odbicia lustrzanego drzewa poszukiwać binarnych. Polega to na zmianie uporządkowania drzewa − wartości mniejsze są położone na prawo, a wartości większe na lewo.
    @param pRoot korzeń drzewa */
void odbij ( wezel * pRoot ){
    if(not pRoot)
        return;
    else{
        wezel* temp;
        odbij(pRoot->pLewy);
        odbij(pRoot->pPrawy);
        temp = pRoot->pLewy;
        pRoot->pLewy = pRoot->pPrawy;
        pRoot->pPrawy = temp;
    }
}


/** Funkcja wypisuje na standardowe wyjście wartości drzewa przy przechodzeniu wszerz. Jako kolejkę FIFO wykorzystana jest lista jedno− lub dwukierunkowa .
    @param pRoot korzeń drzewa
 */
void wypiszWszerz ( wezel * pRoot ){
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
}

/** Funkcja wyszukuje nastepnik węzła. Następnikiem węzła jest kolejny węzeł pod względem wartości. Przykład: Jeżeli drzewo przechowuje wartości 1, 6, 9, 15, to następnikiem węzła przechowującego 6 jest węzeł przechowujący 9. Węzeł przechowujący 15 nie ma następnika.
    @param pRoot korzeń drzewa
    @param pPoprzednik wezel , ktorego nastepnik wyszukuje funkcja
    @return adres nastepnika (jeżeli istnieje)
 */
wezel * znajdzNastepnik ( wezel * pRoot , wezel * pPoprzednik );

/** Funkcja usuwa węzeł z drzewa.
    @warning Należy rozpatrzyć cztery przypadki:
(1) Węzeł do usunięcia nie ma potomków.
(2L) Węzeł do usunięcia ma tylko lewy potomek.
(2P) Węzeł do usunięcia ma tylko prawy potomek.
(3) Węzeł do usunięcia ma dwa przypadki. Wtedy należy znaleźć następnik
węzła do usunięcia , przenieść wartość z następnika do węzła do usunięcia i usunąć następnik (który ma co najwyżej jeden potomek).
    @param pRoot korzeń drzewa
    @param pDoUsuniecia wezeł do usunięcia
*/
void usunWezel ( wezel * & pRoot , wezel * pDoUsuniecia );

/** Funkcja dokonuje rotacji w lewo w drzewie poszukiwań binarnych. Po operacji drzewo zachowuje własności drzewa poszukiwań binarnych.
    @param pRoot korzeń drzewa
    @param q wskaźnik na węzeł , względem którego dokonywana jest rotacja
 */
void rotacja_w_lewo (wezel * & pRoot , wezel * q);

/** Funkcja dokonuje rotacji w prawo w drzewie poszukiwań binarnych. Po operacji drzewo zachowuje własności drzewa poszukiwań
 binarnych .
 @param pRoot korzeń drzewa
 @param p wskaźnik na węzeł , względem którego dokonywana jest rotacja
 */
void rotacja_w_prawo (wezel * & pRoot , wezel * p);

#endif /* funkcje_hpp */
