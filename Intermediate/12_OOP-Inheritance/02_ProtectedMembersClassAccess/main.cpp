// Section 15
// Protected members and class access

/*
 * Protected access modifier principles:
 * 1. All members and methods with protected access modifier are accessible to all
 *     methods of the class itself.
 * 2. Protected class members are also accessible by any derived classes that have
 *     been derived from the base class.
 * 3. Protected class members act like private members: they are not accessible
 *     directly from abjects of either the base class or of the derived class.
 *
 * With Public Inheritance
 *    Base Class      Derived Class
 *    public: a       public: a
 *    protected: b    protected: b
 *    private: c      c: no access (compiler error)
 *
 * With Protected Inheritance
 *    Base Class      Derived Class
 *    public: a       protected: a
 *    protected: b    protected: b
 *    private: c      c: no access (compiler error)
 *
 * With Private Inheritance
 *    Base Class      Derived Class
 *    public: a       private: a
 *    protected: b    private: b
 *    private: c      c: no access (compiler error)
 *
 * ATTENTION:
 *    - Friends of Base class have access to all!
 *    - Friends of Derived class have access to only what Derived has access to!
 */

#include <iostream>

using namespace std;

class Base {
public:
    // Refresh: public members has access to all (public, protect and private members)!
    int a {0};
    void display() const { std::cout << a << ", " << b << ", " << c << endl; }
protected:
    int b {0};
private:
    int c {0};
};

class Derived: public Base {
    // a public
    // b protected
    // c not be accessible
public:
    void access_base_members() {
        a = 1000;
        b = 2000;
//        c = 300;  // not accessible
    }

};

int main() {

    cout << "=== Base member access from base objects ===========" << endl;
    Base base;
    base.a = 100;   // OK
//    base.b = 200;   // Compiler Error - protected
//    base.c = 300;   // Compiler Error - private

    cout << "=== Base member access from derived objects ===========" << endl;
    Derived d;
    d.a = 42;
//    d.b = 200;  // Compiler Error - protected
//    d.c = 300;  // Compiler Error - private
    d.display();

    d.access_base_members();
    d.display();

    return 0;
}
