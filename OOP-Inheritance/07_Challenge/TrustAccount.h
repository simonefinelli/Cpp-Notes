#ifndef CHALLENGE_TRUSTACCOUNT_H
#define CHALLENGE_TRUSTACCOUNT_H

#include "SavingsAccount.h"

class TrustAccount: public SavingsAccount {
    friend std::ostream &operator<<(std::ostream &os, const TrustAccount &account);
private:
    static constexpr const char *def_name {"Unnamed Trust Account"};
    static constexpr double def_balance {0.0};
    static constexpr double def_int_rate {0.0};
    static const double max_withdraw_amount_percentage;
    static const double bonus_threshold;
    static double bonus;
protected:
    unsigned max_withdraws;
public:
    TrustAccount(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    bool withdraw(double amount);
};


#endif // CHALLENGE_TRUSTACCOUNT_H
