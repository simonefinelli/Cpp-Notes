#include "Account.h"
#include "CheckingAccount.h"

double CheckingAccount::fee {1.5};

CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account {name, balance} {
}

bool CheckingAccount::deposit(double amount) {
    return Account::deposit(amount);
}

bool CheckingAccount::withdraw(double amount) {
    return Account::withdraw(amount + fee);
}

void CheckingAccount::print(std::ostream &os) const {
    os << "[CheckingAccount: " << name << ": " << balance << ", " << "Fee: " << fee << "$]";
}