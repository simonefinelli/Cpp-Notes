// Section 18
// Challenge

#include <iostream>
#include <memory>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

using namespace std;

int main() {
    std::unique_ptr<Account> bilbo_account;
    std::unique_ptr<Account> gandalf_account;

    try {
        bilbo_account = std::make_unique<SavingsAccount>("Bilbo", -2000.0);
        std::cout << *bilbo_account << std::endl;

    } catch (const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }

    try {
        gandalf_account = std::make_unique<SavingsAccount>("Gandalf", 1000.0);
        std::cout << *gandalf_account << std::endl;
        gandalf_account->withdraw(500.0);
        std::cout << *gandalf_account << std::endl;
        gandalf_account->withdraw(1000.0);
        std::cout << *gandalf_account << std::endl;

    } catch (const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    } catch (const InsufficientFundsException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}

