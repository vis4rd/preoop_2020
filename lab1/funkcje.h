#pragma once

#include <iostream>
#include <iomanip>

/* silnia - iteracyjna funkcja zwracajaca wartosc silni dla n
	@param n - wartosc, z ktorej wyliczamy silnie
	@return silnia z podanej wartosci
*/
int silnia(int);

/* silnia - rekurencyjna funkcja zwracajaca wartosc silni dla n
	@param n - wartosc, z ktorej wyliczamy silnie
	@return silnia z podanej wartosci
*/
int silnia_rec(int);

/* 	wypisywanie podanej tablicy liczb typu double
	@param tablica liczb typu double
	@param wielkosc wypisywanej tablicy
*/
void wypisz(double[], const int);

/* 	wypisywanie podanej tablicy liczb typu double
	@param tablica liczb typu double
	@param czynnik przez ktory mnozymy wszystkie elementy tablicy
	@param wielkosc wypisywanej tablicy
*/
void powiel(double[], double, const int);

/* 	wypisywanie podanej tablicy liczb typu double
	@param tablica liczb typu double
	@param wielkosc wypisywanej tablicy
	@return suma wartosci elementow podanej tablicy
*/
double suma(double[], const int);

/* 	wypisywanie podanej tablicy liczb typu double
	@param tablica liczb typu double
	@param wielkosc wypisywanej tablicy
	@return srednia z wartosci elementow podanej tablicy
*/
double srednia(double[], const int);

