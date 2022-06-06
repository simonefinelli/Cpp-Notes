#include <iostream>
#include "AccountUtil.h"

// Displays Account objects in a vector of Account objects
void displays(const std::vector<Account> &accounts) {
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto &acc: accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposits(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw amount from each Account object in the vector
void withdraws(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}


// Helper functions for Savings Account class

// Displays Savings Account objects in a  vector of Savings Account objects
void displays(const std::vector<SavingsAccount> &accounts) {
    std::cout << "\n=== Savings Accounts ====================================" << std::endl;
    for (const auto &acc: accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposits(std::vector<SavingsAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraws(std::vector<SavingsAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Helper functions for Checking Account class

// Displays Checking Account objects in a  vector of Savings Account objects
void displays(const std::vector<CheckingAccount> &accounts) {
    std::cout << "\n=== Checking Accounts ====================================" << std::endl;
    for (const auto &acc: accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposits(std::vector<CheckingAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to Checking Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraws(std::vector<CheckingAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Checking Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Helper functions for Trust Account class

// Displays Trust Account objects in a  vector of Savings Account objects
void displays(const std::vector<TrustAccount> &accounts) {
    std::cout << "\n=== Trust Accounts ====================================" << std::endl;
    for (const auto &acc: accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Savings Account object in the vector
void deposits(std::vector<TrustAccount> &accounts, double amount) {
    std::cout << "\n=== Depositing to Trust Accounts ==========================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings Account object in the vector
void withdraws(std::vector<TrustAccount> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Trust Accounts ======================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

