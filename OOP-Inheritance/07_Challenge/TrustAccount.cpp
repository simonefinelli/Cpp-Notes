#include "TrustAccount.h"

const double TrustAccount::bonus_threshold {5000.0};
const double TrustAccount::max_withdraw_amount_percentage {0.20};
double TrustAccount::bonus = {50.0};

TrustAccount::TrustAccount(std::string name, double balance, double int_rate)
        : SavingsAccount {name, balance, int_rate}, max_withdraws {3} {
}

/**
 * Deposit additional $50 bonus when amount >= 5000.0$
 * @param amount
 * @return bool
 */
bool TrustAccount::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus;
    return SavingsAccount::deposit(amount);
}

/**
 * The method is allowed only for 3 withdrawals,
 * and each can be up to a maximum of 20% of the account's value.
 */
bool TrustAccount::withdraw(double amount) {
    if (max_withdraws > 0 and (amount <= balance * max_withdraw_amount_percentage)) {
        max_withdraws--;
        return SavingsAccount::withdraw(amount);
    } else
        return false;
}

std::ostream &operator<<(std::ostream &os, const TrustAccount &account) {
    os << "[TrustAccount: " << account.name << ": " << account.balance << ", " << account.int_rate << "%, " << "Remaining withdraws:"<< account.max_withdraws <<"]";
    return os;
}
