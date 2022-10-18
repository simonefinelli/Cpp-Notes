#ifndef MYSTRING_START_MYSTRING_H
#define MYSTRING_START_MYSTRING_H


class MyString
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    MyString();                            // No-args contstructor
    MyString(const char *s);               // Overloaded contstructor
    MyString(const MyString &source);      // Copy constructor
    ~MyString();                           // Destructor
    void display() const;
    int get_length() const;                // getters
    const char *get_str() const;
};


#endif // MYSTRING_START_MYSTRING_H
