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

/**
 * SavingsAccount Concrete Class
 * TIP: a concrete class must override all the virtual methods
 */
class SavingsAccount: public Account {
private:
    static constexpr const char *def_name = "Unnamed Savings Account";  // constexpr to declare static variable here
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    SavingsAccount(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    void print(std::ostream &os) const override;

    ~SavingsAccount() override {
        std::cout << name << " Savings Account destructor!" << std::endl;
    };
};


#endif // CHALLENGE_SAVINGSACCOUNT_H
