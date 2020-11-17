#include "mystr.h"

bool findSep(char token, char *string)
{
    char *iter = string;
    while(iter != NULL)
    {
        if(token == *iter)
            return true;
        iter++;
    }
    return false;
}

void initMyString(MyString *node, const char *text, const char *tokens)
{
    node->text = mycopy(text);
    if(tokens == nullptr)
        node->tokens = NULL;
    else
        node->tokens = mycopy(tokens);
    node->begin = node->text;
    node->end = node->text + mystrlen(node->text) - 1;
    node->next = node->text;
}

char *mystrtok(MyString *node)
{
    if(node->next == NULL)//nie ma nic do dzielenia (wynika z konca tej funkcji)
        return "\0";

    char *result = node->next;
    char *iter = node->next;
    char *jter = node->tokens;
    bool finished = false;  //wskazuje, czy skonczylismy iterowac po znalezionych
                            //...separatorach. Zazwyczaj separator jest tylko jeden miedzy
                            //...slowami, wiec od razu zwracamy finished = true

    //czyli finished nie wskazuje, czy znaleziono separator!  

    bool found = false; //informuje, czy znaleziono nastepny separator              

    while(iter != node->end)
    {
        jter = node->tokens;
        while(jter != node->tokens+mystrlen(node->tokens))//sprawdzamy dla wszystkich tokenow
        {
            if((char)*iter == (char)*jter)//jesli token sie pojawia
            {
                found = true;
                *iter = '\0';//zastepujemy separator znakiem konca stringa
                node->next = iter+1;//ustawiamy next na nastepny string
                if(*(node->next) == *jter)
                    finished = false;
                else
                    finished = true;
                break;
            }
            jter++;
        }
        if(finished) 
            break;//wydostajemy sie z petli glownej
        iter++;
    }
    if(found == false)//nie ma juz nastepnego wyrazu, bo nie ma separatora
        node->next = NULL;
    
    return result;
}

char *mystrcat(char *string, const char *text, char sep)
{
    int length1 = mystrlen(string);
    int length2 = mystrlen(text);
    int suma = (sep == '\0') ? length1+length2 : length1+length2+1;
    char *result = new char[suma];

    const char *i;
    char* j;
    for(i = string, j = result; i<string+length1; i++, j++){
        *j = *i;
    }

    if(sep != '\0'){
        *j = sep;
        j+=1;
    }

    for(i = text; i<text+suma-length1; i++, j++){
        *j = *i;
    }
    
    return result;
}

void addSep(MyString *target, const char *tokens)
{
    target->tokens = mycopy(tokens);
}

void split2list(StudList *list, MyString *buffer)
{
    char *newstring;
    while(*newstring!='\0')
    {
        newstring = mystrtok(buffer);
        append(list, newstring);
    }
}

void removeMyString(MyString *node)
{
    delete[] node->text;
    delete[] node->tokens;
    delete node;
}

//funkcja pomocnicza do strtok()
/*bool isSeparator(char symbol, char *tokens)
{
    //symbol jest tutaj jako oryginalny argument
    //...ktory zostanie zmieniony
    char *iter = tokens;
    while(iter != tokens+mystrlen(tokens))
    {
        if(*iter == symbol)
        {
            return true;
        }
        iter++;
    }
    return false;
}*/
//projekt porzucony

char *gettok(MyString *node, int n)
{
    char *newstring;
    int count = 0;
    while(*newstring!='\0')
    {
        count++;
        newstring = mystrtok(node);
        if(count == n)
            break;
    }
    return newstring;
}