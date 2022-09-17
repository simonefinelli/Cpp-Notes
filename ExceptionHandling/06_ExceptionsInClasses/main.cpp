// Section 18
// Exceptions in classes

/*
 * Exceptions can be thrown from class methods, constructors and destructors.
 * BUT, do NOT throw exceptions from destructors, indeed, the destructor is marked in
 * C++ as no except by default, which means that is does not throw exceptions.
 *
 * Exceptions in Methods
 *  work like functions
 *
 * Exceptions in Constructors
 *  since constructors may fail, and they do not return any value, throwing an
 *  exception can help to handle:
 *   - dynamic memory allocation failed
 *   - inability to open a file
 *   - etc.
 */

#include <iostream>
#include <memory>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"
#include "IllegalBalanceException.h"

using namespace std;

int main() {
    try {
        unique_ptr<Account> account = make_unique<CheckingAccount>("Gandalf", -42.42);
        cout << *account << endl;
    } catch (const IllegalBalanceException &ex) {
        cerr << "Couldn't create an account with negative balance!" << endl;
    }
    cout << "Bye!" << endl;

    return 0;
}
