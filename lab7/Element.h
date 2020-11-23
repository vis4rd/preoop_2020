#pragma once

#include <cstring>
#include <iostream>

class StudList;

/*	Element kontenera - listy
	@field wskaznik na nastepny element struktury
	@field nazwa elementu
*/
class Element
{
    friend class StudList;

public:
	/*	Konstruktor domyslny
	*/
    Element();

    /*	Przeladowanie konstruktora
    	@param nazwa elementu
    */
    Element(const char name[]);

    /*	Destruktor domyslny
    */
    ~Element();

    /*	Getter nazwy elementu
		@return tablica charow przechowujaca nazwe elementu
    */
    const char *getName() const;

    /*	Wypisywanie nazwy elementu (nie zwracanie)
    */
    void printName() const;

protected:

private:
    Element *next;
    char *name;
};