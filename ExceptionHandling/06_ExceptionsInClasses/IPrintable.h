#ifndef CHALLENGE_IPRINTABLE_H
#define CHALLENGE_IPRINTABLE_H


#include <iostream>

/**
 * Interface to print all kind of accounts
 */
class IPrintable {
    friend std::ostream &operator<<(std::ostream &os, const IPrintable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~IPrintable() = default;
};


#endif // CHALLENGE_IPRINTABLE_H
