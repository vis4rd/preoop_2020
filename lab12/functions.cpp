#include "functions.h"

Linear::Linear(double a, double b)
: a(a), b(b)
{

}

Linear::~Linear()
{

}

double Linear::operator() (double x) const
{
    return this->a * x + this->b;
}

std::ostream &operator<< (std::ostream &output, const Linear &target)
{
    output << target.a << " * x + " << target.b; //tutaj ma sie wyswietlac x, a nie x^2 dla funkcji liniowej??
    return output;
}

Sqrt::Sqrt()
{

}

Sqrt::~Sqrt()
{

}

double Sqrt::operator() (double x) const
{
    return sqrt(x);
}

Sin::Sin(double a, double b)
{
    this->fun = Linear(a, b);
}

Sin::~Sin()
{

}

double Sin::operator() (double x) const
{
    return sin(this->fun(x));
}