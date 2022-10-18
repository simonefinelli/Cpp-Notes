#ifndef CHALLENGE_ACCOUNTUTIL_H
#define CHALLENGE_ACCOUNTUTIL_H


#include <vector>
#include "Account.h"

// Utility helper functions for ALL Account classes
void displays(const std::vector<Account *> &accounts);
void deposits(std::vector<Account *> &accounts, double amount);
void withdraws(std::vector<Account *> &accounts, double amount);


#endif // CHALLENGE_ACCOUNTUTIL_H
