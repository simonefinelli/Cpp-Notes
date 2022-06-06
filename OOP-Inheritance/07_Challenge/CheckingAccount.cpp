#include "Account.h"
#include "CheckingAccount.h"

double CheckingAccount::fee {1.5};

CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account {name, balance} {
}

bool CheckingAccount::withdraw(double amount) {
    return Account::withdraw(amount + fee);
}

std::ostream &operator<<(std::ostream &os, const CheckingAccount &account) {
    os << "[CheckingAccount: " << account.name << ": " << account.balance << ", " << "Fee: " << CheckingAccount::fee << "$]";
    return os;
}

CheckingAccount &operator-=(CheckingAccount &lhs, double amount) {
    lhs.withdraw(amount);
    return lhs;
}