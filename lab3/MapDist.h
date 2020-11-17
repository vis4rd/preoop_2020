#pragma once

#include <cmath>
#include "MapPoint.h"

/*	Struktura mimikujaca dystans miedzy punktami
	@field poludnik
	@field rownoleznik
*/
typedef struct MapDist
{
    double longitude;
    double latitude;
}MapDist;

/*	Funkcja liczaca dystans pomiedzy dwoma punktami
	@param punkt numer 1
	@param punkt numer 2
	@return struktura przechowujaca wartosci przesuniecia z jednego punktu do drugiego
*/
MapDist distance(MapPoint &, MapPoint &);

/*	Funkcja liczaca dystans w linii prostej miedzy punktami
	@param struktura przechowujaca przesuniecie miedzy punktami
	@return liczba typu double oznajmiajaca odleglosc w linii prostej
*/
double angularDistance(MapDist );

/*	Funkcja wskazujaca na najblizszy punkt podanemu punktowi (z dwoch)
	@param punkt od ktorego mierzymy (oznaczenie - 0)
	@param punkt numer 1
	@param punkt numer 2
	@attention Zwracanej wartosci nie mozna modyfikowac!
	@return punkt blizszy punktowi referencyjnemu (0)
*/
const MapPoint &closestPlace(MapPoint *, MapPoint *, MapPoint *);