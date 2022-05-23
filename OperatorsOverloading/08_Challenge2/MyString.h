#ifndef MYSTRING_START_MYSTRING_H
#define MYSTRING_START_MYSTRING_H

#include <iostream>

class MyString {
    // overload operator functions as global
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
    friend std::istream &operator>>(std::istream &in, MyString &rhs);
    friend MyString operator-(const MyString &obj);
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend bool operator!=(const MyString &lhs, const MyString &rhs);
    friend bool operator<(const MyString &lhs, const MyString &rhs);
    friend bool operator>(const MyString &lhs, const MyString &rhs);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    friend MyString &operator+=(MyString &lhs, const MyString &rhs);
    friend MyString operator*(const MyString &lhs, unsigned n);
    friend MyString &operator*=(MyString &lhs, unsigned n);
    friend MyString &operator++(MyString &obj); // pre-increment
    friend MyString operator++(MyString &obj, int); // post-increment - `int` only for placeholder

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

    // overload operator functions as member-methods
    MyString &operator=(const MyString &rhs);      // Copy assignment
    MyString &operator=(MyString &&rhs) noexcept;  // Move assignment

};

#endif // MYSTRING_START_MYSTRING_H
