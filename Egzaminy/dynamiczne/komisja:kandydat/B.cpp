// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct kandydat
{
	string nazwisko;
	int liczba_glosow;
	kandydat * next;
};

struct komisja
{
	int numer;
	kandydat * kandydaci;
	komisja * next;
};



void dodajdokomisji(komisja *&pHead,const string & nazwisko, int liczba)
{
	auto pHeadA = pHead->kandydaci;
	if (!pHeadA)
	{
		pHead->kandydaci = new kandydat{ nazwisko, liczba, nullptr };
		return;
	}
	else
	{
		if (liczba < pHeadA->liczba_glosow)
		{
			auto temp = pHead->kandydaci;
			pHead->kandydaci = new kandydat{ nazwisko,liczba,temp };
			return;
		}
		while (pHeadA)
		{
			if (pHeadA->next)
			{
				if (liczba >= pHeadA->next->liczba_glosow)
				{
					auto temp = pHeadA;
					pHeadA->next = new kandydat{ nazwisko,liczba,temp };
					return;
				}
			}
			else
			{
				pHeadA->next=new kandydat{ nazwisko,liczba,nullptr };
				return;
			}
			pHeadA = pHeadA->next;
		}
	}
	return;
}

void dodaj(komisja *& pHead,const string & nazwisko, int liczba,int numerkomisji)
{
	kandydat * temp = new kandydat{ nazwisko,liczba,nullptr };
	if (!pHead)
	{
		pHead = new komisja{ numerkomisji,temp,nullptr };
	}
	else
	{
		auto pHeadK = pHead;
		if (numerkomisji > pHead->numer)
		{
			auto tempK = pHead;
			pHead = new komisja{ numerkomisji,temp,tempK };
			return;

		}
		while (pHeadK)
		{
			if (pHeadK->numer==numerkomisji)
			{
				dodajdokomisji(pHeadK, nazwisko, liczba);
				break;
			}
			if (pHeadK->next)
			{
				if (pHeadK->next->numer == numerkomisji)
				{
					dodajdokomisji(pHeadK, nazwisko, liczba);
					break;
				}
				if (pHeadK->next->numer < numerkomisji)
				{
					auto tempK = pHeadK->next;
					pHeadK->next = new komisja{ numerkomisji,temp,tempK };
					return;
				}
				if (pHeadK->next->numer > numerkomisji)
				{
					pHeadK = pHeadK->next;
				}
			}
			else
			{
				pHeadK->next= new komisja{ numerkomisji,temp,nullptr };
				return;
			}
		}
	}
	return;
}

kandydat * znajdzkandydat(komisja *& pHead, const string &nazwisko)
{
	auto ziomek = pHead->kandydaci;
	if (!ziomek)
	{
		return nullptr;
	}
	else
	{
		while (ziomek)
		{
			if (ziomek->next)
			{
				if (ziomek->next->nazwisko == nazwisko)
				{
					return ziomek;
				}
			}
			if (ziomek->nazwisko == nazwisko)
			{
				return ziomek;//jest pierwszy pierwszy
			}
			ziomek = ziomek->next;
		}
	}
	return nullptr;
}

void usun(komisja*& pHead,const string & nazwisko,int numerkomisji)
{
	auto pHeadK = pHead;
	if (!pHeadK)
	{
		return;
	}
	else
	{
		while (pHeadK)
		{
			if (pHeadK->numer == numerkomisji)
			{
				auto ziomek = znajdzkandydat(pHeadK, nazwisko);
				if (ziomek)
				{
					if (ziomek->next == nullptr)//
					{
						delete pHeadK->kandydaci;
						pHeadK->kandydaci = nullptr;
						return;
					}
					else
					{
						auto temp = ziomek;
						if (ziomek->nazwisko == nazwisko)
						{
							temp = ziomek->next;
							delete ziomek;
							pHeadK->kandydaci = temp;
							return;
						}
						if (ziomek->next->next)
						{
							temp = ziomek->next->next;
							delete ziomek->next;
							ziomek->next = temp;
							return;
						}
						else
						{
							delete ziomek->next;
							ziomek->next = nullptr;
							return;
						}
					}
				}
				return;
			}
			pHeadK = pHeadK->next;
		}
	}
	return;
}

void aktualizuj(komisja *& pHead,int numerkomisji,const string & nazwisko, int liczbaplus)
{
	auto pHeadK = pHead;
	if (!pHeadK)
	{
		dodaj(pHead, nazwisko, liczbaplus, numerkomisji);
	}
	else
	{
		while (pHeadK)
		{
			if (pHeadK->numer != numerkomisji)
			{
				pHeadK = pHeadK->next;
				continue;
			}
			auto ziomek = znajdzkandydat(pHeadK, nazwisko);
			if (ziomek)
			{
				if (ziomek->nazwisko == nazwisko)
				{
					ziomek->liczba_glosow = ziomek->liczba_glosow + liczbaplus;
					return;
				}
				if (ziomek->next->nazwisko == nazwisko)
				{
					ziomek->next->liczba_glosow = ziomek->next->liczba_glosow + liczbaplus;
					return;
				}
			}
			if (!ziomek)
			{
				break;
			}
		}
		dodaj(pHead, nazwisko, liczbaplus, numerkomisji);
	}
	return;
}

int main()
{
	komisja * Glowna=nullptr;
	dodaj(Glowna, "AX", 50, 10);
	dodaj(Glowna, "BX", 150, 10);
	dodaj(Glowna, "CX", 10, 10);
	dodaj(Glowna, "DX", 55, 9);
	dodaj(Glowna, "EX", 55, 8);
	dodaj(Glowna, "FX", 54, 15);
	dodaj(Glowna, "GX", 53, 7);
	dodaj(Glowna, "HX", 10, 5);
	dodaj(Glowna, "JX", 100, 6);
	usun(Glowna, "CX", 10);
	aktualizuj(Glowna, 10, "AX", 89);
	aktualizuj(Glowna, 10, "BX", 89);
	aktualizuj(Glowna, 10, "CX", 89);

    return 0;
}

