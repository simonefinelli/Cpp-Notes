#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H


#include "Account.h"

/*
 *  Savings Account class
 *  Deposit method increments amount to be deposited by amount * int_rate percentage!!
 *  So a 1000 deposit at 5% interest rate will deposit 1000 + 50 = 1050
 */

// Withdraw method does not specialize

class SavingsAccount: public Account {
    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account);
protected:
    double int_rate;
public:
    SavingsAccount();
    SavingsAccount(double balance, double int_rate);
    void deposit(double amount);
    // withdraw method is inherited
};


#endif // SAVINGSACCOUNT_H
