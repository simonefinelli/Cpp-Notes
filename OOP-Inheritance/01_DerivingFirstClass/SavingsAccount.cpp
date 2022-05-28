#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
        : int_rate {3.0} {

}

SavingsAccount::~SavingsAccount() {}

void SavingsAccount::deposit(double amount) {
    std::cout << "Savings Account deposit called with " << amount << std::endl;
}

void SavingsAccount::withdraw(double amount) {
    std::cout << "Savings Account withdraw called with " << amount << std::endl;
}
