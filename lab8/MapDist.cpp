#include "MapDist.h"

MapDist::MapDist()
{
    this->longitude = 0.0;
    this->latitude = 0.0;
}

MapDist::MapDist(MapPoint &a, MapPoint &b)
{
    this->longitude = fabs(a.coordX - b.coordX);
    this->latitude = fabs(a.coordY - b.coordY);
}

MapDist::~MapDist()
{
    
}

double MapDist::getlongitude() const
{
    return this->longitude;
}

double MapDist::getlatitude() const
{
    return this->latitude;
}   

double MapDist::angularDistance() const
{
    return sqrt((this->longitude*this->longitude)
     + (this->latitude*this->latitude));
}

MapDist distance(MapPoint &a, MapPoint &b)
{
    MapDist result;
    result.longitude = a.coordX - b.coordX;
    result.latitude = a.coordY - b.coordY;
    return result;
}
