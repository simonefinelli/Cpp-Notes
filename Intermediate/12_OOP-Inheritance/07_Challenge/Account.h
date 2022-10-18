#ifndef CHALLENGE_ACCOUNT_H
#define CHALLENGE_ACCOUNT_H


#include <iostream>
#include <string>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
    friend Account &operator+=(Account &lhs, double amount);
    friend Account &operator-=(Account &lhs, double amount);
private:
    static constexpr const char *def_name = "Unnamed Account";  // better way to declare default value
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
};


#endif // CHALLENGE_ACCOUNT_H
