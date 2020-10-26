#include "MapPoint.h"

MapPoint *construct(std::string name, const double coordX, const double coordY)
{
    MapPoint *punkt = new MapPoint;
    punkt->name = name;
    punkt->coordX = coordX;
    punkt->coordY = coordY;
    if(coordX < 0.0)
    {
        punkt->symbolX = 'W';
    }
    else
    {
        punkt->symbolX = 'E';
    }

    if(coordY < 0.0)
    {
        punkt->symbolY = 'S';
    }
    else
    {
        punkt->symbolY = 'N';
    }

    return punkt;
}

void print(const MapPoint *punkt)
{
    std::cout << "Wspolrzedne dla " << punkt->name << ": "
                << punkt->coordX << punkt->symbolX << ", "
                << punkt->coordY << punkt->symbolY << std::endl;
}

MapPoint *construct(std::string name, const double coordX, char symbolX,
             const double coordY, char symbolY)
{
    MapPoint *punkt = new MapPoint;
    punkt->name = name;
    punkt->coordX = coordX;
    punkt->coordY = coordY;
    if(coordX < 0.0)
    {
        punkt->symbolX = symbolX;
    }
    else
    {
        punkt->symbolX = symbolX;
    }

    if(coordY < 0.0)
    {
        punkt->symbolY = symbolY;
    }
    else
    {
        punkt->symbolY = symbolY;
    }
    return punkt;
}

void movePoint(MapPoint *punkt, const double shiftX, const double shiftY)
{
    if(punkt->symbolX == 'W' && shiftX < 0.0)
        punkt->coordX += shiftX;
    else if(punkt->symbolX == 'E' && shiftX > 0.0)
        punkt->coordX += shiftX;
    else
        punkt->coordX -= shiftX;

    if(punkt->symbolY == 'S' && shiftY < 0.0)
        punkt->coordY += shiftY;
    else if(punkt->symbolY == 'N' && shiftY > 0.0)
        punkt->coordY += shiftY;
    else
        punkt->coordY -= shiftY;
}

void clear(MapPoint *a, MapPoint *b, MapPoint *c)
{
    std::cout<<"Usuwanie "<<a->name<<std::endl;
    delete a;
    if(b != nullptr)
    {
        std::cout<<"Usuwanie "<<b->name<<std::endl;
        delete b;
    }

    if(c != nullptr)
    {
        std::cout<<"Usuwanie "<<c->name<<std::endl;
        delete c;
    }
}

std::string getName(const MapPoint &a)
{
    return a.name;
}

MapPoint inTheMiddle(MapPoint *a, MapPoint *b, std::string name)
{
    double tempAX = 0.0;
    double tempAY = 0.0;
    double tempBX = 0.0;
    double tempBY = 0.0;

    if(a->coordX > 0.0 && a->symbolX == 'E')
        tempAX = - a->coordX;
    else 
        tempAX = a->coordX;
    
    if(a->coordY > 0.0 && a->symbolY == 'S')
        tempAY = - a->coordY;
    else 
        tempAY = a->coordY;

    if(b->coordX > 0.0 && b->symbolX == 'E')
        tempAX = - b->coordX;
    else 
        tempAX = b->coordX;

    if(b->coordY > 0.0 && b->symbolY == 'S')
        tempAY = - b->coordY;
    else 
        tempAY = b->coordY;

    MapPoint temp;
    temp.name = name;
    temp.coordX = tempAX + tempBX;
    temp.coordY = tempAY + tempBY;
    if(temp.coordX < 0.0)
        temp.symbolX = 'W';
    else
        temp.symbolX = 'E';

    if(temp.coordY < 0.0)
        temp.symbolY = 'S';
    else
        temp.symbolY = 'N';

    return temp;
}