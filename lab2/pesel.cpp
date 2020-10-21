#include "pesel.h"

bool PeselValidator(char string[11], int (&output)[11])
{
    int dayCount[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(getPeselLength(string) == 11)
    {
        //RRMMDDXXXPK <- wzor//
        for(int i=0; i<11; i++)
        {
            output[i] = string[i] - '0'; //konwersja char -> int
        }

        int tempMonth = 10*output[2] + output[3];
        int tempDay = 10*output[4] + output[5];
        if(tempMonth > 12 && tempMonth < 21)
            return false;
        else if(tempMonth > 32 && tempMonth < 41)
            return false;
        else if(tempMonth > 52 && tempMonth < 61)
            return false;

        bool isLeap = leapYear(1900 + output[0]*10 + output[1]);
        if(isLeap)
            dayCount[1] += 1; //jesli przestepny, to luty ma 29 dni

        if(tempDay > dayCount[getMonth(output)])
            return false;
        

        //liczba ewidencyjna K:
        int sumaWag = getCtrlNumber(output);
        if(sumaWag != output[10]) // jesli K sie nie zgadza to false
            return false;
        

        //wszystkie warunki sprawdzone, nie ma bledu
        return true;
    }
    else //liczba pesel jest za krotka
    {
        
        return false;
    }
}

void printPesel(int tab[11])
{
    for(int i=0; i<11; i++)
        std::cout<<tab[i];
    std::cout<<"/n";
}

int getCtrlNumber(int tab[11])
{
    int waga[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int sumaWag = 0;
    for(int i=0; i<10; i++)
    {
        sumaWag += waga[i]*tab[i];
    }
    sumaWag %= 10;
    sumaWag = 10 - sumaWag;
    sumaWag %= 10;
    return sumaWag;
}

std::string sex(int tab[11])
{
    if(tab[9]%2==0)
        return "Kobieta";
    else
        return "Mezczyzna";
}

int getDay(int tab[11])
{
    return 10*tab[4]*tab[5];
}

int getMonth(int tab[11])
{
    int tempMonth = 10*tab[2] + tab[3];
    if(tempMonth > 20 && tempMonth <= 32)
        return tempMonth - 20; //2000-2099
    else if(tempMonth > 40 && tempMonth <= 52)
        return tempMonth - 40; //2100-2199
    
    return tempMonth; //1900-1999
}

int getYear(int tab[11])
{
    int tempMonth = 10*tab[2] + tab[3];

    if(tempMonth > 20 && tempMonth <= 32)
    {
        return 2000 + tab[0]*10 + tab[1]; //2000-2099
    }
    else if(tempMonth > 40 && tempMonth <= 52)
    {
        return 2100 + tab[0]*10 + tab[1]; //2100-2199
    }

    return 1900 + tab[0]*10 + tab[1]; //1900-1999
}

bool leapYear(int year) 
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int getPeselLength(char tab[11])
{
    int suma=0;
    for(int i=0; i<11; i++)
    {
        if(tab[i]>='0' && tab[i]<='9')
            suma++;
    }
    return suma;
}