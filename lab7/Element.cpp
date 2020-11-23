#include "Element.h"

Element::Element()
{
    this->next = NULL;
    this->name = NULL;
}

Element::Element(const char name[])
{
    this->next = NULL;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Element::~Element()
{
    if(this->name != NULL)
    {
        std::cout<<"Destruktor Element: "<<this->name<<std::endl;
        delete[] this->name;
        this->name = NULL;
    }
}

const char *Element::getName() const
{
    return this->name;
}

void Element::printName() const
{
    std::cout<<this->name;
}