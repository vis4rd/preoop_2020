#include "funkcje.h"

int silnia(int value)
{
    if(value < 0)
    {
        std::cout << "brak rozwiązania ";
        return -1;
    }
    int wynik = 1;
    for(int i=1; i<=value; i++)
    {
        wynik *= i;
    }
    return wynik;
}

int silnia_rec(int value)
{
    if(value < 0)
    {
        std::cout << "brak rozwiązania ";
        return -1;
    }
    else
    {
        if(value == 0 || value == 1)
        {
            return 1;
        }
        return silnia_rec(value-1) * value;
    }
}

void wypisz(double tab[], const int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout<< tab[i] << " ";
    }
    std::cout << std::endl;
}

void powiel(double tab[], double factor, const int size)
{
    for(int i = 0; i < size; i++)
    {
        tab[i] *= factor;
    }
}

double suma(double tab[], const int size)
{
    double sum = 0.0;
    for(int i = 0; i < size; i++)
    {
        sum += tab[i];
    }
    return sum;
}

double srednia(double tab[], const int size)
{
    std::cout << std::setprecision(9);
    return (suma(tab, size) / size);
}