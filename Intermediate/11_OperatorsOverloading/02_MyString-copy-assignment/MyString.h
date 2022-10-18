#ifndef MYSTRING_START_MYSTRING_H
#define MYSTRING_START_MYSTRING_H


class MyString
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    MyString();                            // No-args constructor
    MyString(const char *s);               // Overloaded constructor
    MyString(const MyString &source);      // Copy constructor
    ~MyString();                           // Destructor

    MyString &operator=(const MyString &rhs);  // Copy assignment declaration - we overload the = operator
                                               // TIP: rhs stands for right-hand side

    void display() const;
    int get_length() const;                // getters
    const char *get_str() const;
};


#endif // MYSTRING_START_MYSTRING_H
