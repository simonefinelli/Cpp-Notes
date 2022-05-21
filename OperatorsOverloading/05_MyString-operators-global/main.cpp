// Section 14
// MyString - overload operators as global functions

/*
 * C++ allows us to overload operators as member methods or as global functions (this project).
 *
 * Since these we have non-member functions, we no longer have a `this` pointer to the lhs object.
 * So to get access to private attributes, the non-member functions are declared as friend functions (or we simply use getters to get private values)
 *
 * We can overload unary operators:
 *    ++, --, -, !
 *
 *    Basic declaration:
 *       ReturnType Type::operatorOp(Type &obj);
 *       TIP: the returned object is by value.
 *
 * and binary operators:
 *    +, -, ==, !=, <, >, etc.
 *
 *    Basic declaration:
 *       ReturnType Type::operatorOp(const Type &lhs, const Type &rhs);
 *       TIP: the returned object is by value.
 *
 * TIP: we can't have both member and non-member versions of the same overloaded operator!
 *
 * MyString last_name("XXX")
 * E.g.: "Simox" + last_name;  // Error with member functions, no problems with non-member functions.
 *
 * But
 * "Simox" + "last_name"; // won't work because C++ assumes that they are primitive pointers and not objects.
 *
 */


#include "MyString.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    MyString larry {"Larry"};
    larry.display();  // Larry

    larry = -larry;
    larry.display();  // larry

    cout << boolalpha << endl;
    MyString moe{"Moe"};
    MyString stooge = larry;

    cout << (larry == moe) << endl;     // false
    cout << (larry == stooge) << endl;  // true

    MyString stooges = "Larry" + moe;  // Now OK with non-member function ("Larry" will convert in a MyString object)
    stooges.display();  // LarryMoe

    MyString two_stooges = moe + " " + "Larry";
    two_stooges.display();  // Moe Larry
    MyString three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();  // Moe larry Curly

    return 0;
}
