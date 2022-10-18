#ifndef MYSTRING_START_MYSTRING_H
#define MYSTRING_START_MYSTRING_H

#include <iostream>

class MyString {
    // overload operator functions as global
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
    friend std::istream &operator>>(std::istream &in, MyString &rhs);

private:
    char *str;  // pointer to a char[] that holds a C-style string

public:
    // constructors
    MyString();                        // No-args constructor
    MyString(const char *s);           // Overloaded constructor
    MyString(const MyString &source);  // Copy constructor
    MyString( MyString &&source);      // Move constructor
    ~MyString();                       // Destructor

    // methods
    void display() const;
    int get_length() const;
    const char *get_str() const;

    // overload operator functions as global member-methods
    MyString &operator=(const MyString &rhs);      // Copy assignment
    MyString &operator=(MyString &&rhs) noexcept;  // Move assignment
    MyString operator-() const;
    bool operator==(const MyString &rhs) const;
    bool operator!=(const MyString &rhs) const;
    bool operator<(const MyString &rhs) const;
    bool operator>(const MyString &rhs) const;
    MyString operator+(const MyString &rhs) const;
    MyString &operator+=(const MyString &rhs);
    MyString operator*(unsigned n) const;
    MyString &operator*=(unsigned n);
    MyString &operator++(); // pre-increment
    MyString operator++(int); // post-increment - `int` only for placeholder

    // TIP:
    //  remember that:
    //   - MyString operator return the object by VALUE
    //   - MyString &operator return the object by REFERENCE
};

#endif // MYSTRING_START_MYSTRING_H
