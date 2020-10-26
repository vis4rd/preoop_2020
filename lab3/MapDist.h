#pragma once

#include <cmath>
#include "MapPoint.h"

typedef struct MapDist
{
    double longitude;
    double latitude;
}MapDist;

MapDist distance(MapPoint &, MapPoint &);
double angularDistance(MapDist );
const MapPoint &closestPlace(MapPoint *, MapPoint *, MapPoint *);