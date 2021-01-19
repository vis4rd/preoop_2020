/* Zdefiniuj klasę Fraction reprezentujacą ułamek zwykły.
   posiadającą dwa pola prywatne _l i_m typu int.

 * Zdefiniuj niezbędne konstruktory i metody pomocnicze.
   Ułamek jest upraszczany na etapie konstruktora (funkcja simplify).
   W ramach uproszczenia, w komentarzu umieszczono kod funkcji nwd,
   służacej do wyliczenia największego wspólnego dzielnika.
   
 * Zaimplementuj operatory dodawania +, mnożenia *
   (również w wersji liczba + ułamek), operator *=
   operator przypisania =, operator liczby przeciwnej -, 
   ostream << oraz konwersję do double Fraction.
   Zdecyduj, które operatory napisać jako metody klasy
   a które jako zewnętrzne funkcje.
  
 * W wybranych miejscach po odkomentowaniu program nie powinien się kompilować.
   Należy zadbać o to, aby wysłać wersję, która się kompiluje.
 * W innych przypadkach pliku main.cpp, NIE WOLNO modyfikować.
 * Proszę pamietać o dokumentacji kodu.
*/

#include "fraction.h"
#include <iostream>

using namespace std;

/* do wykorzystania w funkcji simplify
int nwd(int m, int n){
	int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
	    m = oldn;
	    n = oldm % oldn;
	}
    return n;
} */

int main ()
{
  Fraction f1(6,8);
  const Fraction f2(3,2);
  Fraction f3(6,2);
  cout << "Ułamki po skróceniu w konstruktorze:" << endl; 
  cout << "f1 = " << f1 << endl; 
  cout << "f2 = " << f2 << endl; 
  cout << "f3 = " << f3 << endl; 

  double val = f1;
  cout << "Ułamek dziesiętny f1: " << val << endl; 
  
  cout << "**********  Prosta arytmetyka *************" << endl; 
  Fraction f4=f1*f2;
  f3=f1*f4;
  cout << "Iloczyn: " << f1 << " * " << f2 <<" = " << f4 << endl; 
  cout << "Iloczyn: " << f1 << " * " << f4 <<" = " << f3 << endl;
  f3*=4;
  cout << "Iloczyn: " << f1*f4 <<" * 4 = " << f3 << endl; 
  cout << "Iloczyn: " << f1*f4 <<" * 4 = " << static_cast<float>(f3) << endl; 
  cout << "Suma: " << f1 << " + " << f2 <<" = " << f1+f2 << endl;

  f3= -f3;
  cout << "Suma: " << "1 + " << f3 <<" = " << 1+f3 << endl; 

  f3 = -f1;
  cout << "f3 = -f1   " << f3 << endl;; 
 
//Zadania do poeksperymentowania po skończeniu pierwszej części
  f1=f2; // OK
 // f1+f2=f4; // ma się nie kompilować po odkomentowaniu

  Fraction tab[2];
  tab[0] = f1; //OK
  f1 = tab[0]; //OK
  //f2 = tab[0]; //ma się nie kompilować po odkomentowaniu
  // ponieważ chcemy zapobiec modyfikowaniu obiektów const

  return 0;
}

/* Oczekiwany wynik: ./main
Ułamki po skróceniu w konstruktorze:
f1 = 3/4
f2 = 1 1/2
f3 = 3
Ułamek dziesiętny f1: 0.75
**********  Prosta arytmetyka *************
Iloczyn: 3/4 * 1 1/2 = 1 1/8
Iloczyn: 3/4 * 1 1/8 = 27/32
Iloczyn: 27/32 * 4 = 3 3/8
Iloczyn: 27/32 * 4 = 3.375
Suma: 3/4 + 1 1/2 = 2 1/4
Suma: 1 + -3 3/8 = -2 3/8
f3 = -f1   -3/4
*/
