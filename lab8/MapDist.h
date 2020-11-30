#pragma once

#include <cmath>
#include "MapPoint.h"

class MapPoint;

class MapDist
{
friend class MapPoint;
friend MapDist distance(MapPoint &, MapPoint &);

public:
    /** Konstruktor domyslny
    */
    MapDist();

    /** Konstruktor, 
    *   @param Punkt pierwszy
    *   @param Punkt drugi
    */
    MapDist(MapPoint &, MapPoint &);

    /**  Destruktor domyslny
    */
    ~MapDist();

    /** Getter skladnika klasy
    *   @return dlugosc geograficzna typu double
    */
    double getlongitude() const;

    /** Getter skladnika klasy
    *   @return szerokosc geograficzna typu double
    */
    double getlatitude() const;

    /**	Dystans liczony w linii prostej (obiekt zapisuje dystans w manhattanDistance)
    *   @return dystans w linii prostej typu double
    */
    double angularDistance() const;
protected:

private:
    double longitude;
    double latitude;
};
