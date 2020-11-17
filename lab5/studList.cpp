#include "studList.h"

void initList (StudList* list,const char* name)
{
 list->head = NULL;
 list->tail = NULL;
 list->name = mycopy(name);
}

bool isEmpty (const StudList* list) {
  return !(list->head) && !(list->tail);
}

void append(StudList* list,const char* name) {
  if (*name) {
      Element *student = new Element;
      student->name = mycopy(name);
      student->next = NULL;
      if (isEmpty(list)) {
         list->head =list->tail = student;
      } else {
         list->tail->next = student;
         list->tail = student;
      }
  }
}

void print(const StudList* list) {
   if(list){
    Element *tmp =list->head;
     std::cout << list->name << " = ";
    while (tmp != NULL) {
        std::cout << "<" << tmp->name << ">";
        if (tmp->next != NULL) {
            std::cout << " ";
        }
        tmp = tmp->next;
    }
    std::cout /*<< "]"*/ << std::endl;
 }
 else std::cout << "Lista usunieta\n";
}

void removeFirst(StudList* list) {
  if (list->head){
    if (list->head == list->tail) {
        delete[] list->head->name;
        delete list->head;
        list->head = list->tail = NULL;
    } 
    else {
        Element *tmp = list->head;
        list->head = tmp->next;
        delete[] tmp->name;
        delete tmp;
    }
  }
}

void clearList (StudList* list) {
  while (list->head)
     removeFirst(list);
}

void removeList (StudList* list) {
    clearList(list);
    std::cout << "Kasowanie " <<list->name << std::endl;
    delete[] list->name;
    list=nullptr;
}

char *mycopy(const char *string)
{
    int length = mystrlen(string);//uzyskujemy dlugosc stringa
    char *target = new char[length];//alokacja pamieci

    const char *i;
    char* j;
    for(i = string, j = target; i<string+length; i++, j++)
    {
        *j = *i;//zapelnianie tablicy
    }
    return target;
}

int mystrlen (const char* string)
{
    const char *i;
    for(i = string; (*i)!='\0'; i++);//liczenie dlugosci stringa
    return i - string;//zwraca dlugosc - roznice wartosci adresow wskaznikow
}