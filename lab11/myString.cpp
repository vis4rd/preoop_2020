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
    this->text = std::__exchange(source.text, nullptr);
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

String String::operator+ (const char other) const
{
	char *temp = new char[2];
	temp[0] = other; temp[1] = '\0';
	String result(temp);
	delete temp;
	return result;
}

String String::operator+ (const char other[]) const
{
	String result;
	result.size = this->getSize() + strlen(other);
	result.text = new char[ result.size ];
	strcpy(result.text, this->getText());
	strcat(result.text, other);
	return result;
}

String String::operator+ (const String &second) const
{
	String result;
	result.size = this->getSize() + second.getSize();
	result.text = new char[ result.size ];
	strcpy(result.text, this->getText());
	strcat(result.text, second.getText());
	return result;
}

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

String &String::operator* (int right)
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
    if(this->size != static_cast<int>(strlen(result)))
    {
    	this->size = strlen(result);
    }
    
    this->text = new char[this->size];
    strcpy(this->text, result);
}

void String::setSize(int size)
{
	if(size < 0)
		size = -size;
	this->size = size;
}

//funkcje

String operator+ (const char first[], const String second)
{
	String result(second + first); //200iq
	return result;
}