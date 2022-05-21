#include "MyString.h"
#include <cstring>
#include <iostream>

/// Operations Overloading

/*
 * Note that these are simple methods and not member class method, indeed
 * we cannot start with MyString::...
 */

// Equality
bool operator==(const MyString &lhs, const MyString &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Lowercase
MyString operator-(const MyString &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i=0; i<std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    MyString temp {buff};
    delete [] buff;
    return temp;
}

// Concatenation
MyString operator+(const MyString &lhs, const MyString &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    MyString temp {buff};
    delete [] buff;
    return temp;
}
/// Operations Overloading End

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
        : str(source.str) {
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
    std::cout << "Copy assignment" << std::endl;
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

