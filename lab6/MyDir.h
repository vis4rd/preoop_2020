#pragma once

#include <iostream>

typedef struct MyDir
{
    std::string name;
    struct MyDir *parent;
    struct MyDir **children;
    int childCount;
}MyDir; 

bool initDir(MyDir, std::string);
void printDir(MyDir);
MyDir *addDir(MyDir, std::string);
MyDir *addDir(MyDir parent, MyDir child);
void clearDir(MyDir *);
int tabLength(MyDir **);
bool isNameOK(std::string);