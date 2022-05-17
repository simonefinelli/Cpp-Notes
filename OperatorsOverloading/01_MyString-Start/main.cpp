// Section 14
// MyString - starting point

/*
 * We have operator overloading when an operator works with different types
 * keeping the same behaviour (for example + operator can work with int, double, etc,).
 *
 * Operator Overloading allows us to make code more readable because it allows
 * to use an operator both with built-in types and user-defined types.
 *
 * The only operator that the compiler provides a default implementation of the
 * overloading is the assignment operator (=). All the other operators that can
 * be overloaded must be explicitly defined.
 *
 * Operator overload can also be applied to objects.
 *
 * The majority of operators can be overloaded, except these:
 *  - :: (scope resolution operator)
 *  - :? (conditional operator)
 *  - .* (pointer to member operator)
 *  - .  (dot operator)
 *  - sizeof
 *
 */

// TIP: this is the start project, so we don't have any kind of operator overloading


#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    MyString empty;                // no-args constructor
    MyString larry("Larry");    // overloaded constructor
    MyString stooge {larry};       // copy constructor

    empty.display();
    larry.display();
    stooge.display();

    return 0;
}
