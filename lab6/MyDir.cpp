#include "MyDir.h"

bool initDir(MyDir target, std::string name)
{
    if(isNameOK(name))
        target.name.insert(0, name);
    else
        return false;
    target.parent = NULL;
    target.children = NULL;
    target.childCount = 0;
    return true;
}

void printDir(MyDir target)
{
    std::cout<<target.name<<std::endl;
    MyDir **iter = target.children;
    if(iter != NULL)
    {
        while(*iter != NULL)
        {
            std::cout<<"  ";
            printDir(**iter);
            (*iter)++;
        }
    }
}

MyDir *addDir(MyDir parent, std::string childName)
{
    MyDir *element = new MyDir;
    if(!initDir(*element, childName))
    {
        delete element;
        return NULL;
    }
    element->parent = &parent;

    int length = tabLength(parent.children);
    if(length != 0)//tablica wskaznikow nie jest pusta
    {
        MyDir *temp[length];//tymczasowe przechowanie tablicy wskaznikow
        for(int i=0; i<length; i++)
            temp[i] = parent.children[i];//wypelnianie
        delete[] parent.children;//usuwanie tablicy
        MyDir **changed = new MyDir*[length+1];//nowa tablica o wiekszej dlugosci
        for(int i=0; i<length; i++)
            changed[i] = temp[i];//wypelnianie z tymczasowej

        parent.children = changed;//przypisanie z powrotem do struktury
        parent.children[length] = element;//dodanie nowego elementu
    }
    else//tablica wskaznikow pusta
    {
        parent.children = new MyDir*[1]; 
        parent.children[0] = element;
    }
    return element;

}

MyDir *addDir(MyDir parent, MyDir child)
{
    child.parent = &parent;
    int length = tabLength(parent.children);
    if(length != 0)//tablica wskaznikow nie jest pusta
    {
        MyDir *temp[length];//tymczasowe przechowanie tablicy wskaznikow
        for(int i=0; i<length; i++)
            temp[i] = parent.children[i];//wypelnianie
        delete[] parent.children;//usuwanie tablicy
        MyDir **changed = new MyDir*[length+1];//nowa tablica o wiekszej dlugosci
        for(int i=0; i<length; i++)
            changed[i] = temp[i];//wypelnianie z tymczasowej

        parent.children = changed;//przypisanie z powrotem do struktury
        parent.children[length] = &child;//dodanie nowego elementu
    }
    else//tablica wskaznikow pusta
    {
        parent.children = new MyDir*[1]; 
        parent.children[0] = &child;
    }
    return &child;
}

void clearDir(MyDir *target)
{
    int length = tabLength(target->children);
    for(int i=0; i<length; i++)
        clearDir(target->children[i]);
    for(int i=0; i<length; i++)
        delete target->children[i];
    delete[] target->children;
}

int tabLength(MyDir **target)
{
    MyDir **iter = target;
    if(target == NULL)
        return 0;
    else
    {
        while(iter!=NULL)
            iter++;
        return iter-target;
    }
}

bool isNameOK(std::string target)
{
    if(target.length() < 1 || target.length() > 10)
        return false;
    
    return true;
}