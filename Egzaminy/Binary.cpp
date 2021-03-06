// Binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <random>

using namespace std;



int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 256);
	fstream plik("plik.bin", ios::in | ios::out | ios::binary);
	if (plik.is_open())
	{
		long ileznakow;//odczyt zawartosci
		plik.seekg(0, plik.end);
		ileznakow = plik.tellg();
		plik.seekg(0);
		char *bufor = new char[ileznakow];
		int *intbufor = new int[ileznakow];
		plik.read(bufor, ileznakow);
		for (int i = 0; i < ileznakow; i++)
		{
			intbufor[i]=(int)bufor[i];
			cout << intbufor[i]<<endl;
		}
		delete bufor;
		bufor = nullptr;
	}
	else
	{
		plik.open("plik.bin", ios::in | ios::out | ios::binary | ios::trunc);
		const int constant = 100;//zapis losowych
		char*tab = new char[constant];
		for (int i = 0; i < constant; i++)
		{
			tab[i] = dist(gen);
		}
		plik.write(tab, constant);
		delete tab;
		tab = nullptr;
			}
	plik.close();


    return 0;
}

