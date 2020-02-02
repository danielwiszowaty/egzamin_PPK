#include <iostream>

using namespace std;

/* Proszę napisać fragment kodu, który sortuje
tablicę o rozmiarze const int N znanym w czasie kompilacji. */
void SortujTablice(int tablica[], const int N){
	int temp;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(tablica[j]>tablica[i]){
				temp=tablica[i];
				tablica[i]=tablica[j];
				tablica[j]=temp;
			}
		}
	}
}

/* . Proszę napisać fragment kodu, który scala
dwie tablice posortowanych liczb zmiennoprzecinkowych o rozmiarach const int M
i const int N w jedną tablicę posortowaną
o rozmiarze M + N (wszystkie stałe znane
w czasie kompilacji). Nie można używać tutaj
algorytmu sortowania. */

int* PolaczTablice(int* t1, const int N, int* t2, const int M){
	int* tablica = new int[N + M];

	int i=0, j=0, k=0;

	while(i < N and j < M)
		tablica[k++] = t1[i] < t2[j] ? t1[i++] : t2[j++];
	while(i < N)
		tablica[k++] = t1[i++];
	while(j < M)
		tablica[k++] = t2[j++];

	return tablica;
}



int main(){

const int rozmiar = 5;
const int rozmiar2 = 4;
int tablica[]= {24,14,7,15,4};
int tablica2[]= {64,13,21,17};
SortujTablice(tablica,rozmiar);
SortujTablice(tablica2,rozmiar2);
int* tablica3 = PolaczTablice(tablica,rozmiar,tablica2,rozmiar2);

for(int i=0; i<rozmiar+rozmiar2; i++)
	cout<<tablica3[i]<<" ";

if(tablica3)
	delete[] tablica3;


	return 0;
}