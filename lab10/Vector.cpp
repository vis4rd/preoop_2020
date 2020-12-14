#include "Vector.h"

Vector::Vector(int size)
{
    this->skladowe = new double[size];
    for(int i=0; i<size; i++)
        this->skladowe[i] = 0.0;

    this->size = size;
}

Vector::Vector(Vector &origin)
{
    this->skladowe = new double[origin.size];
    for(int i=0; i<origin.size; i++)
        this->skladowe[i] = origin.skladowe[i];

    this->size = origin.size;
}

Vector::Vector(Vector &&source)
{
    this->size = std::__exchange(source.size, 0);
    this->skladowe = std::__exchange(source.skladowe, nullptr);
}

Vector::~Vector()
{
    delete this->skladowe;
}

Vector::operator double() const
{
    return this->norm();
}

double Vector::dot(const Vector &one, const Vector &two)
{
    double temp_sum = 0.0;

    int smaller = (one.size < two.size) ? one.size : two.size;

    for(int i=0; i<smaller; i++)
    {
        temp_sum += one.skladowe[i] * two.skladowe[i];  
    }

    return temp_sum;
}

Vector Vector::sum(const Vector &one, const Vector &two)
{

    int greater = (one.size > two.size) ? one.size : two.size;
    Vector result(greater);

    for(int i=0; i<greater; i++)
    {
        if(i >= one.size)
            result.skladowe[i] = two.skladowe[i];
        else if(i >= two.size)
            result.skladowe[i] = one.skladowe[i];
        else
            result.skladowe[i] = one.skladowe[i] + two.skladowe[i];
    }

    return result;
}

Vector Vector::sum(const Vector &one, const double two)
{
    Vector result(one.size);
    for(int i=0; i<one.size; i++)
    {
        result.skladowe[i] = one.skladowe[i] + two;
    }

    return result;
}

double Vector::norm() const
{
    double temp_sum = 0.0;

    for(int i=0; i<this->size; i++)
        temp_sum += (this->skladowe[i]) * (this->skladowe[i]);
    
    return sqrt(temp_sum);
}

double &Vector::at(int index)
{
    return this->skladowe[index];
}

void Vector::print(std::string prefix) const
{
    std::cout << prefix << "(";

    if(size != 0)
    {
        std::cout << this->skladowe[0];
        for(int i=1; i<this->size; i++)
            std::cout << ", " << this->skladowe[i];
    }

    std::cout << ") " << std::endl;
}