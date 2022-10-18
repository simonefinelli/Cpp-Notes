#ifndef CHALLENGE_ACCOUNTUTIL_H
#define CHALLENGE_ACCOUNTUTIL_H


#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

// Utility helper functions for Account class

void displays(const std::vector<Account> &accounts);
void deposits(std::vector<Account> &accounts, double amount);
void withdraws(std::vector<Account> &accounts, double amount);

// Utility helper functions for Savings Account class

void displays(const std::vector<SavingsAccount> &accounts);
void deposits(std::vector<SavingsAccount> &accounts, double amount);
void withdraws(std::vector<SavingsAccount> &accounts, double amount);

// Utility helper functions for Savings Account class

void displays(const std::vector<CheckingAccount> &accounts);
void deposits(std::vector<CheckingAccount> &accounts, double amount);
void withdraws(std::vector<CheckingAccount> &accounts, double amount);

// Utility helper functions for Trust Account class

void displays(const std::vector<TrustAccount> &accounts);
void deposits(std::vector<TrustAccount> &accounts, double amount);
void withdraws(std::vector<TrustAccount> &accounts, double amount);


#endif // CHALLENGE_ACCOUNTUTIL_H
