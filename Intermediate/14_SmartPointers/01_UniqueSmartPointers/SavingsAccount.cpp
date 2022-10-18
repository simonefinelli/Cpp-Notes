#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance, double int_rate)
        : Account {name, balance}, int_rate{int_rate} {
}

// Deposit:
//    Amount supplied to deposit will be incremented by (amount * int_rate/100)
//    and then the updated amount will be deposited
//
bool SavingsAccount::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

bool SavingsAccount::withdraw(double amount) {
    return Account::withdraw(amount);
}

void SavingsAccount::print(std::ostream &os) const {
    os << "[SavingsAccount: " << name << ": " << balance << ", " << int_rate << "%]";
}
