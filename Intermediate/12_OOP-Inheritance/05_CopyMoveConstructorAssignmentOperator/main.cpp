// Section 15
// Copy/Move constructor and operator=

/*
 * Copy/Move constructor and assigment operator (operator=) are not inherited
 * from the Base class.
 *
 * REMEMBER that if we don't have pointers the compiler already provide default
 * versions of these operations (in the most of all cases is all we need).
 *
 * If necessary, we can invoke the Base class versions from the Derived class.
 *
 * === Copy Constructor
 *    If we need to copy a derived object, then we must ensure that the base
 *    part of that derived object is also copied. If the Base class has a copy
 *    constructor, then we can explicit invoke it from our derived copy
 *    constructor (using for example initialization list).
 *
 * === Move Constructor
 *    The move constructor works as the copy constructor.
 *
 * === Overloaded copy/move assignment
 *    They work on the same principle of copy/move constructors.
 *
 * In general, we have that:
 *  - Often you do not need to provide your own copy/move constructors and overloaded operator=.
 *  - If we do not define them in Derived class, then the compiler will create
 *     them automatically and calls the Base class' version.
 *  - If we provide Derived versions, then we must invoke the Base versions EXPLICITLY!
 *  - If we have raw pointers or dynamic memory allocation, use deep copy semantics!
 *
 */

#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
    Base()
        : value {0}  {
        cout << "Base no-args constructor" << endl;
    }
    Base(int x)
        : value {x} {
        cout << "int Base constructor" << endl;
    }

    // copy constructor
    Base(const Base &other)
        : value {other.value} {
        cout << "Base copy constructor" << endl;
    }

    // overloading copy assignment operator
    Base &operator=(const Base &rhs)  {
        cout << "Base operator=" << endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }

    ~Base(){ cout << "Base destructor" << endl; }
};


class Derived : public Base {
private:
    int doubled_value;
public:
    Derived()
        : Base {}  {
        cout << "Derived no-args constructor " << endl;
    }
    Derived(int x)
        : Base{x} , doubled_value {x * 2} {
        cout << "int Derived constructor" << endl;
    }

    // copy constructor
    Derived(const Derived &other)  // the variable other references the derived object!
        : Base(other), doubled_value {other.doubled_value} {  // we can pass other (Derived object) to Base constructor
                                                              // because we use a 'is-a' inheritance, so a Derived object ia a Base object.
                                                              // In this case the compiler uses a 'slicing' and slice out the Base part
                                                              // from the derived object. (through the compiler inspection this part is viewable)
        cout << "Derived copy constructor" << endl;
    }

    // overloading copy assignment operator
    Derived &operator=(const Derived &rhs) {
        cout << "Derived operator=" << endl;
        if (this == &rhs)
            return *this;
        Base::operator=(rhs);  // assign the Base part with the overloaded copy assigment Base operator (using slicing)
        doubled_value = rhs.doubled_value;  // assign the Derived part
        return *this;
    }
    ~Derived(){ cout << "Derived destructor " << endl; }
};


int main() {
//    Base b {100};  // Overloaded constructor
//    Base b1 {b};      // Copy constructor
//    b = b1;           // Copy assignment - (refresh: b1 will be an l-value)

    Derived d {100};  // Overloaded constructor
    Derived d1 {d};   // Copy constructor
    d = d1;           // Copy assignment

    return 0;
}

