#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char* value;
    void copy(const String& other)
    {
        this -> value = new char[strlen(other.value) + 1];
        strcpy(this -> value, other.value);
    }
    void erase()
    {
        delete [] value;
    }
public:
    String()
    {
        this -> value = new char[1];
        strcpy(this -> value, "");
    }
    String(const char* _value)
    {
        this -> value = new char[strlen(value) + 1];
        strcpy(this -> value, _value);
    }
    String(const String& other)
    {
        this -> copy(other);
    }
    String operator = (const String& other)
    {
        if(this != &other)
        {
            this -> erase();
            this -> copy(other);
        }
        return *this;
    }
    void print() const
    {
        cout << this -> value << endl;
    }
    ~String()
    {
        this -> erase();
    }
};
