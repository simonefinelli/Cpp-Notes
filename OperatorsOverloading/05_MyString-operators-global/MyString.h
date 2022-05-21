#ifndef MYSTRING_START_MYSTRING_H
#define MYSTRING_START_MYSTRING_H


class MyString {
    // note the friend notation
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend MyString operator-(const MyString &obj);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
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

    void display() const;
    int get_length() const;       // getters
    const char *get_str() const;
};


#endif // MYSTRING_START_MYSTRING_H
