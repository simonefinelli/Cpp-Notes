// Section 13
// Implementing member methods 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
    // attributes
    string name;
    double balance;

public:
    // methods

    // declared inline
    void set_balance(double bal) {
        balance = bal;
    }

    double get_balance() {
        return balance;
    }

    // methods will be implemented outside this class declaration
    void set_name(string n);      //--------------------//
    string get_name();            //--------------------//
                                                        //-----> like prototypes
    bool deposit(double amount);  //--------------------//
    bool withdraw(double amount); //--------------------//
};

void Account::set_name(string n) {  // '::' scope resolution operator
    name = n;
}

string Account::get_name() {
    return name;
}

bool Account::deposit(double amount) {
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}


int main() {

    Account account1;

    account1.set_name("Simox");
    account1.set_balance(10'000'000.00);  // cpp accepts numbers with ' separators

    if (account1.deposit(200.00))
        cout << "Deposit OK!" << endl;
    else
        cout << "Deposit Not Allowed!" << endl;

    if (account1.withdraw(7800.00))
        cout << "Withdraw OK!" << endl;
    else
        cout << "Not sufficient funds!" << endl;

    if (account1.withdraw(6'000'000'000.00))
        cout << "Withdraw OK!" << endl;
    else
        cout << "Not sufficient funds!" << endl;

    return 0;
}
