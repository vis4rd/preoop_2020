/* Należy zaimplementować strukturę obrazująca drzewo katalogów w systemie.
   Każdy folder może zawierać podfoldery.
   Podfoldery trzeba alokować dynamicznie za pomocą new i delete. 
   Do obsługi drzewa najprościej używać funkcji rekurencyjnych.
     
   Aby przejrzyście wypisać strukurę drzewa, funkcja print powinna otrzymywać odpowiednią ilość spacji albo kresek do wypisania. Proszę nie skupiac się w głównej mierze na podanym wzorze, na początek wystarczą zwykłe spacje albo podkreślniki, a jak starczy czasu to można dopracować.

   Do przechowywania wskaźników do potomków należy zastosować dynamiczną tablicę wskaźników do struktury, którą po dodatniu potomka trzeba powiększać. Korzystanie z kontenera std::vector albo tablicy statycznej jest akceptowalne, ale wiąże się z obniżeniem otrzymanej liczby punktów za zadanie o 3 punkty albo obowiązkowo zrobieniem całości zadania, łacznie z usuwaniem poddrzewa i właściwym drukowaniem drzewa.

   W przypadku wersji pełnej - zastosowania dynamicznej tablicy do przechowywania wskaźników (którą trzeba ponownie alokować), linię 60 z wywołaniem clearDir(&jan); można zakomentować i dokończyć po zajęciach.
   
   Dla uproszczenia przyjmujemy, że maksymalna długość nazwy to 10 znaków.  Można zatem użyć:
   * std::string (polecam, jest to najlepsze rozwiązanie).
   * tablicy statycznej (tradycyjnej char str[11] albo std::array).
   * tablicy dynamicznej (może braknąć czasu)
  
  Wskazówka: 
  Do usuwania gałęzi drzewa przyda się przechowywanie w strukturze wskaźnika do rodzica i funkcja usuwająca wskaźnik gałezi z listy potomków rodzica.
  Inne pomocnicze pola, które mogą się przydać - wg własnego uznania, np głębokość drzewa.
 */

#include "MyDir.h"
#include <iostream>

int main()
{  
    std::cout << "*** Drzewo plikow ***" << std::endl;
        
    MyDir root;
    initDir(root, "root");
    printDir(root);
    std::cout << std::endl;
    addDir(root, "etc");
    MyDir* home = addDir(root, "home");
    addDir(*home, "rok1");
    MyDir* rok2 = addDir(*home, "rok2");
    addDir(*home, "rok3");
    addDir(*home, "");
    printDir(root);
    std::cout << std::endl;
       
    // Za długa nazwa:
    addDir(*home, "Absolwenci_IS");
    std::cout << std::endl;
        
    MyDir jan;
    initDir(jan, "Jan");
    addDir( *addDir(jan, "oceny"), "PPO");
    printDir(jan);
    std::cout << std::endl;
    
    // Dodawanie całego katalogu z podkatalogami
    addDir(*rok2, jan);

    printDir(*home);
    std::cout << std::endl;
    
    // Czyszczenie katalogów
    std::cout << "*** Czyszczenie ***" << std::endl;
    clearDir(&jan); // usuwanie gałęzi - do ewentualnego zakomentowania i uzupełnienia po zajęciach jak braknie czasu
    printDir(root);
    clearDir(&root);

    /*  ########### UWAGA ###########
        Ponizsze dwie dealokacje sa niepotrzebne, a wrecz nieprawidlowe
        z tego wzgledu, ze pamiec zaalokowana w tych obszarach pamieci
        powinna byc i jest zwalniana w funkcji clearDir(MyDir *).

        Z tego tez wzgledu przy sprawdzaniu programu valgrindem pojawia
        sie blad:
            `total heap usage: 17 allocs, 19 frees, 74,216 bytes allocated`
        , czyli dwa zwolnienia za duzo, ktore maja zamiar zwolnic pamiec 
        o rozmiarze 0 bajtow.

        - przypis studenta
        ##############################*/
    delete home;
    delete rok2;
    
    return 0;
}

/**oczekiwany wynik:
./main
*** Drzewo plikow ***
root
Za krotka nazwa
root
|__etc
|__home
   |__rok1
   |__rok2
   |__rok3

Za dluga nazwa: Absolwenci_IS

Jan
|__oceny
   |__PPO

home
|__rok1
|__rok2
   |__Jan
      |__oceny
         |__PPO
|__rok3

*** Czyszczenie ***
// root
// |__etc
// |__home
//    |__rok1
//    |__rok2
//    |__rok3
*/

/*Dopuszcza się wersję uproszczną wypisywania postaci:
root
  etc
  home
     rok1
     rok2
     rok3
*/