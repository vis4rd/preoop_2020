#pragma once

#include <iostream>
/**
 * struktura elementu listy
 * @tparam name nazwa elementu
 * @tparam next wskaznik do nastepnego elementu
 */
struct Element {
  char* name;
  Element *next;
};
/**
 * struktura listy jednokierunkowej
 * @tparam name nazwa listy
 * @tparam head wskaznik do pierwszego elementu listy
 * @tparam tail wskaznik do ostatniego elementu listy
 */
struct StudList {
  char *name;
  Element* head;
  Element* tail;
};

/**
 * funkcja inicjująca listę StudList i nadająca jej nazwę, alokująca pamięć dla name
 * @param list wskaźnik do nowej listy
 * @param name nazwa listy
 */
void initList (StudList* list,const char* name);

/**
 * funkcja sprawdzająca czy lista StudList jest pusta
 * @param list wskaźnik do listy
 * @return jeśli jest pusta, zwraca true; w przeciwnym wypadku false
 */
bool isEmpty (const StudList* list);

/**
 * funkcja dodająca element do listy StudList
 * @param list wskaznik do listy
 * @param name nazwa nowego elementu
 */
void append(StudList* list,const char* name);

//
/**
 * funkcja wypisująca elementy listy Studlist w nawiasach kwadratowych wraz z nazwą
 * @param list wskaznik do listy
 */
void print(const StudList* list);

/**
 * funkcja usuwająca pierwszy element listy StudList
 * @param list wskaznik do listy
 */
void removeFirst(StudList * l);

/**
 * funkcja usuwająca wszystkie elementy listy StudList; korzysta z removeFirst
 * @param list wskaznik do listy
 */
void clearList (StudList * l);

/**
 * funkcja usuwająca wszystkie elementy listy StudList wraz ze zwolnieniem pamięci na nazwę; korzysta z clearList
 * @param list wskaznik do listy
 */
void removeList (StudList * l);

/**
 * kopiowanie tablicy charow podanych w argumencie
 * @param wskaznik do tablicy charow
 * @return zaalokowana i wypelniona pamiec podana tablica charow
 */
char* mycopy (const char* string);

/**
 * obliczanie dlugosci tablicy charow
 * @param wskaznik do tablicy charow
 * @return dlugosc podanej tablicy
 */
int mystrlen (const char* string);