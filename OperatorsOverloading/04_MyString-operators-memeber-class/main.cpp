// Section 14
// MyString - overload operators as member functions

/*
 * C++ allows us to overload operators as member methods (this project) or as global non-member functions.
 *
 * We can overload unary operators:
 *    ++, --, -, !
 *
 *    Basic declaration:
 *       ReturnType Type::operatorOp();
 *       TIP: the returned object is by value.
 *
 * and binary operators:
 *    +, -, ==, !=, <, >, etc.
 *
 *    Basic declaration:
 *       ReturnType Type::operatorOp(const Type &rhs);
 *       TIP: the returned object is by value.
 *
 * WARNING: the only limitation to overloading operators as member functions is
 *  that the object on the left-hand side must be an object of the class you're
 *  using.
 *
 *  MyString last_name("XXX")
 *  E.g.: "Simox" + last_name;  // Error -> lhs is not a MyString object (no problems with non-member functions)
 */


#include "MyString.h"
#include <iostream>


using namespace std;


int main() {
    cout << boolalpha << endl;  // to print true false instead of 1 and 0.

    MyString larry{"Larry"};
    MyString moe{"Moe"};
    MyString stooge = larry;

    larry.display();  // Larry
    moe.display();    // Moe

    cout << (larry == moe) << endl;     // false
    cout << (larry == stooge) << endl;  // true

    larry.display();            // Larry
    MyString larry2 = -larry;
    larry2.display();           // larry

    MyString stooges = larry + "Moe";    // ok with member function
    //MyString stooges = "Larry" + moe;  // compiler error - lhs ("Larry") is not a MyString object

    MyString two_stooges = moe + " " + "Larry";
    two_stooges.display();  // Moe Larry
    MyString three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display();  // Moe Larry Curly

    return 0;
}
