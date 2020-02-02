/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 3: funkcje
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl


#include <iostream> 
#include <random>
#include <chrono>
#include <vector>


/** To jest komentarz w stylu doxygen.
  
 * Funkcja dodająca dwie wartości całkowite. 
 * Parametry są przekazane przez wartość.
 * @param a dodajna
 * @param b dodajnik
 * @return suma dodajnej i dodajnika
 */ 
int dodaj (int a, const int b)   // a i b są kopiami
{
    int wynik = a + b;
    a = 1234; // modyfikacja kopii, zmiana lokalna, niewidoczna na zewnątrz funkcji
    return wynik;
}

/** Funkcja odejmująca dwie wartości całkowite.
 * @par am a odjemna
 * @param b odjemnik
 * @return różnica odjemnej i odjemnika
 */ 
auto odejmij (const int a, const int b) -> int
{ 
    return a - b;
}
/** Funkcja mnożąca dwie wartości całkowite.
 * @param a mnożna
 * @param b mnożnik
 * @return iloczyn mnożnej i mnożnika - Typ wartości zwracanej będzie automatycznie wyznaczony na podstawie wyrażenia w instrukcji return.
 */ 
auto mnoz (const int a, const int b) // jeżeli jest to możliwe, to lepiej przekazywać parametry jako stałe
{
    return a * b;
}


/** Funkcja zwiększa wartość pierwszego parametru, a zmniejsza drugiego.
 * Parametry są przekazane przez referecję, zatem modyfikacje wewnątrz funkcji będą widoczne na poza funkcją. 
 * @param[in,out] a liczba bedzie powiekszona
    @param[in,out] b liczba bedzie zmniejszona
    @return nic :-)
*/
void zwiekszRoznice (int & a, int & b) // oba parametry przekazane przez referencję
{
    a++;
    b--;
    
    return; 
}


/** Funkcja dzieląca dwie wartości całkowite.
 * @param a dzielna
 * @param b dzialnik
 * @return iloraz dzielnej i dzielnika
 * @warning Funkcja wykonuje dzielenie <b>całkowitoliczbowe</b>.
 */
inline double podziel (double a, double b)
{
    return a / b;
}


/** @return Funkcja zwraca wartosci z przedziału [0, 99] z rozkładem jednorodnym. */
int los ()
{
    std::default_random_engine silnik;
    silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> rozklad (0, 99);
    
    return rozklad (silnik);
}

/** @return Funkcja zwraca 12. */
int dwanascie ()
{
    return 12;
}

/** @return Funkcja zwraca 12. 
    @remark Uzycie slowa kluczowego <b>constexpr</b> powoduje, ze kompilator postara sie wyznaczyć wartosc funkcji w czasie kompilacji i tę wartość będzie traktować jako stałą znaną w czasie kompilacji (constexpr).
  */
constexpr int stale_dwanascie ()
{
    return 12; 
}

/** @return zwraca wartosc silni

  Funkcja constexpr oznacza, że wynik funkcji moze byc użyty tam, gdzie konieczna jest stała o wartości znanej już  w czasie kompilacji.
  Funkcja musi być na tyle prosta, by jej wartosc była możliwa do obliczenia w czasie kompilacji. 
 */
constexpr unsigned long long int silnia (unsigned int i)
{
    return i < 2 ? 1 : i * silnia(i - 1);
}

/** Funkcja wypisuje tablicę na standardowe wyjście. 
 * @param t tablica do wypisania
 * @param N rozmiar tejże
 * @author to ja :-)
 * @remark Tablica musi istnieć!
 * @todo do implementacji
 */ 
void wypisz (double t[], const int N)
{
    for (int i = 0; i < N; i++)
        std::cout << t[i] << " ";
    std::cout << std::endl;
}

/** Funkcja wypełnia tablicę wartościami losowymi
 * @param t tablica do wypełnienia
 * @param N rozmiar tablicy do wypełnienia
 * @return nie zwraca nic - standard języka zabrania zwracania tablic z funkcji
 * @remark Tablica musi istnieć!
 * @todo do implementacji
 */ 
void wypelnij (double t[], const int N)
{
    for (int i = 0; i < N; i++)
       t[i] = i;   // modyfikacja wartości w tablicy!
}

 
/** @param ile liczba parametrów wywołania funkcji main
    @param params tablica napisów reprezentujących parametry 
 */
