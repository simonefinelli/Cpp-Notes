// Section 16
// Dynamic Polymorphism using Base class pointers

#include <iostream>
#include <vector>

// this class uses dynamic polymorphism for the withdraw method
// to achieve dynamic binding we use virtual keyword (more details in 03 project)
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }

    virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();

    p1->withdraw(1000);  // Account::withdraw
    p2->withdraw(1000);  // Savings::withdraw
    p3->withdraw(1000);  // Checking::withdraw
    p4->withdraw(1000);  // Trust::withdraw

    std::cout << "\n === Array ==== " << std::endl;
    Account *array [] = {p1,p2,p3,p4};
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);  // call a specific withdraw and not always Account::withdraw like static binding.

    std::cout << "\n === Array ==== " << std::endl;
    array[0] = p4;
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);

    std::cout << "\n === Vector ==== " << std::endl;
    std::vector<Account *> accounts {p1,p2,p3,p4};
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);

    std::cout << "\n === Vector ==== " << std::endl;
    accounts.push_back(p4);
    accounts.push_back(p4);
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}
