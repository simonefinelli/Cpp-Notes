#include <iostream>
#include "AccountUtil.h"

// Displays Account objects in a vector of Account objects pointers
void displays(const std::vector<Account *> &accounts) {
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto acc : accounts)
        std::cout << *acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposits(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto acc : accounts)  {
        if (acc->deposit(amount))
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << *acc << std::endl;
    }
}

// Withdraw amount from each Account object in the vector
void withdraws(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto acc : accounts)  {
        if (acc->withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << *acc << std::endl;
    }
}
