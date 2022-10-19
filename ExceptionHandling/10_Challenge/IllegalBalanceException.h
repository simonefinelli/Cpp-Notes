#ifndef ILLEGALBALANCEEXCEPTION_H
#define ILLEGALBALANCEEXCEPTION_H


#include <exception>

class IllegalBalanceException: public std::exception {
public:
    IllegalBalanceException() noexcept = default;

    virtual const char* what() const noexcept { // `noexcept` tells the compiler that the method will
                                                // not throw an exception. So don't throw exception from this method
        return "Illegal balance exception: negative amount.";
    }

    ~IllegalBalanceException() override = default; // the destructor is `noexcept` by default.
};

// NOTE: if we throw an exception from a method marked as `noexcept` the program
// will terminate and the exception will not be handled!


#endif // ILLEGALBALANCEEXCEPTION_H
