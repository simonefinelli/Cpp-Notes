// Section 18
// Exceptions in classes

/*
 * C++ Standard Exception Class Hierarchy
 *  - std::exception is the Base class
 *  - all derived classes have to implement the `what()` virtual function, that
 *    describes the exception occurred
 *     virtual const char *what() const noexcept;
 *
 *  To view the entire std::exception class see https://en.cppreference.com/w/cpp/error/exception
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
        cerr << ex.what() << endl;
    }
    cout << "Bye!" << endl;

    return 0;
}
