#pragma once

#include <iostream>

/*	Struktura przechowujaca folder
	@field nazwa folderu
	@field wskaznik na folder nadrzedny
	@field tablica wskaznikow na foldery podrzedne
	@field liczba folderow podrzednych
*/
typedef struct MyDir
{
    std::string name;
    struct MyDir *parent;
    struct MyDir **children;
    int childCount;
}MyDir; 

/*	Inicjalizacja struktury
	@param referencja do inicjalizowanego obiektu
	@param nazwa inicjalizowanego obiektu
*/
void initDir(MyDir &, std::string);

/*	Wypisywanie calego drzewa struktur
	@param nadrzedny folder, ktorego zawartosc zostanei wypisana
	@param glebokosc podrzednosci folderu (0 - MyDir)
*/
void printDir(MyDir, int = 0);

/*	Dodanie nowego folderu do drzewa
	@param referencja do folderu nadrzednego
	@param nazwa nowego folderu umieszczanego w nadrzednym
	@return wskaznik na nowoutworzony folder
*/
MyDir *addDir(MyDir &, std::string);

/*	Dodanie juz istniejacego folderu do drzewa
	@param referencja do folderu nadrzednego
	@param referencja do juz istniejacego dodawanego folderu
	@return wskaznik na nowoutworzony folder
*/
MyDir *addDir(MyDir &, MyDir &);

/*	Usuwanie folderu lub galezi folderow z drzewa
	@param wskaznik na nadrzedny folder do usuniecia
*/
void clearDir(MyDir *);

/*	Obliczanie dlugosci tablicy wskaznikow
	@attention DEPRECATED: lepiej uzywac skladnika struktury - int childCount
	@param wskaznik na tablice wskaznikow
	@return dlugosc tablicy
*/
int tabLength(MyDir **);

/*	Sprawdzenie poprawnosci nazwy folderu
	@param nazwa, ktora nalezy sprawdzic
	@return informacja o dlugosci (-1 - za krotka, 1 - za dluga, 0 - OK)
*/
int isNameOK(std::string);