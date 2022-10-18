// .h file contains classes declaration/specification
// .h stands for header (or include file)


/*
 * if the file (Account.h) is included by more than one .cpp file the compiler
 * will see the declaration of the account class more than once, so it will rise
 * a compiler error about duplicate declarations.
 * In order to solve that, we can use an INCLUDE GUARD, that ensure that the
 * compiler will process the file .h only once.
 *
 * An INCLUDE GUARD is just a series of pro-processor directives that guarantees
 * the file will only be included once.
 *
 * To guarantee uniqueness, they should be based on the full path in a project's source tree:
 *     <PROJECT>_<PATH>_<FILE>_H
 *
 * For example, the file foo/src/bar/baz.h in project foo should have the following guard:
 *     #ifndef FOO_BAR_BAZ_H
 *     #define FOO_BAR_BAZ_H
 *
 *     ...
 *
 *     #endif  // FOO_BAR_BAZ_H
 */

#ifndef _ACCOUNT_H  // if not define
#define _ACCOUNT_H

#include "string"


class Account {
private:
    // attributes
    std::string name;
    double balance;

public:
    // methods

    // declared inline
    void set_balance(double bal) {
        balance = bal;  // the 'this' is not necessary
    }

    double get_balance() {
        return balance;
    }

    // methods will be implemented outside this class declaration (in the file .cpp)
    void set_name(std::string n);  // method prototypes
    std::string get_name();        // method prototypes

    bool deposit(double amount);   // method prototypes
    bool withdraw(double amount);  // method prototypes
};


#endif // _ACCOUNT_H
