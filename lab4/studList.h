#pragma once

#include <iostream>
#include <cstring>

typedef struct Node
{
    struct Node *next;
    char *name;
}Node;

typedef struct StudList
{
    char *name;
    Node *head;
    Node *tail;
}StudList;

void initList(StudList *, const char[]);  //inicjalizacja listy, nadanie nazwy strukturze
void prepend(StudList *, const char[]);   //dodawanie elementu na poczatek listy
bool isEmpty(const StudList *);     //sprawdzenie, czy lista jest pusta
void print(const StudList *);       //wypisywanie zawartosci listy
void removeLast(StudList *);        //usuniecie ostatniego elementu listy
void clearList(StudList *);         //usuniecie calej zawartosci listy
void removeList(StudList *);        //usuniecie struktury listy 
                                    //...(wraz z nazwa i wszystkimi elementami)