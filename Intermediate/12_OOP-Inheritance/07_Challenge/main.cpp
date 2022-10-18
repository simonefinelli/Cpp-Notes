// Section 16
// Challenge

#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "AccountUtil.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );

    displays(accounts);
    deposits(accounts, 1000);
    withdraws(accounts, 2000);

    // Savings Accounts

    vector<SavingsAccount> sav_accounts;
    sav_accounts.push_back(SavingsAccount {} );
    sav_accounts.push_back(SavingsAccount {"Superman"} );
    sav_accounts.push_back(SavingsAccount {"Batman", 2000} );
    sav_accounts.push_back(SavingsAccount {"Wonderwoman", 5000, 5.0} );

    displays(sav_accounts);
    deposits(sav_accounts, 1000);
    withdraws(sav_accounts, 2000);

    // Checking Accounts

    vector<CheckingAccount> check_accounts;
    check_accounts.push_back(CheckingAccount {} );
    check_accounts.push_back(CheckingAccount {"Bilbo"} );
    check_accounts.push_back(CheckingAccount {"Gandalf", 2000} );
    check_accounts.push_back(CheckingAccount {"Frodo", 5000} );

    displays(check_accounts);
    deposits(check_accounts, 1000);
    withdraws(check_accounts, 2000);

    // Trust Accounts

    vector<TrustAccount> trust_accounts;
    trust_accounts.push_back(TrustAccount {} );
    trust_accounts.push_back(TrustAccount {"Harry", 10'000, 5.0} );
    trust_accounts.push_back(TrustAccount {"Hermione", 20'000, 4.0} );
    trust_accounts.push_back(TrustAccount {"Ron", 30'000} );

    displays(trust_accounts);
    deposits(trust_accounts, 1000);
    withdraws(trust_accounts, 3000);

    cout << "\n===== Run out of all withdrawals =====";
    // call withdraws 5 times
    for (int i=1; i<=5; i++)
        withdraws(trust_accounts, 1000);

    cout << "\n===== Operators overloading =====\n";

    Account a1 {"Mario"};
    a1 += 1000.0;
    cout << a1 << endl;
    a1 -= 10.0;
    cout << a1 << endl;

    CheckingAccount c1 {};
    c1 += 500.0;
    cout << c1 << endl;
    c1 -= 10.0;
    cout << c1 << endl;

    // in these cases we use Account operator-= because for the TrustAccount
    // that operator is NOT implemented
    TrustAccount t1 {"Luigi", 1'500};
    t1 -= 1000.00;
    t1 -= 10.00;
    t1 -= 1.00;
    t1 -= .10;
    cout << t1 << endl;

    return 0;
}
