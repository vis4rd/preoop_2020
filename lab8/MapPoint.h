#pragma once

#include <iostream>
#include "MapDist.h"
class MapDist;

class MapPoint
{
    friend class MapDist;
    friend MapDist distance(MapPoint &a, MapPoint &b);
    friend MapPoint inTheMiddle(MapPoint *a, MapPoint *b, std::string name);

public:
    /** Konstruktor domyslny
    */
    MapPoint();

    /** Konstruktor (przeladowanie 1)
    *   Polkule wnioskowane sa ze znaku przy liczbie.
    *   Uklad wspolrzednych wyglada tak:
    *
    *               N
    *              /\
    *         B    |
    *              |
    *              | (0, 0)
    *   W----------0---------->E
    *              |
    *              |
    *       X      |
    *              |
    *              S
    *
    *   Czyli punkt X ma wspolrzedne (-X.xW, -X.yS)
    *   Natomiast punkt B ma wsporzedne (-B.xW, B.yN)
    *
    *   @param nazwa punktu
    *   @param dlugosc geograficzna
    *   @param szerokosc geograficzna
    */
    MapPoint(std::string name, const double longitude, const double latitude);

    /** Konstruktor (przeladowanie 2)
    *   Polkule sa podawane w argumentach, wiec wszelkie niezgodnosci pomiedzy
    *   symbolem oraz liczba sa poprawiane (z zachowaniem znaku).
    *   
    *   Czyli, gdyby podac punkt X = (X.xW, -X.yN), to zostaloby to poprawione
    *   na X = (-X.xW, X.yN). To znaczy, ze podany symbol ma wieksze znaczenie 
    *   niz znak przy liczbie.
    *   
    *   Przyklad drugi:
    *   B = (-B.xE, B.yS)  =>>  (B.xE, -B.yS)
    *   
    *   @param nazwa punktu
    *   @param dlugosc geograficzna
    *   @param symbol polkuli (W/E - zachod/wschod)
    *   @param szerokosc geograficzna
    *   @param symbol polkuli (S/N - poludnie/polnoc)   
    */
    MapPoint(std::string name, const double longitude, const char symbolX, 
                               const double latitude, const char symbolY);

    /** Destruktor domyslny
    */
    ~MapPoint();

    /**	Wypisywanie skladnikow klasy
    */
    void print() const;

    /**	Przesuniecie punktu o dana dlugosc i szerokosc geograficzna
    *   @param wartosc przesuniecia wzdluz poludnika
    *   @param wartosc przesuniecia wzdluz rownoleznika
    */
    void movePoint(const double, const double);

    /**	Getter nazwy punktu
    *   @return nazwa punktu
    */
    std::string getName() const;

    /**	Znajdowanie punktu, ktory w jest w linii prostej blizej
    *   @param punkt numer 1
    *   @param punkt numer 2
    *   @return blizszy punkt
    */
    const MapPoint &closestPlace(MapPoint *, MapPoint *);
protected:

private:
    std::string name;
    double coordX;
    double coordY;
    char symbolX;
    char symbolY;
};