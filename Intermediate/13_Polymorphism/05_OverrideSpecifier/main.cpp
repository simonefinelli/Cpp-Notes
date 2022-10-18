// Section 16
// Polymorphism using override specifier

/*
 * We can override base class using virtual functions.
 *
 * But if we change the signature a little by mistake, then the function will be
 * overloaded, and it will use static binding.
 *
 * To avoid this, C++ providing the Override Specifier.
 */

#include <iostream>

class Base {
public:
    virtual void say_hello() const {  // const because the method only print and don't want to modify anything.
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    virtual ~Base() {}
};

class Derived: public Base {
public:
    void say_hello() const override {  // virtual is redundant
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
    ~Derived() override {}
};


int main() {

    Base *p1 = new Base();        // Base::say_hello() (using dynamic binding)
    p1->say_hello();

    Derived *p2 = new Derived();  // Derived::say_hello() (using static binding)
    p2->say_hello();

    Base *p3 = new Derived();     // Derived::say_hello() (using dynamic binding)
    p3->say_hello();


    return 0;
}

