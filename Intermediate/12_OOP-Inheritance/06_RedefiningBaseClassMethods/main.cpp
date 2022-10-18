// Section 15
// Redefining and Using Base Class Methods

/*
 * A derived class can Override or Redefine base class methods using the same
 * name and signature of the method in the base class.
 * So the signature is the same, but the implementation is different!
 *
 * By default, C++ uses STATIC BINDING:
 *  - Base b;
 *    b.deposit(1000.0);           // this call Base::deposit()
 *
 *  - Derived d;
 *    d.deposit(1000.0);           // this call Derived::deposit()
 *
 *  - Base *ptr = new Derived();
 *    ptr->deposit(1000.0);        // this call Base::deposit()
 *                                 // to change this behaviour and call Derived::deposit()
 *                                 // we have to use DYNAMIC BINDING (see Polymorphism section)
 */

#include <iostream>
#include "SavingsAccount.h"

using namespace std;


int main() {
    cout << "\n===== Account class ===================" << endl;
    Account a1 {1000.0};
    cout << a1 << endl;           // Account balance: 1000

    a1.deposit(500.0);
    cout << a1 << endl;           // Account balance: 1500

    a1.withdraw(1000);    // Account balance: 500
    cout << a1 << endl;

    a1.withdraw(5000.0);  // Insufficient funds
    cout << a1 << endl;           // Account balance: 500

    cout << "\n===== Savings Account class ===========" << endl;
    SavingsAccount s1 {1000, 5.0};
    cout << s1 << endl;         // Savings Account balance: 1000, Interest rate: 5

    s1.deposit(1000);
    cout << s1 << endl;         // Savings Account balance: 2050, Interest rate: 5

    s1.withdraw(2000);
    cout << s1 << endl;         // Savings Account balance: 50, Interest rate: 5

    s1.withdraw(1000);  // Insufficient funds
    cout << s1 << endl;         // Savings Account balance: 50, Interest rate: 5


    return 0;
}
