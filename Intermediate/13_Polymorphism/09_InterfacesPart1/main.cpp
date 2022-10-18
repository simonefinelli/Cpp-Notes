// Section 16
// Interfaces - Part1

/*
 * Abstract classes are used to make INTERFACES classes in c++.
 *
 * Interface
 *  - An Interface Class in a class that has ONLY pure virtual functions.
 *  - The virtual functions provide a general set of services that users of the class
 *    can use.
 *  - These virtual functions must be public (otherwise they won't be useful).
 *  - Each subclass is free to implement these services as needed.
 *  - Every service (method) MUST BE implemented (prototypes must match exactly)
 *
 * ATTENTION: unlike other languages, C++ does not provide a specific keyword
 * to declare an interface. So we use abstract classes with pure virtual functions
 * to achieve the concept of an interface.
 *
 * TIP: sometimes an Interface Class is declared putting in the name the letter
 * 'I' before the real name. E.g. IShape.
 */

#include <iostream>

/*****************
 * Account Class *
 *****************/
class Account  {
    friend std::ostream &operator<<(std::ostream &os, const Account &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {}
};

std::ostream &operator<<(std::ostream &os, const Account &acc) {
    os << "Account display";
    return os;
}

/******************
 * Checking Class *
 ******************/
class Checking: public Account  {
    friend std::ostream &operator<<(std::ostream &os, const Checking &acc);
public:
    void withdraw(double amount) override {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    ~Checking() override {}
};

std::ostream &operator<<(std::ostream &os, const Checking &acc) {
    os << "Checking display";
    return os;
}

/*****************
 * Savings Class *
 *****************/
class Savings: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Savings &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {}
};

std::ostream &operator<<(std::ostream &os, const Savings &acc) {
    os << "Savings display";
    return os;
}

/***************
 * Trust Class *
 ***************/
class Trust: public Account  {
    friend std::ostream &operator<<(std::ostream &os, const Trust &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {}
};

std::ostream &operator<<(std::ostream &os, const Trust &acc) {
    os << "Trust display";
    return os;
}


/********
 * Main *
 ********/
int main() {
//    Account a;
//    std::cout << a<< std::endl;
//
//    Checking c;
//    std::cout << c << std::endl;
//
//    Savings s;
//    std::cout << s << std::endl;
//
//    Trust t;
//    std::cout << t << std::endl;


    Account *p1 = new Account();
    std::cout << *p1 << std::endl;  // Account display

    Account *p2 = new Checking();
    std::cout << *p2 << std::endl;  // Account display

    /*
     * This happens because the operator<< is not a virtual function, and because it is not a member function,
     * we cannot use the virtual attribute.
     * So, to avoid this kind of mistakes:
     *  1. we can make a method print() and override it in all the concrete class (derived class)
     *  2. create an Interface to handle only the print of the objects (project 10_InterfacesPart2).
     */

    delete p1;
    delete p2;

    return 0;
}

