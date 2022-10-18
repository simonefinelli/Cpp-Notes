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

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) {
    os << "[SavingsAccount: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}
