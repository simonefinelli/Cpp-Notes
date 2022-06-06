#ifndef CHALLENGE_CHECKINGACCOUNT_H
#define CHALLENGE_CHECKINGACCOUNT_H


#include "Account.h"

class CheckingAccount: public Account{
    friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &account);
    // override only operator-= because it is different from Account class behaviour
    friend CheckingAccount &operator-=(CheckingAccount &lhs, double amount);
private:
    static constexpr const char *def_name {"Unnamed Checking Account"};
    static constexpr double def_balance {0.0};
    static double fee;
public:
    CheckingAccount(std::string name = def_name, double balance = def_balance);
    // Account::deposit is inherited, and it's already fine
    bool withdraw(double amount);
};


#endif // CHALLENGE_CHECKINGACCOUNT_H
