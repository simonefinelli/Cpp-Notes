#ifndef DERIVINGFIRSTCLASS_SAVINGSACCOUNT_H
#define DERIVINGFIRSTCLASS_SAVINGSACCOUNT_H


#include "Account.h"  // to get the Account class

/**
 * SavingsAccount is the sub class (derived class or child class)
 */
class SavingsAccount: public Account {  // public inheritance - it establishes an "is-a" relationship between
                                        // SavingsAccount and Account.
public:
    double int_rate;
    SavingsAccount();
    ~SavingsAccount();
    void deposit(double amount);
    void withdraw(double amount);
};


#endif //DERIVINGFIRSTCLASS_SAVINGSACCOUNT_H
