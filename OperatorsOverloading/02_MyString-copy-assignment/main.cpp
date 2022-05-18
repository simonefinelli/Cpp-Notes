// Section 14
// MyString - copy assignment operator

/*
 * The assignment operator is used by c++ when it assigns one object to another.
 * Don't confuse assignment with initialization.
 *
 * MyString s1 = "SimoX";  // initialization
 * MyString s2 = s1;       // initialization
 *
 * s2 = s1;  // assignment. If we don't provide own overload assignment operator, the compiler generates one for us.
 *           // The default assignment is member-wise assignment (shallow copy).
 *           // So if we have pointers deep copy is required.
 *
 * To overload the copy assignment operator:
 *      Type &Type::operator=(const Type &rhs);  // deep copy
 *
 */


#include "MyString.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    MyString a {"Hello"};     // overloaded constructor
    MyString b;                  // no-args constructor

    b = a;                       // copy assignment
                                 // b.operator=(a)

    b = "This is a test";        // copy assignment - b.operator=("This is a test");

    MyString empty;              // no-args constructor
    MyString larry("Larry");  // overloaded constructor
    MyString stooge {larry};     // copy constructor
    MyString stooges;            // no-args constructor

    empty = stooge;  // copy assignment

    empty.display();   // Larry : 5
    larry.display();   // Larry : 5
    stooge.display();  // Larry : 5
    empty.display();   // Larry : 5

    stooges = "Larry, Moe, and Curly";  // copy assignment
    stooges.display();  // Larry, Moe, and Curly : 21

    vector<MyString> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");

    cout << "=== Loop 1 ==================" << endl;
    for (const MyString &s: stooges_vec)
        s.display();

    cout << "=== Loop 2 ==================" << endl;
    for (MyString &s: stooges_vec)
        s = "Changed";  // copy assignment

    cout << "=== Loop 3 ================" << endl;
    for (const MyString &s: stooges_vec)
        s.display();

    return 0;
}
