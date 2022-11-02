#ifndef CHALLENGE_CHECKINGACCOUNT_H
#define CHALLENGE_CHECKINGACCOUNT_H


#include "Account.h"

/**
 * CheckingAccount Concrete Class
 * TIP: a concrete class must override all the virtual methods
 */
class CheckingAccount: public Account {
private:
    static constexpr const char *def_name {"Unnamed Checking Account"};
    static constexpr double def_balance {0.0};
    static double fee;
public:
    CheckingAccount(std::string name = def_name, double balance = def_balance);

    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    void print(std::ostream &os) const override;

    ~CheckingAccount() override = default;
};


#endif // CHALLENGE_CHECKINGACCOUNT_H
