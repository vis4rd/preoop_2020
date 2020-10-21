#pragma once

#include <iostream>

bool PeselValidator(char [11], int (&) [11]);
void printPesel(int[11]);
int getCtrlNumber(int[11]);
std::string sex(int[11]);
int getDay(int[11]);
int getMonth(int[11]);
int getYear(int[11]);

bool leapYear(int);
int getPeselLength(char[11]);