#include "studList.h"

StudList::StudList()
{
    this->name = NULL;
    this->head = NULL;
    this->tail = NULL;
}

StudList::StudList(const char name[])
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->head = NULL;
    this->tail = NULL;
}

StudList::~StudList()
{
    std::cout<<"Destruktor StudList: "<<this->getName()<<std::endl;
    this->removeList();
}

/*void initList(StudList *target, const char name[])
{
    target->head = NULL;
    target->tail = NULL;

    unsigned length = strlen(name) + 1;//sprawdzamy dlugosc nazwy listy
    target->name = new char[length];//i alokujemy odpowiednio pamiec
    strcpy(target->name,name);
}*/

void StudList::prepend(const char elementName[])
{
    Element *newElement = new Element(elementName);
    newElement->next = NULL;

    if(this->head == NULL)//jesli to pierwszy element to tail tez na to wskazuje
    {
        this->tail = newElement;
    }
    else //nie jest to pierwszy element
    {
        newElement->next = this->head;//head staje sie nastepnym elementem
    }
    this->head = newElement;//nowy element staje sie headem
}

void StudList::prepend(Element *element)
{
    if(this->head == NULL)//jesli to pierwszy element to tail tez na to wskazuje
    {
        this->tail = element;
        element->next = NULL;
    }
    else //nie jest to pierwszy element
    {
        element->next = this->head;//head staje sie nastepnym elementem
    }
    this->head = element;//nowy element staje sie headem
}

const Element *StudList::getHead() const
{
    return this->head;
}

const Element *StudList::getTail() const
{
    return this->tail;
}

Element *StudList::getLast()
{
    if(this->isEmpty())
        return NULL;

    Element *iter = this->head;
    Element *result = this->tail;
    if(iter != this->tail)
    {
        while(iter->next != this->tail)//szukamy przedostatniego elementu
            iter = iter->next;

        iter->next = NULL;
        
        this->tail = iter;//teraz bedzie to ostatni element
    }
    else//head == tail
    {
        iter->next = NULL;
        this->head = NULL;
        this->tail = NULL;
    }
    return result;
}

const char *StudList::getName() const
{
    return this->name;
}

bool StudList::isEmpty() const
{
    if(this->head == NULL)
        return true;
    else
        return false;
}

void StudList::print() const
{
    std::cout << this->name << " = [";
    if(this->isEmpty())//lista jest pusta wiec wyswietlamy puste nawiasy
    {
        std::cout << " ]" << std::endl;
    }
    else//wyswietlamy zawartosc
    {
        Element *iter = this->head;
        while(iter != NULL)
        {
            std::cout << iter->getName() << " ";
            iter = iter->next;
        }
        std::cout << "]" << std::endl;
    }
}

void StudList::removeLast()
{
    if(this->isEmpty())//lista pusta, nic nie robimy
        return;
    else//usuwamy ostatni element
    {
        if(this->head == this->tail)//jesli jest tylko jeden element
        {
            delete this->head;
            this->tail = NULL;
            this->head = NULL;
        }
        else//wiecej elementow
        {
            Element *iter = this->head;
            while(iter->next != this->tail)//szukamy nowego ostatniego elementu
            {
                iter = iter->next;
            }
            delete this->tail;
            this->tail = iter;
            this->tail->next = NULL;
        }
    }
}

void StudList::clearList()
{
    if(this->isEmpty())//pusta lista to nic nie trzeba robic
        return;
    else//usuwamy elementy
    {
        while(this->head != NULL)
        {
            this->removeLast();
        }
    }
}

void StudList::removeList()
{
    if(!this->isEmpty()) //usuwana lista jeszcze ma elementy!
    {
        this->clearList();    
    }
    std::cout<<"Kasowanie " << this->name << std::endl;
    delete[] this->name;
}