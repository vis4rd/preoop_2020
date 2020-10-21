/* 
   Proszę skompilować program automatycznie oraz manualnie (kompilator g++ z opcjami -Wall -pedantic) 
   a następnie z wykorzystaniem programu make oraz cmake (w domu)
   Prosty makefile powinien mieć zdefiniowane cele użytkownika run, clean (rm), check (valgrind) oraz all (main+run)

   Proszę uzupełnić kod o bibliotekę funkcje (funkcje.h funkcje.cpp)
   z funkcjami silnia, silnia_rec, wypisz, powiel, suma, średnia.
   Aktualnie bloki z wywołaniami funcji są zakomentarzowane,
   ale w przyszłości nie będzie wolno modyfikować pliku main.

   Rozwiązanie w formie spakowanych wszystkich plików źródłowych proszę w miarę możliwości umieścić w katalogu o nazwie
   nr_grupy_lab1_nazwisko, z którego należy utworzyć archiwum nr_grupy_lab1_nazwisko.zip
   (po ściągnięciu z repl.it wydedytować zip i dodać ręcznie katalog).
   i przesłać pod koniec zajęć na platformę UPEL
   Jeśli używamy makefile, koniecznie trzeba zrobić przed spakowaniem plików make clean.
 */

#include <iostream> 
#include <cmath>

#include "funkcje.h"

// Dodać plik nagłówkowy funkcje.h oraz funkcje.cpp
// Aby uniknąć podwójnego ładowania jednej biblioteki,
// w odpowiednim miejscu zastosuj dyrektywę pragma
// https://en.wikipedia.org/wiki/Pragma_once

using namespace std;

int main ()
{
  int i, abs_i;
  cout << "Podaj liczbę całkowitą: ";
  cin >> i;
  cout << "Podano liczbę " << i;
  abs_i = abs(i);
  cout << " a jej wartość bezwzględna wynosi " << abs_i << endl;

//Odkomentuj po napisaniu funkcji silnia, silnia_rec

  int k = (i<0? i : -i);
  int abs_k = abs(k);
  cout <<  0 << "! = " << silnia(0) << endl;
  cout <<  k << "! = " << silnia(k) << endl;
  cout << abs_k << "! = " << silnia(abs_k) << endl;
  cout << "Silnia obliczona rekurencyjnie:\n";
  cout << 0 << "! = " << silnia_rec(0) << endl;
  cout << k << "! = " << silnia_rec(k) << endl;
  cout << abs_k << "! = " << silnia_rec(abs_k) << endl;

  double tab[] = { 3, -1, 4, 10, -9, 10, 3 };
  const int size = sizeof(tab)/sizeof(tab[0]);
  double factor = 2.;

//Odkomentuj blok po napisaniu funkcji wypisz, powiel, suma, srednia

  cout << "tab[] = ";
  wypisz (tab, size);
  powiel (tab, factor, size);
  cout << "Po przemnożeniu przez " << factor << endl;
  cout << "tab[] = ";
  wypisz (tab, size);
  cout << "Suma: " << suma (tab, size) << endl;
  cout << "Średnia: " << srednia (tab, size) << endl;

  return 0;
}

/* 
Przykładowy oczekiwany wynik dla -5:

Podaj liczbę całkowitą: -5
Podano liczbę -5 a jej wartość bezwzględna wynosi 5
0! = 1
-5! = brak rozwiązania -1
5! = 120
Silnia obliczona rekurencyjnie:
0! = 1
-5! = Brak rozwiązania -1
5! = 120
tab[] = 3 -1 4 10 -9 10 3 
Po przemnożeniu przez 2
tab[] = 6 -2 8 20 -18 20 6 
Suma: 40
Średnia: 5.71428571
*/  