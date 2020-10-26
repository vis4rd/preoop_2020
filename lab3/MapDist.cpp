#include "MapDist.h"

MapDist distance(MapPoint &a, MapPoint &b)
{
    double tempAX = 0.0;
    double tempAY = 0.0;
    double tempBX = 0.0;
    double tempBY = 0.0;

    if(a.coordX < 0.0 && a.symbolX == 'W')
        tempAX = a.coordX;
    else if(a.coordX > 0.0 && a.symbolX == 'E')
        tempAX = a.coordX;
    else 
        tempAX = - a.coordX;
    
    if(a.coordY < 0.0 && a.symbolY == 'S')
        tempAY = a.coordY;
    else if(a.coordY > 0.0 && a.symbolY == 'N')
        tempAY = a.coordY;
    else 
        tempAY = - a.coordY;

    if(b.coordX < 0.0 && b.symbolX == 'W')
        tempAX = b.coordX;
    else if(b.coordX > 0.0 && b.symbolX == 'E')
        tempAX = b.coordX;
    else 
        tempAX = - b.coordX;

    if(b.coordY < 0.0 && b.symbolY == 'S')
        tempAY = b.coordY;
    else if(b.coordY > 0.0 && b.symbolY == 'N')
        tempAY = b.coordY;
    else 
        tempAY = - b.coordY;

    MapDist result;
    result.longitude = tempAX - tempBX;
    result.latitude = tempAY - tempBY;
    return result;
}

double angularDistance(MapDist target)
{
    return sqrt((target.longitude*target.longitude)
     + (target.latitude*target.latitude));
}

const MapPoint &closestPlace(MapPoint *target, MapPoint *a, MapPoint *b)
{
    MapDist atar = distance(*target, *a);
    MapDist btar = distance(*target, *b);
    if(angularDistance(atar) >= angularDistance(btar))
    {
        return *b;
    }
    else
    {
        return *a;
    }
}