#include "MapPoint.h"

MapPoint::MapPoint()
{
    this->name = "UNDEF";
    this->coordX = 0.0;
    this->coordY = 0.0;
    this->symbolX = 'X';
    this->symbolY = 'Y';
}

MapPoint::MapPoint(std::string name, const double longitude, const double latitude)
{
    this->name = name;
    this->coordX = longitude;
    this->coordY = latitude;
    if(longitude > 0.0)
        this->symbolX = 'E';
    else
        this->symbolX = 'W';

    if(latitude > 0.0)
        this->symbolY = 'N';
    else
        this->symbolY = 'S';

}

MapPoint::MapPoint(std::string name, const double longitude, const char symbolX, 
                 const double latitude, const char symbolY)
{
    this->name = name;

    if(longitude > 0.0 && symbolX == 'W')
        this->coordX = -longitude;
    else if (longitude < 0.0 && symbolX == 'E')
        this->coordX = -longitude;
    else
        this->coordX = longitude;
    
    if(latitude > 0.0 && symbolY == 'S')
        this->coordY = -latitude;
    else if (latitude < 0.0 && symbolY == 'N')
        this->coordY = -latitude;
    else
        this->coordY = latitude;

    //powyzszy kod sprawia ze znak zawsze pokrywa sie ze strona swiata

    this->symbolX = symbolX;
    this->symbolY = symbolY;
}

MapPoint::~MapPoint()
{
    std::cout<<"Usuwanie "<<this->name<<std::endl;
}

// MapPoint *construct(std::string name, const double coordX, const double coordY)
// {
//     MapPoint *punkt = new MapPoint;
//     punkt->name = name;
//     punkt->coordX = coordX;
//     punkt->coordY = coordY;
//     if(coordX < 0.0)
//     {
//         punkt->symbolX = 'W';
//     }
//     else
//     {
//         punkt->symbolX = 'E';
//     }

//     if(coordY < 0.0)
//     {
//         punkt->symbolY = 'S';
//     }
//     else
//     {
//         punkt->symbolY = 'N';
//     }

//     return punkt;
// }

void MapPoint::print() const
{
    std::cout << "Wspolrzedne dla " << this->name << ": "
                << fabs(this->coordX) << this->symbolX << ", "
                << fabs(this->coordY) << this->symbolY << std::endl;
}

// MapPoint *construct(std::string name, const double coordX, char symbolX,
//              const double coordY, char symbolY)
// {
//     MapPoint *punkt = new MapPoint;
//     punkt->name = name;
//     punkt->coordX = coordX;
//     punkt->coordY = coordY;
//     if(coordX < 0.0)
//     {
//         punkt->symbolX = symbolX;
//     }
//     else
//     {
//         punkt->symbolX = symbolX;
//     }

//     if(coordY < 0.0)
//     {
//         punkt->symbolY = symbolY;
//     }
//     else
//     {
//         punkt->symbolY = symbolY;
//     }
//     return punkt;
// }

void MapPoint::movePoint(const double shiftX, const double shiftY)
{
    this->coordX += shiftX;
    this->coordY += shiftY;

    if(this->coordX < 0.0)
        this->symbolX = 'W';
    else
        this->symbolX = 'E';

    if(this->coordY < 0.0)
        this->symbolY = 'S';
    else
        this->symbolY = 'N';
}

// void clear(MapPoint *a, MapPoint *b, MapPoint *c)
// {
//     std::cout<<"Usuwanie "<<a->name<<std::endl;
//     delete a;
//     if(b != nullptr)
//     {
//         std::cout<<"Usuwanie "<<b->name<<std::endl;
//         delete b;
//     }

//     if(c != nullptr)
//     {
//         std::cout<<"Usuwanie "<<c->name<<std::endl;
//         delete c;
//     }
// }

std::string MapPoint::getName() const
{
    return this->name;
}

const MapPoint &MapPoint::closestPlace(MapPoint *a, MapPoint *b)
{
    MapDist atar = distance(*this, *a);
    MapDist btar = distance(*this, *b);
    if(atar.angularDistance() >= btar.angularDistance())
    {
        return *b;
    }
    else
    {
        return *a;
    }
}

MapPoint inTheMiddle(MapPoint *a, MapPoint *b, std::string name)
{
    MapPoint point;
    point.name = name;

    point.coordX = (a->coordX + b->coordX)/2;
    point.coordY = (a->coordY + b->coordY)/2;

    if(point.coordX < 0.0)
        point.symbolX = 'W';
    else
        point.symbolX = 'E';

    if(point.coordY < 0.0)
        point.symbolY = 'S';
    else
        point.symbolY = 'N';

    return point;
}