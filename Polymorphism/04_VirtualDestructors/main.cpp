// Section 16
// Virtual destructors

/*
 * If we have a derived class object that is destroyed by deleting its base class pointer
 * and that class does not have a virtual destructor, then the behaviour is
 * undefined by the c++ standard!
 *
 * Derived objects must be destroyed in the correct order starting at the correct destructor.
 *
 * If a class has virtual functions we have to provide a virtual destructor, and
 * all derived class destructors will be virtual too.
 */

#include <iostream>

// this class uses dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() { std::cout << "Account:: destructor" << std::endl; }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() { std::cout << "Checking:: destructor" << std::endl; } // virtual keyword can be omitted, but for
                                                                               // a best practice is better to explict it
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() { std::cout << "Savings:: destructor" << std::endl; }

};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() { std::cout << "Trust:: destructor" << std::endl; }

};

int main() {

    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);


    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    /*
     * without virtual destructors we call always ~Account().
     * So we can hava a lot of memory leaks!
     */

    return 0;
}
