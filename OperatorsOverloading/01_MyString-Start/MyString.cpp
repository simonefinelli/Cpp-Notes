#include "MyString.h"
#include <cstring>
#include <iostream>

// No-args constructor
MyString::MyString()
        : str{nullptr} {
    str = new char[1];  // allocate new on the heap
    *str = '\0';
}

// Overloaded constructor
MyString::MyString(const char *s)
        : str {nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s)+1];  // new array of char on the heap
        std::strcpy(str, s);
    }
}

// Copy constructor - deep copy
MyString::MyString(const MyString &source)
        : str{nullptr} {
    str = new char[std::strlen(source.str ) + 1];
    std::strcpy(str, source.str);  // deep copy
}

// Destructor
MyString::~MyString() {
    delete [] str;  // delete memory on the heap
}

// Display method
void MyString::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int MyString::get_length() const { return std::strlen(str); }

// string getter
const char * MyString::get_str() const { return str; }

