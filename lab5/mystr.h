#pragma once

#include <iostream>
#include "studList.h"

/**
 * struktura przechowujaca i obslugujaca tablice charow
 * @tparam lista separatorow dzielacych tablice na slowa
 * @tparam tablica charow przechowujaca tekst
 * @tparam wskaznik na nastepny niepodzielony jeszcze fragment tekstu
 * @tparam wskaznik na poczatek tekstu
 * @tparam wskaznik na koniec tekstu
 */
typedef struct MyString
{
    char *tokens;   //wszystkie separatory
    char *text;     //string
    char *next;     //niepodzielony jeszcze fragment
    char *begin;    //poczatek
    char *end;      //koniec
}MyString;

/**
 * funkcja szukajaca separatora w tekscie
 * @param separator do znalezienia
 * @param tablica charow, w ktorej szuakmy separatora
 * @return true, jesli separator znaleziony, w przeciwnym wypadku false
 */
bool findSep(char, char*);

/**
 * procedura inicjalizujaca strukture
 * @param wskaznik do inicjalizowanej struktury
 * @param wskaznik do tablicy charow z tekstem
 * @param wskaznik do tablicy charow z tokenami (domyslny)
 */
void initMyString(MyString *, const char *, const char * = nullptr);

/**
 * funkcja dzielaca tekst na wyrazenia niebedace separatorami
 * @param wskaznik do struktury
 * @return ostatni lub nastepne znalezione wyrazenie
 */
char *mystrtok(MyString *);

/**
 * funkcja laczaca dwie tablice charow w jedna
 * @param wskaznik na tablice charow z tekstem
 * @param wskaznik na stala tablice charow
 * @param ewentualny separator miedzy laczonymi wyrazeniami
 * @return finalna polaczona tablcia charow
 */
char *mystrcat(char *, const char*, char = '\0');

/**
 * procedura dodajaca tablice separatorow do struktury
 * @param wskaznik do struktury
 * @param wskaznik do tablicy charow z separatorami
 */
void addSep(MyString *, const char*);

/**
 * procedura dodajaca podzielone wyrazenia do nowych elementow listy
 * @param wskaznik do listy
 * @param wskaznik do struktury
 */
void split2list(StudList *, MyString *);

/**
 * procedura czyszczaca i usuwajaca strukture
 * @param wskaznik do struktury
 */
void removeMyString(MyString *);

/**
 * funkcja pomocnicza sprawdzajaca czy podany znak jest separatorem
 * @param sprawdzany znak
 * @param tablica charow z separatorami
 * @return true, jesli znak jest separatorem, w przeciwnym wypadku false
 */
//bool isSeparator(char , char*);

/**
 * funkcja szukajaca wyrazenie miedzy separatorami o podanym indeksie
 * @param wskaznik do struktury
 * @param indeks (numer) wyrazenia
 * @return tablica charow ze znalezionym wyrazeniem o podanym indeksie
 */
char *gettok(MyString *, int);