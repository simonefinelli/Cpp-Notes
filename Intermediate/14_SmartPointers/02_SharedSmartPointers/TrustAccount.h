#ifndef CHALLENGE_TRUSTACCOUNT_H
#define CHALLENGE_TRUSTACCOUNT_H


#include "SavingsAccount.h"

/**
 * TrustAccount Concrete Class
 * TIP: a concrete class must override all the virtual methods
 */
class TrustAccount: public SavingsAccount {
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

    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    void print(std::ostream &os) const override;

    ~TrustAccount() override {
        std::cout << name << " Trust Account destructor!" << std::endl;
    };
};


#endif // CHALLENGE_TRUSTACCOUNT_H
