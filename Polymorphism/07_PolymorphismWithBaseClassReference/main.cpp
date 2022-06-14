// Section 16
// Polymorphism using Base class references

/*
 * We can also use dynamic Polymorphism with Base class references.
 */

#include <iostream>

class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    void withdraw(double amount) override {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    ~Checking() override {}
};

class Savings: public Account  {
public:
    void withdraw(double amount) override {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    ~Savings() override {}
};

class Trust: public Account  {
public:
    void withdraw(double amount) override {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    ~Trust() override {}
};


// normal method
void do_withdraw(Account &account, double amount) {  // dynamic binding (reference)
    account.withdraw(amount);  // dynamic binding
}

int main() {

    Account a;
    Account &ref = a;
    ref.withdraw(1000);		 // In Account::withdraw - dynamic binding (reference)

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000);     // In Trust::withdraw - dynamic binding (reference)

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    do_withdraw(a1, 1000);   // In Account::withdraw - dynamic binding (reference)
    do_withdraw(a2, 2000);   // In Savings::withdraw - dynamic binding (reference)
    do_withdraw(a3, 3000);   // In Checking::withdraw - dynamic binding (reference)
    do_withdraw(a4, 4000);   // In Trust::withdraw - dynamic binding (reference)


    return 0;
}