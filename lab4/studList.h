#pragma once

#include <iostream>
#include <cstring>

/*	Element struktury (listy)
	@field wskaznik na nastepny element struktury
	@field nazwa elementu
*/
typedef struct Node
{
    struct Node *next;
    char *name;
}Node;

/*	Struktura przechowujaca liste struktur
	@param nazwa listy
	@param wskaznik na pierwszy element
	@param wskaznik na ostatni element
*/
typedef struct StudList
{
    char *name;
    Node *head;
    Node *tail;
}StudList;

/*	Inicjalizacja listy
	@param wskaznik na niezainicjalizowana strukure
	@param nowa nazwa dla podanej struktury
*/
void initList(StudList *, const char[]);

/*	Dodawanie elementu na poczatek listy
	@param wskaznik do listy
	@param nazwa nowego elementu
*/
void prepend(StudList *, const char[]);

/*	Funkcja sprawdzajaca czy lista jest pusta
	@param wskaznik do listy
	@return true/false wskazujacy czy lista jest pusta
*/
bool isEmpty(const StudList *);

/*	Wypisywanie calej listy
	@param wskaznik do listy
*/
void print(const StudList *);

/*	Usuwanie ostatniego elementu listy
	@param wskaznik do listy
*/
void removeLast(StudList *);

/*	Usuwanie wszystkich elementow listy
	@param wskaznik do listy
	@attention procedura ta korzysta z removeLast(StudList *)
*/
void clearList(StudList *);

/*	Zwolnienie pamieci struktury przechowujacej liste
	@param wskaznik do listy
*/
void removeList(StudList *);