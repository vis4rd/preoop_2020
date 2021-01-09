#include "myString.h"

using namespace mystring;

String::String(const char *input)
{
    this->size = strlen(input);
    this->text = new char[this->size];
    strcpy(this->text, input);
}

String:: String(const String &origin)
{
    this->size = origin.size;
    this->text = new char[this->size];
    strcpy(this->text, origin.text);
}

String::String(String &&source)
{
    this->size = std::__exchange(source.size, 0);
    this->text = std::move(source.text);
}

String::~String()
{
    if(!this->text)
        delete[] this->text;
}

String::operator char*() const
{
    return this->text;
}

void String::print(const char* prefix) const
{
    std::cout << prefix << this->text << std::endl;
}

String &String::operator+ (String &right) const
{
    char temp_text[this->size + right.size];
    strcpy(temp_text, this->text);
    strcat(temp_text, right.text);
    String result(temp_text);
    return result;
}

String &String::operator+ (const char *right) const
{
    char temp_text[this->size + strlen(right)];
    strcpy(temp_text, this->text);
    strcat(temp_text, right);
    String result(temp_text);
    return result;
}

String &String::operator+ (const char right) const
{
    char temp_text[this->size + 1];
    strcpy(temp_text, this->text);
    temp_text[this->size] = right;
    String result(temp_text);
    return result;
}

// String String::operator= (String right)
// {
//     if(this->text != nullptr)
//         delete[] this->text;

//     this->text = std::move(right.text);
//     this->size = std::__exchange(right.size, 0);
//     return *this;
// }

String &String::operator= (const char *right)
{
    if(strcmp(this->text, right) != 0)
    {
        delete[] this->text;
        this->text = new char[strlen(right)];
        this->size = strlen(right);
        strcpy(this->text, right);
    }
    return *this;
}

String String::operator* (int right)
{
    char *temp = nullptr; 
    strcpy(temp, this->text);
    delete[] this->text;
    this->text = new char[right * this->size];
    for(int i=0; i<right; i++)
        strcat(this->text, temp);

    return *this;
}

bool String::operator== (const String &right)
{
    return !strcmp(this->text, right.text);
}

bool String::operator== (const char *data)
{
    return !strcmp(this->text, data);
}

const char *String::getText() const
{
    return this->text;
}

const int String::getSize() const
{
    return this->size;
}

void String::setText(char result[])
{
    if(this->text != nullptr)
        delete this->text;
    int new_len = strlen(result);
    this->text = new char[new_len];
    strcpy(this->text, result);
    this->size = new_len;
}

String operator+ (const char left[], String right)
{
    char new_text[strlen(left) + right.getSize()];
    strcat(new_text, left);
    strcat(new_text, right.getText());
    String result(new_text);
    return result;
}   