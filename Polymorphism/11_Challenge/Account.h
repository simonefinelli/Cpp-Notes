#ifndef CHALLENGE_ACCOUNT_H
#define CHALLENGE_ACCOUNT_H


#include <iostream>
#include <string>
#include "IPrintable.h"

/**
 * Abstract Base Class
 */
class Account: public IPrintable {
private:
    static constexpr const char *def_name = "Unnamed Account";  // better way to declare default value
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);

    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    void print(std::ostream &os) const override;

    ~Account() override = default;
};


#endif // CHALLENGE_ACCOUNT_H
