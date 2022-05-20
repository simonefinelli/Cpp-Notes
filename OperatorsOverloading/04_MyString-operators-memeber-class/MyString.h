#ifndef MYSTRING_START_MYSTRING_H
#define MYSTRING_START_MYSTRING_H


class MyString {
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    MyString();                            // No-args constructor
    MyString(const char *s);               // Overloaded constructor
    MyString(const MyString &source);      // Copy constructor
    MyString( MyString &&source);          // Move constructor
    ~MyString();                           // Destructor

    MyString &operator=(const MyString &rhs);  // Copy assignment declaration - we overload the = operator - rhs is an l-value
                                               // TIP: rhs stands for right-hand side

    MyString &operator=(MyString &&rhs) noexcept;  // Move assignment - rhs now is an r-value

    MyString operator-() const;                      // make lowercase
    MyString operator+(const MyString &rhs) const;   // concatenate
    bool operator==(const MyString &rhs) const;      // compare the string (only member attribute str is available in this case)

    void display() const;
    int get_length() const;       // getters
    const char *get_str() const;
};


#endif // MYSTRING_START_MYSTRING_H
