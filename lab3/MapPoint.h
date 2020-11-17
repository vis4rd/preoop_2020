#pragma once

#include <iostream>
//#include <string>


/*	Struktura mimikujaca punkt na mapie
	@field nazwa punktu
	@field poludnik
	@field rownoleznik
	@field symbol polkuli horyzontalnej
	@field symbol polkuli wertykalnej
*/
typedef struct MapPoint
{
    std::string name;
    double coordX;
    double coordY;
    char symbolX;
    char symbolY;
}MapPoint;

/*	Konstruktor tworzacy nowy punkt na mapie
	@param nazwa nowego punktu
	@param wartosc lokalizacji poludnika
	@param wartosc lokalizacji rownoleznika
	@attention Ta funkcja ma swoje przeciazenie
	@return nowy punkt na mapie
*/
MapPoint *construct(std::string, const double, const double);

/*	Procedura wypisujaca dane struktury MapPoint
	@param punkt potrzebny do wypisywania
*/
void print(const MapPoint *);

/*	Konstruktor tworzacy nowy punkt na mapie
	@param nazwa nowego punktu
	@param wartosc lokalizacji poludnika
	@param dodatkowy symbol poludnika
	@param wartosc lokalizacji rownoleznika
	@param dodatkowy symbol rownoleznika
	@attention Ta funkcja ma swoje przeciazenie
	@return nowy punkt na mapie
*/
MapPoint *construct(std::string, const double, char, const double, char);

/*	Procedura przesuwajaca punkt na mapie
	@param wskaznik do docelowego punktu
	@param wartosc przesuniecia wzdluz poludnika
	@param wartosc przesuniecia wzdluz rownoleznika
*/
void movePoint(MapPoint *, const double, const double);

/*	Procedura usuwajaca i zwalniajaca pamiec
	@param struktura do usuniecia
	@param kolejna (2) struktura (nieobowiazkowa)
	@param kolejna (3) struktura (nieobowiazkowa)
*/
void clear(MapPoint *, MapPoint * = nullptr, MapPoint * = nullptr);

/*	Funkcja pobierajaca nazwe podanej struktury
	@param referencja do struktury
	@return nazwa elementu struktury
*/
std::string getName(const MapPoint &);

/*	Funkcja tworzaca nowy punkt pomiedzy dwoma podanymi
	@param podawany punkt numer 1
	@param podawany punkt numer 2
	@param nazwa nowego punktu na mapie
*/
MapPoint inTheMiddle(MapPoint *, MapPoint *, std::string name);