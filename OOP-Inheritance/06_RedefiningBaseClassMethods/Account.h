#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <iostream>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
protected:
    double balance;
public:
    Account();
    Account(double balance);
    void deposit(double amount);
    void withdraw(double amount);
};


#endif // ACCOUNT_H
