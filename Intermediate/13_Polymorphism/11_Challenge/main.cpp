// Section 15
// Challenge

#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << std::fixed;

    // Account frank{"Frank", 5000};  // compile error

    CheckingAccount simox {"SimoX", 1'000};
    cout << simox << endl;

    Account *trust = new TrustAccount("Carl");
    cout << *trust << endl;

    Account *p1 = new CheckingAccount("Frodo", 100'000);
    Account *p2 = new SavingsAccount("Gandalf", 1'000, 5.0);
    Account *p3 = new TrustAccount("Bilbo", 42'000, 4.2);

    std::vector<Account *> accounts {p1,p2,p3};

    displays(accounts);
    deposits(accounts, 1'000);
    withdraws(accounts, 2'000);

    displays(accounts);

    delete p1;
    delete p2;
    delete p3;

    return 0;

    /*
     * TIP: remember that we cannot create instances of abstract classes, so
     * we cannot use vector<Account> but we can only handle raw/smart pointers
     *
     * See: https://stackoverflow.com/questions/57603980/c-vector-of-vector-of-abstract-class
     */
}
