
// Pracownik.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
struct Zadanie
{
	int priorytet;
	string tresc_zadania;
	Zadanie * pLewy;
	Zadanie * pPrawy;

};
struct Pracownik
{
	string nazwisko;
	Pracownik * pPrev;
	Pracownik * pNext;
	Zadanie * zadanie;
};
Pracownik * Dodaj(Pracownik * & pHead, Pracownik * & pTail, const string & nazwisko)
{
	if (!pHead)
	{
		pHead = new Pracownik{ nazwisko, nullptr, nullptr, nullptr };
		pTail = pHead;
		return pTail;
	}
	else if (pHead->nazwisko > nazwisko)
	{
		auto temp = new Pracownik{ nazwisko, nullptr, pHead, nullptr };
		pHead->pPrev = temp;
		pHead = temp;
		return pHead;
	}
	else
	{
		auto pomoc = pHead;
		
			while (pomoc && pomoc->nazwisko < nazwisko)
			{
				pomoc = pomoc->pNext;
			}
			if (!pomoc) //dodawanie na koniec
			{
				pomoc = new Pracownik{ nazwisko, pTail, nullptr, nullptr };
				pTail->pNext = pomoc;
				pTail = pomoc;
				return pTail;
			}
			else  //dodawanie w srodku 
			{
				auto toAdd = new Pracownik{ nazwisko, pomoc->pPrev, pomoc};
				pomoc->pNext = toAdd;
				pomoc->pNext->pPrev = toAdd;
				return toAdd;
			}
	}
}
Pracownik * ZnajdzLubDodajPracownika(Pracownik * & pHead, Pracownik  *& pTail, const string & nazwisko)
{
	bool nie_ma = true;
	if (!pHead)
	{
		return Dodaj(pHead, pTail, nazwisko);
	}
	if (pHead->nazwisko == nazwisko)
	{
		return pHead;
	}
	if (pTail->nazwisko == nazwisko)
	{
		return pTail;
	}
	else
	{
		auto pomoc = pHead;
		while (pomoc && nie_ma)
		{
			if (pomoc->nazwisko == nazwisko)
			{
				nie_ma = false; 
				return pomoc;
			}
			else
			{
				pomoc = pomoc->pNext;
			}
		}
		if (!nie_ma)
		{
			return Dodaj(pHead, pTail, nazwisko);
		}
	}
}
void DodajZadanie(Zadanie * & pRoot, int priorytet, string nazwa)
{
	if (pRoot)
	{
		pRoot = new Zadanie{ priorytet, nazwa, nullptr, nullptr };
	}
	else
	{
		if (priorytet < pRoot->priorytet)
		{
			DodajZadanie(pRoot->pLewy, priorytet, nazwa);
		}
		else
		{
			DodajZadanie(pRoot->pPrawy, priorytet, nazwa);
		}
	}
}
void DodajPracownikowiZadanie(Pracownik * & pHead, Pracownik * & pTail, string nazwisko, int priorytet, string nazwa)
{
	Pracownik * w = ZnajdzLubDodajPracownika(pHead, pTail, nazwisko);
	DodajZadanie(w->zadanie, priorytet, nazwa);
}
void UsunElement(Pracownik * & pHead, Pracownik * & pTail, Pracownik * p)
{
	if (pHead)
	{
		if (pHead == p)
		{
			pHead = pHead->pNext;
		}
		if (pTail == p)
		{
			pTail = pTail->pPrev;
		}
		else
		{
			p->pPrev->pNext =p-> pNext;
			p->pNext->pPrev = p->pPrev;
		}
		delete p;
	}
}
void UsunPracownikaBezZadan(Pracownik * & pHead, Pracownik  *& pTail)
{
	auto pomoc = pHead;
	while (pomoc)
	{
		if (pomoc->zadanie == nullptr)
		{
			UsunElement(pHead, pTail, pomoc);
		}
		else
		{
			pomoc = pomoc->pNext;
		}
	}
}
int main()
{
    return 0;
}

