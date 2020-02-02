#include <iostream>
#include <vector>

using namespace std;

/* Proszę napisać funkcję, która przyjmuje pięć liczb zmiennoprzecinkowych i zwraca ich minimum */

double Minimum(double a, double b, double c, double d, double e){
	double tablica[5] = {a, b, c, d, e};
	double najmnniejsza = tablica[0];
	for(int i=0; i<5; i++)
	{
		if(tablica[i] < najmnniejsza)
			najmnniejsza = tablica[i];
	}
	return najmnniejsza;
}

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

/* Proszę napisać funkcję, która przyjmuje tablicę liczb zmiennoprzecinkowych i rozmiar tablicy, i zwraca
ich minimum */

double MinimumTablica(double tablica[], const int N){
	double najmnniejsza = tablica[0];
	for(int i=0; i<5; i++)
	{
		if(tablica[i] < najmnniejsza)
			najmnniejsza = tablica[i];
	}
	return najmnniejsza;
}

/* Proszę napisać funkcję, która przyjmuje tablicę liczb zmiennoprzecinkowe i rozmiar tablicy, i odwraca
kolejność elementów w tablicy. */

void OdwrocTablice(double tablica[], const int N){
	for(int i=0, j= N-1; i < j; i++, j--)
		swap(tablica[i], tablica[j]);
}

//Simiński

void odwroc(int * tab, const int ROZMIAR)
{
    int * pLewy = tab;
    int * pPrawy = (tab + ROZMIAR - 1);
    
    while(pLewy < pPrawy)
        std::swap(*pLewy++, *pPrawy--);
}

/* Proszę napisać funkcję, która przyjmuje tablicę liczb całkowitych i rozmiar tablicy, i zwraca liczbę
liczb parzystych zawartych w tablicy */

int IleParzystych(int tablica[], const int N){
	int parzyste=0;
	for(int i=0; i<N; i++){
		if(tablica[i] % 2 == 0)
			++parzyste;
	}
	return parzyste;
}

/* Proszę napisać funkcję, która przyjmuje tablicę liczb naturalnych, rozmiar tablicy i wartość m,
i wpisuje do tablicy wartość tej komórki tablicy modulo m. Przykładowo po przekazaniu do funkcji
tablicy
4 9 12 567 15 24 65
i m = 7 wartości w tablicy zostaną nadpisane liczbami
4 2 5 0 1 3 2 */

void Modulo(int tablica[], const int N, int modulo){
	for(int i=0 ; i<N; i++){
		tablica[i] = tablica[i] % modulo;
	}
}

/* Proszę napiszą funkcję, która przyjmuje wektor liczb zmiennoprzecinkowych i zwraca wektor tychże
liczb w odwrotnej kolejności. */

vector<double> OdwrocWektor(vector<double> &wektor){
	reverse(wektor.begin(), wektor.end());
	return wektor;
}

/* Proszę napisać funkcję, która przyjmuje dwa posortowane wektory liczb całkowitych i zwraca posortowany 
wektor zawierający wszystkie liczby. Nie można użyć tutaj funkcji sortującej. */



int main(){
	double a= 2.41, b= 4.32, c= 5.41, d=1.15, e=54.2;
	cout<<Minimum(a,b,c,d,e)<<endl;

	const int rozmiar = 4;
	double tablica[] = {12.4, 15.8, 14.7, 11.4};
	cout<<MinimumTablica(tablica, rozmiar)<<endl;
	OdwrocTablice(tablica,rozmiar);

	for(int i=0; i<rozmiar; i++)
		cout<<tablica[i]<<" ";
	cout<<endl;

	int tablica2[] = {4,8,13,21,36};
	const int rozmiar2= 5;
	cout<<IleParzystych(tablica2, rozmiar2)<<endl;
	Modulo(tablica2, rozmiar2, 7);

	for(int i=0; i<rozmiar2; i++)
		cout<<tablica2[i]<<" ";
	cout<<endl;

	vector<double> wektor {43.2, 4411.4, 431.2, 45.64, 43.22};
	OdwrocWektor(wektor);
	for (auto ile : wektor)
		cout<<ile<<" ";

	return 0;
}