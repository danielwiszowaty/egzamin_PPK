#include <iostream>
#include <random>

using namespace std;

/** Funkcja alokuje tablicę i wypełnia ją wartościami pseudolosoowymi. 
@param SIZE rozmiar tablicy do zaalokowania 
@return adres zaalokowanej i wypełnionej tablicy 
*/

int* generuj_tablice(const int SIZE){
	int* tablica = new int[SIZE];

	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000);

    for(int i=0; i<SIZE; i++)
    	tablica[i]=dis(gen);

    return tablica;

}

/** Funkcja tworzy nową tablicę i kopiuje do niej najpierw elementy z tablicy pierwszej, a potem 
z drugiej.
@param t1 adres pierwszej tablicy
@param n1 rozmiar pierwszej tablicy
@param t2 adres drugiej tablicy
@param n2 rozmiar pierwszej tablicy
@return adres nowej tablicy (o rozmiarze n1+n2) zawierającej kopi eelementów z pierwszej i drugiej tablicy 
*/

int* kontankentuj(const int* t1, const int n1, const int* t2, const int n2){
	int* tablica = new int[n1+n2];

	for(int i=0; i<n1; i++)
		tablica[i]=t1[i];
	for(int i=0; i<n2;i++)
		tablica[n1+i]=t2[i];
	return tablica;
}

/** Funkcja scala dwie tablice posortowane, tzn. tworzy nową tablicę i kopiuje do niej elementy z obu 
tablic w ten sposób, że w tablicy wynikowej elementy są także posortowane.
Żeby obniżyć złożoność obliczeniową, funkcja nie korzysta z sortowania.
@param t1 adres pierwszej tablicy posortowanej
@param N rozmiar pierwszej tablicy posortowanej
@param t2 adres drugiej tablicy posortowanej
@param M rozmiar pierwszej tablicy posortowanej
@return adres nowej tablicy posortowanej (o rozmiarze
n1+n2 ) zawierającej kopie elementów z pierwszej i drugiej tablicy
*/

int* scal(int* t1, const int N, int* t2, const int M){
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

	const int size = 10;
	int* tablica = generuj_tablice(10);
	for(int i=0; i<size; i++)
		cout<<tablica[i]<<" ";
	cout<<endl;

	int* tablica2 = generuj_tablice(10);
	for(int i=0; i<size; i++)
		cout<<tablica2[i]<<" ";
	cout<<endl;

	int* tablica3 = kontankentuj(tablica, size, tablica2, size);
	for(int i=0; i<size+size; i++)
		cout<<tablica3[i]<<" ";

	if(tablica and tablica2 and tablica3){
		delete[] tablica;
		tablica = nullptr;
		delete[] tablica2;
		tablica2= nullptr;
		delete[] tablica3;
		tablica3= nullptr;
	}


	return 0;
}