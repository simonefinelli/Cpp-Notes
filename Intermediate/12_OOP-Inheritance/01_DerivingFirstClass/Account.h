#ifndef DERIVINGFIRSTCLASS_ACCOUNT_H
#define DERIVINGFIRSTCLASS_ACCOUNT_H


#include <string>

/**
 * Account is the super class (base class or parent class)
 *
 */
class Account {
public:
    double balance;
    std::string name;

    Account();
    ~Account();

    void deposit(double amount);
    void withdraw(double amount);
};


#endif //DERIVINGFIRSTCLASS_ACCOUNT_H
