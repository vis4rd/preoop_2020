#include "studList.h"

void initList(StudList *target, const char name[])
{
    target->head = NULL;
    target->tail = NULL;

    unsigned length = strlen(name) + 1;//sprawdzamy dlugosc nazwy listy
    target->name = new char[length];//i alokujemy odpowiednio pamiec
    strcpy(target->name,name);
}

void prepend(StudList *list, const char nodeName[])
{
    Node *newNode = new Node;
    unsigned nameLength = strlen(nodeName) + 1;
    newNode->name = new char[nameLength];
    strcpy(newNode->name, nodeName);
    newNode->next = NULL;

    if(list->head == NULL)//jesli to pierwszy element to tail tez na to wskazuje
    {
        list->tail = newNode;
    }
    else //nie jest to pierwszy element
    {
        newNode->next = list->head;//head staje sie nastepnym elementem
    }
    list->head = newNode;//nowy element staje sie headem
}

bool isEmpty(const StudList *list)
{
    if(list->head == NULL)
        return true;
    else
        return false;
}

void print(const StudList *list)
{
    std::cout << list->name << " = [";
    if(isEmpty(list))//lista jest pusta wiec wyswietlamy puste nawiasy
    {
        std::cout << " ]" << std::endl;
    }
    else//wyswietlamy zawartosc
    {
        Node *iter = list->head;
        while(iter != NULL)
        {
            std::cout << iter->name << " ";
            iter = iter->next;
        }
        std::cout << "]" << std::endl;
    }
}

void removeLast(StudList *list)
{
    if(isEmpty(list))//lista pusta, nic nie robimy
        return;
    else//usuwamy ostatni element
    {
        delete[] list->tail->name;
        if(list->head == list->tail)//jesli jest tylko jeden element
        {
            delete list->head;
            list->tail = NULL;
            list->head = NULL;
        }
        else//wiecej elementow
        {
            Node *iter = list->head;
            while(iter->next != list->tail)//szukamy nowego ostatniego elementu
            {
                iter = iter->next;
            }
            delete list->tail;
            list->tail = iter;
            list->tail->next = NULL;
        }
    }
}

void clearList(StudList *list)
{
    if(isEmpty(list))//pusta lista to nic nie trzeba robic
        return;
    else//usuwamy elementy
    {
        while(list->head != NULL)
        {
            removeLast(list);
        }
    }
}

void removeList(StudList *list)
{
    if(!isEmpty(list)) //usuwana lista jeszcze ma elementy!
    {
        clearList(list);    
    }
    std::cout<<"Kasowanie " << list->name << std::endl;
    delete[] list->name;
}