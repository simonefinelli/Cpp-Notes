#include <iostream>
#include <cstring>
#include "MyString.h"

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
    std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
MyString::MyString(MyString &&source)
        : str{source.str} {
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
}

// Destructor
MyString::~MyString() {
//    if (str == nullptr) {
//        std::cout << "Calling destructor for MyString : nullptr" << std::endl;
//    } else {
//        std::cout << "Calling destructor for MyString : " << str << std::endl;
//    }
    delete [] str;
}

// Copy assignment
MyString &MyString::operator=(const MyString &rhs) {  // we have to make deep copy for each raw pointers (in this case only one)
    // TIP: `this` is the left side object
    std::cout << "Using copy assignment" << std::endl;
    if (this == &rhs)  // check if it is a self-assignment comparing the addresses
        return *this;  // de-referencing - we return the address not the pointer it-self.

    delete [] this->str;  // to make a deep copy `this` object must be overwritten, so we need to de-allocate anything it refers to on the heap.
    // if we don't do this we have a memory leak (we'll orphan the memory on the heap)
    str = new char[std::strlen(rhs.str) + 1];  // allocate new memory on the heap
    std::strcpy(this->str, rhs.str);  // copy the data

    return *this;  // returning `this` we can support chain assignment
}

// Move assignment
MyString &MyString::operator=(MyString &&rhs) noexcept {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)  // check if it is a self-assignment
        return *this;

    delete [] this->str;  // deallocate current storage on the heap (to prevent memory leak)

    this->str = rhs.str;  // steal the pointer

    rhs.str = nullptr;  // null out the rhs object (to prevent memory leak)
    // indeed, when it gets destroyed by the destructor, no data will lose the pointing (safe)

    return *this;  // returning `this` we can support chain assignment
}

// Display method
void MyString::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int MyString::get_length() const { return std::strlen(str); }

// string getter
const char * MyString::get_str() const { return str; }

/// Operations Overloading

// Stream Insertion operator (<<)
std::ostream &operator<<(std::ostream &os, const MyString &rhs) {
    os << rhs.str;
    return os;
}

// Stream Extraction operator (>>)
std::istream &operator>>(std::istream &in, MyString &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = MyString{buff};  // copy or move assignment
    delete [] buff;
    return in;
}

// Lowercase
MyString MyString::operator-() const {
    unsigned str_len = std::strlen(str);
    char *buff = new char[str_len + 1];
    std::strcpy(buff, str);
    for (size_t i=0; i < str_len; i++)
        buff[i] = static_cast<char>(std::tolower(buff[i]));
    MyString s {buff};
    delete [] buff;
    return s;
}

// Equality
bool MyString::operator==(const MyString &rhs) const {
    return std::strcmp(str, rhs.str) == 0;
}

// Inequality
bool MyString::operator!=(const MyString &rhs) const {
    return std::strcmp(str, rhs.str) != 0;
}

// Less than - lexically
bool MyString::operator<(const MyString &rhs) const {
    return std::strcmp(str, rhs.str) < 0;
}

// Greater than - lexically
bool MyString::operator>(const MyString &rhs) const {
    return std::strcmp(str, rhs.str) > 0;
}

// Concatenation
MyString MyString::operator+(const MyString &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    MyString s {buff};
    delete [] buff;
    return s;
}

// Concatenation and assignment
MyString &MyString::operator+=(const MyString &rhs) {
    *this = *this + rhs;  // copy/move assignment
    return *this;
}

// Multiplication
MyString MyString::operator*(unsigned n) const {
    char *buff = new char[std::strlen(str) * n + 1];
    std::strcpy(buff, "");  // initialization: avoid invalid characters
    for (size_t i = 0; i < n; i++)
        std::strcat(buff, str);
    MyString s {buff};
    delete [] buff;
    return s;

    // reusing concat overload operator - more inefficient (lots of move assignments) but more readable
//    MyString temp;
//    for (size_t i=0; i< n; i++)
//        temp = temp + *this;
//    return temp;
}

// Multiplication and assignment
MyString &MyString::operator*=(unsigned n) {
    *this = *this * n;  // copy/move assignment
    return *this;
}

// Pre-increment
MyString &MyString::operator++() {
    // make uppercase
//    unsigned str_len = std::strlen(str);
//    char *buff = new char[str_len + 1];
//    std::strcpy(buff, str);
//    for (size_t i=0; i < str_len; i++)
//        buff[i] = static_cast<char>(std::toupper(buff[i]));
//    *this = MyString {buff};  // copy/move assigment
//    delete [] buff;
//    return *this;

    // more efficient version
    for (size_t i=0; i<std::strlen(str); i++)
        str[i] = static_cast<char>(std::toupper(str[i]));
    return *this;
}

// Post-increment
MyString MyString::operator++(int) {
    MyString temp {*this};  // make a copy - copy constructor
    operator++();  // calling operator++(int) (post-increment -> this function) creates an infinite loop
    return temp;  // return the old value
}

/// Operations Overloading End