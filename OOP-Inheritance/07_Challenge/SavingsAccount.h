#ifndef CHALLENGE_SAVINGSACCOUNT_H
#define CHALLENGE_SAVINGSACCOUNT_H


/*
 *  Savings Account is a type of Account that adds an interest rate
 *
 *  Withdraw:
 *      same as a regular account
 *  Deposit:
 *      amount supplied to deposit will be incremented by (amount * int_rate/100)
 *      and then the updated amount will be deposited
 *
 */

#include "Account.h"

class SavingsAccount: public Account {
    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";  // constexpr to declare static variable here
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    SavingsAccount(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    // SavingsAccount inherits the Account::withdraw methods so no method override
};


#endif // CHALLENGE_SAVINGSACCOUNT_H
