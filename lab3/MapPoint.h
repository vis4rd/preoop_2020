#pragma once

#include <iostream>
//#include <string>

typedef struct MapPoint
{
    struct MapPoint *copy = NULL;
    std::string name;
    double coordX;
    double coordY;
    char symbolX;
    char symbolY;
}MapPoint;

MapPoint *construct(std::string, const double, const double);
void print(const MapPoint *);
MapPoint *construct(std::string, const double, char, const double, char);
//MapPoint *copyCTR(MapPoint *);
void movePoint(MapPoint *, const double, const double);
void clear(MapPoint *, MapPoint * = nullptr, MapPoint * = nullptr);
std::string getName(const MapPoint &);
MapPoint inTheMiddle(MapPoint *, MapPoint *, std::string name);