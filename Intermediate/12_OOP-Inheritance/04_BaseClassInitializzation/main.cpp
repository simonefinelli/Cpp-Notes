// Section 15
// Base class initialization

/*
 * Refresh: the base object in the derived class must be initialized first!
 *
 * Before we use derived constructor, some base class constructor must be invoked
 * to make the initialization of the Base class.
 * To call a specific base class constructor we can refer to the list arguments.
 *
 * TIP: if we don't explicitly invoke the base overloaded constructor, then the
 * no-args constructor will be invoked automatically (because the base class
 * must be always initialized).
 *
 */

#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
    Base() : value {0}  {
        cout << "Base no-args constructor" << endl;
    }
    Base(int x)  : value {x} {
        cout << "Base (int) overloaded constructor" << endl;
    }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived()
        : Base {}, doubled_value {0} {  // Superclass initialization using list initialization
        cout << "Derived no-args constructor " << endl;
    }
//    Derived()
//            : Derived(0) {  // using delegating constructor
//        cout << "Derived (int) constructor" << endl;
//    }

    Derived(int x)
        : Base {x}, doubled_value {x * 2} {  // Superclass initialization using list initialization
        cout << "Derived (int) constructor" << endl;
    }

    ~Derived() { cout << "Derived destructor " << endl; }
};

int main() {
    // Derived d;
    Derived d {1000};
    return 0;
}