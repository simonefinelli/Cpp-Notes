// Section 16
// Polymorphism using final specifier

/*
 * We can use the final specifier in two contexts:
 *  - At the class level:
 *      Prevents a class from being derived.
 *      This is done for better compiler optimization, or to ensure that objects are
 *      copied safely without slicing.
 *  - At method level:
 *      Prevents the method from being overridden in derived classes.
 *      This is done for better compiler optimization.
 *
 *  // Classes
 *  class MyClass final {};
 *
 *  // Method
 *  void method() final {};
 */

#include <iostream>

using namespace std;

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base {
public:
    void say_hello() const override final {  // with final we prevent further overriding
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

class Another: public Derived {
public:
//    void say_hello()  const override  {  // compiler error: cannot override final method
//        std::cout << "Hello - I'm a Another class object" << std::endl;
//    }
};


// normal method
void greetings(const Base &obj) {
    std::cout << "Greetings: " ;
    obj.say_hello();  // (dynamic binding)
}

using namespace std;

int main() {
    Base b;
    b.say_hello();  // Base::say_hello()

    Derived d;
    d.say_hello();  // Derived::say_hello()

    Base *p1 = new Base();        // Base::say_hello()
    p1->say_hello();

    Derived *p2 = new Derived();  // Derived::say_hello()
    p2->say_hello();

    Base *p3 = new Derived();     // Derived::say_hello()
    p3->say_hello();

    std::cout <<  "\n========================" << std::endl;
    greetings(b);
    greetings(d);
    greetings(*p1);
    greetings(*p2);
    greetings(*p3);
    return 0;
}