int main (int ile, char * params[])
{

   // proste funkcje 
  
   int suma = dodaj   (5, 4);  // parametry przekazane przez wartość (kopiowane)
    
   std::cout << suma << std::endl;
   
   int pierwsza =  10;
   int druga    = -10;
   debug(pierwsza);
   debug(druga);
   std::cout << dodaj (pierwsza, druga) << std::endl;
   debug(pierwsza);
   debug(druga);

   
//    return 0;
   
   std::cout << odejmij (5, 4) << std::endl;
   std::cout << mnoz    (5, 4) << std::endl;
   
//    return 0;
   

    
   debug(pierwsza);
   debug(druga);

   zwiekszRoznice (pierwsza, druga);  // parametry przekazane przez referencję    
   
   debug(pierwsza);
   debug(druga);
   
//    return 0;

   int r = los();
   debug(r);
   
//    return 0;
   
   const int c_r = los();   // const oznacza, że po inicjalizacji nie można modyfikować wartości.
   debug(c_r);
//       c_r++;  // nie wolno!

   
//    int tab1[c_r];  // nie działa!
   
//    return 0;
   
//     constexpr int cexpr_r = los();  // nie działa! Wartość funkcji los nieznana w czasie kompilacji.
   
   
//     int tab_c_r [cexpr_r];
   
//    int tab12 [dwanascie()];   // Funkcja dwanascie() nie jest constexpr.
   
   int tab12constexpr [stale_dwanascie()];  // OK
   
   
//    return 0;
   
   int zmienna = 4;
   // funkcje constexpr
   int tab[silnia(4)]; // Funkcja silnia jest constexpr i przyjmuje parametr, którego wartość jest znana w czasie kompilacji.
//    int tab[silnia(zmienna)];   // Funkcja silnia jest constexpr, ale przyjmuje parametr, którego wartość NIE jest znana w czasie kompilacji. 
   
   
//    return 0;
   
   // funkcje inline
   double iloraz = podziel (45, 55); // Prosimy kompilator o rozwinięcie funkcji w tym miejscu, czyli: 45 / 55; 
   debug(iloraz);

//    return 0;
   // przekazywanie tablic do funkcji 
   const int ROZMIAR = 5;
   double tablica[ROZMIAR]; 

//    return 0;
   // wypisanie tablicy:
   std::cout << "tablica niezainicjowana" << std::endl;
   wypisz (tablica, ROZMIAR);

//    return 0;
   // wypelnienie tablicy:
   wypelnij (tablica, ROZMIAR);
   std::cout << "tablica wypelniona" << std::endl;
   wypisz (tablica, ROZMIAR);

//    return 0;

   // main to tez funkcja! I moze miec swoje parametry (podawane przy uruchomieniu z linii polecen).
   for (int i = 0; i < ile; i++)
      std::cout << i << ": " << params[i] << std::endl;
  

//    return 0;  // odczytywanie tego, co zwrocil main: ./main ; echo $?
   
   // wektor
   std::vector<int> tablica_o_zmiennym_rozmarze; // pusty wektor (rozmiar: 0)

   tablica_o_zmiennym_rozmarze.push_back(12); // dodajemy wartość 12 na koniec 
   debug(tablica_o_zmiennym_rozmarze[0]);     // dostęp do elementów wektora jak w zwykłej tablicy
   std::cout << tablica_o_zmiennym_rozmarze.size() << std::endl;  // wypisanie liczby elementów wektora
   tablica_o_zmiennym_rozmarze.push_back(6);  // dodajemy wartość 6 na koniec (wydłużenie wektora o 1)
   std::cout << tablica_o_zmiennym_rozmarze.size() << std::endl;
  
   for (int i = 0; i < 10; i++)
      tablica_o_zmiennym_rozmarze.push_back(i * 20);  // dodajemy w pętli
  
   std::cout << tablica_o_zmiennym_rozmarze.size() << std::endl;
   
   for (int i = 0; i < tablica_o_zmiennym_rozmarze.size(); i++)
       std::cout << tablica_o_zmiennym_rozmarze[i] << " ";  // dostęp do elementów jak w zwykłej tablicy
   std::cout << std::endl;
   
   std::cout << tablica_o_zmiennym_rozmarze.size() << std::endl;
   
   for (int i = 0; i < 50; i++)
   {
       tablica_o_zmiennym_rozmarze.push_back(i);
       std::cout << "size: "       << tablica_o_zmiennym_rozmarze.size()  // liczba elementów w wektorze 
                 << ", capacity: " << tablica_o_zmiennym_rozmarze.capacity() // rzeczywista rozmiar wektora (liczba elementów, dla których została zaalokowana pamięć) 
                 << std::endl;
   }
   std::cout << tablica_o_zmiennym_rozmarze.size() << std::endl;
   tablica_o_zmiennym_rozmarze.pop_back();  // usunięcie ostatniego elementu z wektora
   std::cout << tablica_o_zmiennym_rozmarze.size() << std::endl;
   
   std::cout << tablica_o_zmiennym_rozmarze[10000] << std::endl;  // kompilator nie sprawdza poprawności indeksów
   
   // wypisane tablicy pętlą for
   for (std::size_t i = 0; i < tablica_o_zmiennym_rozmarze.size(); i++)
       std::cout << tablica_o_zmiennym_rozmarze[i] << " ";
   std::cout << std::endl;
   
   // wypisanie tablicy pętla for, for each (iterator wewnętrzny)
   for (auto el : tablica_o_zmiennym_rozmarze) // dla każdego elementu w tablicy_o_zmiennym_rozmiarze
       std::cout << el << " ";                 // wypisz tenże element
   std::cout << std::endl;
   
   return 0;
} 

// Finis coronat opus.
