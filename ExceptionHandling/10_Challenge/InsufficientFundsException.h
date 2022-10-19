#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H


#include <iostream>
#include <exception>

class InsufficientFundsException: public std::exception {
public:
    InsufficientFundsException() noexcept = default;

    virtual const char* what() const noexcept {
        return "Insufficient funds exception: amount not enough.";
    }

    ~InsufficientFundsException() override = default;
};


#endif // INSUFFICIENTFUNDSEXCEPTION_H
