// Section 16
// Virtual functions

/*
 * When we derive a class from a base class, we can redefine the base classes
 * functions behaviors in the derived class.
 * If we do not use the virtual keyword with the derived functions, they are
 * statically bound at compile time (OVERLOADED functions or Redefinition functions (other name)).
 * If we use virtual keyword with the derived functions, they are bound dynamically
 * at run time (OVERRIDDEN functions).
 *
 * So with overridden functions we can think abstractly by treating all objects
 * in the hierarchy as objects of the base class.
 *
 * Once we declare a function as virtual in the Base class, then that function
 * is virtual in the derived classes.
 *
 * REMEMBER: virtual functions are dynamically bound ONLY when we call them via
 * a base class pointer or reference, otherwise they are statically bounded!
 *
 * Finally, whenever you have a virtual function, we need to have virtual destructors (04 project).
 *
 */

#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {  // in the derived classes virtual key is implicit, so we do not have to
                                            // specific here, but it is a best practice
        std::cout << "In Checking::withdraw" << std::endl;
    } // to override a Base class function, the Derived function signature and the return type must be the same,
      // otherwise the function will be treated as an overloaded function (static bind).
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
};

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();

    p1->withdraw(1000);  // Account::withdraw()
    p2->withdraw(1000);  // Savings::withdraw()
    p3->withdraw(1000);  // Checking::withdraw()
    p4->withdraw(1000);  // Trust::withdraw()


    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}
