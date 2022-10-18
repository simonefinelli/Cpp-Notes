// Section 15
// Deriving our First Class

/*
 * In C++ we have Public, Private and Protected inheritance.
 * Public:
 *  - Most common
 *  - Establishes an 'is-a' relationship between sub and super classes.
 *      E.g.: Student is-a Person. (Student class derive from Person Class)
 *
 * Private and Protected:
 *  - Establishes "derived class has a base class" relationship.
 *  - Different from composition.
 *
 * Refresh on Composition:
 *  - 'has-a' relationship
 *      E.g.: Person has-a Account, Player has-a SpecialAttack, etc.
 *      In the code we have something like that:
 *          class Person {
 *          private:
 *              string name;  //has-a name
 *              Account account; // has-a account
 *          }
 *
 * TIP: in this and others projects section only public inheritance is cover.
 */

#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

int main() {

    // Use the Account class
    cout << "\n=== Account ==================================" << endl;
    Account acc {};
    acc.deposit(2000.0);
    acc.withdraw(500.0);

    cout << endl;

    // using pointers
    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

    // Use the Savings Account class
    cout << "\n=== Savings Account ==========================" << endl;
    SavingsAccount sav_acc {};
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500.0);

    cout << endl;

    // using pointers
    SavingsAccount *p_sav_acc {nullptr};
    p_sav_acc = new SavingsAccount();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;

    cout << "\n==============================================" << endl;
    return 0;
}
