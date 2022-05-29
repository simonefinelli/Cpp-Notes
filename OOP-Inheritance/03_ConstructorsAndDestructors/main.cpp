// Section 15
// Constructors and Destructors in inheritance

/*
 * CONSTRUCTORS
 * As expected the Base part of the Derived class must be initialized before the
 * Derived class is initialized.
 *
 * So, when a Derived object is created:
 *  1. the Base class constructor is executed,
 *  2. the Derived class constructor is executed.
 *
 * DESTRUCTORS
 * Destructors are invoked in the reverse order: first derived destructor after
 * the base destructor.
 * Note that each destructor should free any resources allocated in its own class constructors.
 *
 * Derived classes do not inherit
 *  - Base class constructors
 *  - Base class destructors
 *  - Base class overloaded assignment operators
 *  - Base class friend functions
 *
 * However, Derived classes can invoke
 *  - Base class constructors
 *  - Base class destructors
 *  - Overloaded assignment operators
 *
 */


#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
    Base() : value{0} { cout << "Base no-args constructor" << endl; }
    Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
    ~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived() : doubled_value {-100} { cout << "Derived no-args constructor " << endl; }
    Derived(int x) : doubled_value {x*2}  { cout << "Derived (int) overloaded constructor" << endl; }
    ~Derived() { cout << "Derived destructor " << endl; }
};

int main() {

    // Base b;
    // Base b {42};
    // Derived d;
    Derived d {1000};

    return 0;
}