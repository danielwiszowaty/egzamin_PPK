#include <iostream>
#include <vector>
#include <random>

using namespace std;

/** Funkcja zapisuje do strumienia przekazane liczby
@param str strumien do zapisu
@param liczby tablica liczb do zapisu do strumienia
@param N rozmiar tablicy liczb
*/

void zapisz_liczby(ostream& str, const double liczby[], const int N){
	for(int i=0; i<N; i++)
		str<<liczby[i]<<" ";
}

/** Funkcja zapisuje do strumienia przekazane liczby
@param str strumien do zapisu
@param liczby tablica liczb do zapisu do strumienia
*/

void zapisz_liczby1(ostream& str, const vector<double> liczby){
	for(auto i : liczby)
		str<<i<<" ";
}

/** Funkcja zapisuje do podanego strumienia losową liczbe losowych liczb zmiennoprzecinkowych */
void zapisz_losowe(ostream& str){
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 50);

    for(int i=0; i<(int)dis(gen); i++)
    	str<<dis(gen)<<" ";
}

/** Funkcja zwraca srednią liczby podanych w strumieniu.
@param str strumień z liczbami
@return srednia liczb podanych w strumieniu, gdy nie ma żadnej liczby w strumieniu funkcja zwraca 0
*/
double srednia_liczb(istream& str){
	std::vector<double> liczby;
	double liczba;
	while(str>>liczba)
		liczby.push_back(liczba);
	double srednia = 0;
	for(auto i : liczby)
		srednia += i;
	return srednia / liczby.size();
} 

int main(){

	double tab[]={4.32, 44.1, 411.4, 424.3};
	const int size = 4;
	zapisz_liczby(cout, tab, size);
	cout<<endl;

	std::vector<double> v {4.32,44.1};
	zapisz_liczby1(cout, v);
	cout<<endl;
	//zapisz_losowe(cout);
	//cout<<srednia_liczb(cin);

	return 0;
}