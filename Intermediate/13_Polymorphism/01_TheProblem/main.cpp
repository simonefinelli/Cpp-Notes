// Section 16
// Introduction to Polymorphism

/*
 * There are several types of polymorphism in C++, in particular we have two families:
 *
 * COMPILE-TIME POLYMORPHISM (or early/static binding):
 *    - Function overloading
 *    - Operator overloading
 *  Compile-time means that the compiler takes care of that before the program runs.
 *
 * RUN-TIME POLYMORPHISM (or late/dynamic binding):
 *    - Function overriding
 *  Run-time means that the compiler takes care of that as the program executes.
 *
 * Polymorphism allows us to think more abstractly.
 *
 * In C++ the default binding is the static! (principally for efficiency)
 *
 * To achieve run-time polymorphism we must have:
 *  - Inheritance
 *  - Base class pointers or references
 *  - Virtual functions
 *
 * For example if we have public inheritance between Account and TrustAccount,
 * with static binding we have:
 *    Account *p = new TrustAccount();
 *    p->withdraw(1000); // this call Account::withdraw(), but we want TrustAccount::withdraw()
 *
 * with dynamic binding we have:
 *    p->withdraw(1000); // this call TrustAccount::withdraw()
 *  to achieve this, withdraw method is declared as virtual in the Account class.
 *
 * The idea of using virtual functions tells the compiler to use run time binding.
 */

#include <iostream>
#include <memory>  // for smart pointers

class Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base {
public:
    void say_hello()  const {
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};


/*
 * Because we have static binding if the greetings function is called passing
 * a Derived object, it's using the Base say_hello() method.
 */
void greetings(const Base &obj) {  // remember that Derived 'is-a' Base so the function can accept Derived objs.
    std::cout << "Greetings: " ;
    obj.say_hello();
}

int main() {
    Base b;
    b.say_hello();  // Hello - I'm a Base class object

    Derived d;
    d.say_hello();  // Hello - I'm a Derived class object

    greetings(b);  // Hello - I'm a Base class object
    greetings(d);  // Hello - I'm a Base class object

    // raw pointers
    Base *ptr = new Derived();
    ptr->say_hello();  // Hello - I'm a Base class object

    //
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();  // Hello - I'm a Base class object (same problem even with smart pointers)

    // free memory (only row pointers)
    delete ptr;

    return 0;
}
