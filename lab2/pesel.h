#pragma once

#include <iostream>
#include <cstring>

/*	Funkcja sprawdzajaca poprawnosc podanego peselu
	@param tablica przechowujaca pesel w postaci char
	@param tablica zwrotna po konwersji do typu int
	@return true/false wskazujacy czy pesel jest poprawny
*/
bool PeselValidator(char [11], int (&) [11]);

/*	Procedura wypisujaca pesel
	@param tablica przechowujaca pesel
*/
void printPesel(int[11]);

/*	Funkcja pobierajaca liczbe kontrolna (ostatnia cyfra ciagu pesel)
	@param tablica przechowujaca pesel
	@return znaleziona w tablicy liczba kontrolna
*/
int getCtrlNumber(int[11]);

/*	Funkcja zwracajaca plec na podstawie peselu w postaci slownej
	@param tablica przechowujaca pesel
	@return plec w postaci slownej
*/
std::string sex(int[11]);

/*	Funkcja pobierajaca z peselu dzien urodzenia
	@param tablica przechowujaca pesel
	@return znaleziony w pesel dzien urodzin
*/
int getDay(int[11]);

/*	Funkcja pobierajaca z peselu miesiac urodzenia
	@param tablica przechowujaca pesel
	@return znaleziony w pesel miesiac urodzin
*/
int getMonth(int[11]);

/*	Funkcja pobierajaca z peselu rok urodzenia
	@param tablica przechowujaca pesel
	@return znaleziony w pesel rok urodzin
*/
int getYear(int[11]);


/*	Funkcja sprawdzajaca przestepnosc roku
	@param sprawdzany rok w postaci RRRR
	@return true/false w zaleznosci czy podany rok jest przestepny
*/
bool leapYear(int);

/*	Funkcja liczaca dlugosc podanego ciagu cyfrowego
	@param tablica przechowujaca pesel
	@return dlugosc podanej tablicy z numerem pesel
*/
int getPeselLength(char[11]);