#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double balance, double int_rate)
        : Account {balance}, int_rate {int_rate} {

}

SavingsAccount::SavingsAccount()
        : SavingsAccount {0.0, 0.0} {

}

void SavingsAccount::deposit(double amount) {  // Override Base class method
    amount = amount + (amount * int_rate/100);
    Account::deposit(amount);  // invoke the Base class method
}

// TIP: we don't want override operator<< because we'll lose the part of SavingsAccount due to slicing!
std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) {
    os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate;
    return os;
}