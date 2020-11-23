#pragma once

#include "Element.h"

/*	Klasa tworzaca i obslugujaca liste jednokierunkowa
	@field nazwa listy
	@field wskaznik na pierwszy element
	@field wskaznik na ostatni element
*/
class StudList
{
    friend class Element;
public:

	/*	Domyslny konstruktor
	*/
    StudList();

    /*	Przeladowanie konstruktora
    	@param nazwa kontenera
    */
    StudList(const char name[]);

    /*	Domyslny destruktor
	*/
    ~StudList();

    /*	#Inicjalizacja listy
        #@param wskaznik na niezainicjalizowana strukure
        #@param nowa nazwa dla podanej struktury
    */
    //void initList(StudList *, const char[]);

    /*	Dodawanie elementu na poczatek listy
	    @param nazwa nowego elementu
    */
    void prepend(const char elementName[]);


    /*	Dodawanie elementu na poczatek listy
	    @param wskaznik nowego elementu
    */
    void prepend(Element *element);

    /*	Getter pierwszego elementu listy
    	@return pierwszy element listy
    	@note jesli lista jest pusta, zwracany jest NULL
    */
    const Element *getHead() const;

    /*	Getter ostatniego elementu listy
    	@return wskaznik ostatni element listy
    	@note jesli lista jest pusta, zwracany jest NULL
    */
    const Element *getTail() const;

    /*	Getter ostatniego elementu z jego usunieciem
    	@return wskaznik na usuniety ostatni element listy
    	@warning zwracany element jest USUWANY z listy
    */
    Element *getLast();

    /*	Getter nazwy kontenera (listy)
    	@return tablica char zawierajaca nazwe listy
    */
    const char *getName() const;

    /*	Metoda sprawdzajaca czy lista jest pusta
		@return true - lista jest pusta, false - nie jest
    */
    bool isEmpty() const;

    /*	Wypisywanie calej listy
    */
    void print() const;

    /*	Usuwanie ostatniego elementu listy
    */
    void removeLast();

    /*	Usuwanie wszystkich elementow listy
        @attention procedura ta korzysta z removeLast(StudList *)
    */
    void clearList();

    /*	Zwolnienie pamieci struktury przechowujacej liste
    */
    void removeList();

protected:

private:
    char *name;
    Element *head;
    Element *tail;
};





