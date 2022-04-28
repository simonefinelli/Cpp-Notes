// Section 13
// Implementing member methods 2

#include <iostream>  // '< >' are used to include system header files
#include "Account.h"  // '" "' are used to include local header files

using namespace std;

int main() {

    Account account1;  // Account is declared in the header file Account.h

    account1.set_name("Simox");
    account1.set_balance(10'000.00);  // cpp accepts numbers with ' separators

    if (account1.deposit(2009.32))
        cout << "Deposit OK!" << endl;
    else
        cout << "Deposit Not Allowed!" << endl;

    if (account1.withdraw(7800.90))
        cout << "Withdraw OK!" << endl;
    else
        cout << "Not sufficient funds!" << endl;

    if (account1.withdraw(60'000.00))
        cout << "Withdraw OK!" << endl;
    else
        cout << "Not sufficient funds!" << endl;

    cout << "The final balance is: " << account1.get_balance() << " $" << endl;

    return 0;
}
