// C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct towar
{
	string nazwa;
	double cena;
	towar * next;
	towar* prev;
};

struct klient
{
	string nazwisko;
	towar * pZakupy;
	klient * lewy;
	klient * prawy;
};

klient * znajdz(klient*&pHead, const string & nazwisko)
{
	auto pHeadK = pHead;
	while(pHeadK)
	{
		if (pHeadK->nazwisko == nazwisko)
		{
			return pHeadK;
		}
		if (nazwisko > pHeadK->nazwisko)
		{
			if (pHeadK->prawy)
			{
				pHeadK = pHeadK->prawy;
				continue;
			}
			else
			{
				return pHeadK;
			}
		}
		if (nazwisko < pHeadK->nazwisko)
		{
			if (pHeadK->lewy)
			{
				pHeadK = pHeadK->lewy;
				continue;
			}
			else
			{
				return pHeadK;
			}
		}
	}
	return pHeadK;
}

void dodajzakupy(klient *& pklient, const string & zakupy,double cena)
{
	auto pHeadT = pklient->pZakupy;
	if (!pklient->pZakupy)// 0 zakupow
	{
		 pklient->pZakupy = new towar { zakupy,cena,nullptr,nullptr };
		 return;
	}
	else // ma juz zakupy
	{
		if (cena <= pklient->pZakupy->cena) // nowa najmniejsza cena
		{
			auto temp = pklient->pZakupy;
			if (pklient->pZakupy->next)
			{
				temp = pklient->pZakupy->next;
				pklient->pZakupy = new towar{ zakupy,cena,temp,nullptr };
				temp->prev = pklient->pZakupy;
				return;
			}
			else
			{
				temp = pklient->pZakupy;
				pklient->pZakupy = new towar{ zakupy,cena,temp,nullptr };
				temp->prev = pklient->pZakupy;
				return;
			}
		}
		else //gdzies
		{
			while (pHeadT)
			{
				if (cena <= pHeadT->cena)
				{
					auto tempprev = pHeadT->prev;
					pHeadT->prev = new towar{ zakupy,cena,pHeadT,tempprev };
					if (tempprev)
					{
						tempprev->next = pHeadT->prev;
					}
					return;
				}
				if (!pHeadT->next)
				{
					break;
				}
				pHeadT->next;
			}
			pHeadT->next = new towar{ zakupy,cena,nullptr,pHeadT };
		}
	}
	return;
}

void dodaj(klient *& pHead, const string & nazwisko,const string & nazwa,double cena)
{
	towar * zakupy = new towar { nazwa,cena,nullptr,nullptr };
	if (!pHead)
	{
		pHead = new klient{ nazwisko,zakupy,nullptr,nullptr };
	}
	else
	{
		auto komu = znajdz(pHead, nazwisko);
		if (komu->nazwisko==nazwisko)
		{
			dodajzakupy(komu, nazwa, cena);
			return;
		}
		if (nazwisko>komu->nazwisko)
		{
			komu->prawy = new klient{ nazwisko,zakupy,nullptr,nullptr };
		}
		if (nazwisko<komu->nazwisko)
		{
			komu->lewy = new klient{ nazwisko,zakupy,nullptr,nullptr };
		}
	}
}

int main()
{
	klient * Glowny = nullptr;
	dodaj(Glowny, "AX", "chlep", 10);
	dodaj(Glowny, "BX", "chlep", 9);
	dodaj(Glowny, "CX", "chlep", 110);
	dodaj(Glowny, "DX", "chlep", 17);
	dodaj(Glowny, "EX", "chlep", 15);
	dodaj(Glowny, "GX", "chlep", 11);
	dodaj(Glowny, "GX", "chlep", 11);
	dodaj(Glowny, "AX", "chlep", 11);
	dodaj(Glowny, "AX", "chlep", 9);

    return 0;
}

