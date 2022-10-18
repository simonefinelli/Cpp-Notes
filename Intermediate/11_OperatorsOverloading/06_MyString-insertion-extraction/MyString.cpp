#include <cstring>
#include <iostream>
#include "MyString.h"

/// Operations Overloading

// Stream Insertion operator (<<)
std::ostream &operator<<(std::ostream &os, const MyString &rhs) {  // os -> output stream
    os << rhs.str;  // chose what we want to display
    // os << rhs.get_str(); // if not friend function
    return os;  // return output stream reference (to allow chaining of multiple insertions)
}

// Stream Extraction operator (>>)
std::istream &operator>>(std::istream &in, MyString &rhs) {  // in -> input stream
                                                             // no const because we modify rhs object (depending on the data we want to read)
    char *buff = new char[1000];
    in >> buff;  // store the data form the stream (or directly on the object)
    rhs = MyString{buff};  // copy or move assignment (if we have)
    delete [] buff;
    return in; // return input stream reference (to allow chaining of multiple insertions)
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
