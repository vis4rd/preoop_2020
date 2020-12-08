#include "Vector2D.h"

//public
int Vector2D::count = 0;

Vector2D::Vector2D(std::string name) : Vector2D(name, 0.0, 0.0)
{

}

Vector2D::Vector2D(const Vector2D &original) 
: Vector2D(original.name, original._x, original._y)
{
    this->print("--- kopiowanie ");
}

Vector2D::Vector2D(Vector2D &&source)
{
    this->count++;
    source.print("--- przenoszenie ");
    std::__exchange(source._x, 0.0);
    std::__exchange(source._y, 0.0);
    std::move(source.name);
} 

Vector2D::~Vector2D()
{
    count--;
}

Vector2D Vector2D::fromCarthesian(std::string name, double x, double y)
{
    return Vector2D(name, x, y);
}

Vector2D Vector2D::fromCarthesian(double x, double y)
{
    return Vector2D::fromCarthesian("Vx", x, y);
}

Vector2D Vector2D::fromPolar(std::string name, double r, double deg)
{
    return Vector2D(name, r*cos(deg*M_PI/180.0), r*sin(deg*M_PI/180.0));
}

void Vector2D::print(std::string prefix) const
{
    std::cout << prefix << this->name << "=(" << this->_x << ", " << this->_y << ")" << std::endl;
}

double Vector2D::dot(Vector2D two) const
{
    return (this->_x * two._x) + (this->_y * two._y);
}

Vector2D Vector2D::add(Vector2D two) const
{
    return Vector2D("Vx", this->_x + two._x, this->_y + two._y);
}

//private

Vector2D::Vector2D(std::string name, double x, double y) 
: name(name), _x(x), _y(y)
{
    this->count++;
}
