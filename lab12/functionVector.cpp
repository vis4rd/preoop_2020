#include "functionVector.h"


FunctionVector::~FunctionVector()
{
    this->data.clear();
    this->results.clear();
}

void FunctionVector::insert(std::function<double(double)> input)
{
    this->data.push_back(input);
}

double FunctionVector::calc(double x)
{
    this->results.clear();
    this->results.reserve(this->data.size());
    this->results[0] = this->data[0](x);
    unsigned i = 1;
    for(; i < this->data.size(); i++)
    {
        this->results[i] = this->data[i](this->results[i-1]);
    }
    
    return this->results[i-1];
}

double FunctionVector::operator[] (int index)
{
    return this->results[index];
}