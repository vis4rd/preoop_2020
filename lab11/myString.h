#pragma once

#include <cstring>
#include <iostream>

namespace mystring
{

class String
{
public:
    //String();
    explicit String(const char *input); //zwykly konstruktor
    String(const String &origin);
    String(String &&source);
    ~String();

    operator char*() const; //konwersja String - char*

    void print(const char* prefix) const;

    String &operator+ (String &right) const;
    String &operator+ (const char *right) const;
    String &operator+ (const char right) const;
    //String operator= (String right);
    String &operator= (const char *right);
    String operator* (int right); 
    bool operator== (const String &right);
    bool operator== (const char *data);

    const char *getText() const;
    const int getSize() const;
    void setText(char result[]);

protected:

private:
    char *text;
    int size;
};

String operator+ (const char left[], String right);

}

