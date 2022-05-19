// Section 14
// MyString - move assignment operator

/*
 * With move constructor we have more efficiency.
 *
 * MyString s1;
 * s1 = MyString ("Simox"); // the move constructor doesn't create a new temporary object MyString (like copy constructor),
 * but it 'moves' the r-value changing the pointing on the heap.
 *
 * So, the move operator overloading take advantage of move constructor.
 *
 * s1 = MyString ("simox");  // move operator= called
 * s1 = "SimoX";             // move operator= called
 *
 * Like always, if we have raw pointer we should overload the move assignment operator (for efficiency).
 */


#include "MyString.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    MyString a = "Hello";     // Overloaded constructor
    a = MyString("Hola");  // Overloaded constructor then move assignment BECAUSE the "Hola" is an r-value
    a = "Bonjour";            // Overloaded constructor then move assignment - "Bonjour" is an r-value


    MyString empty;              // no-args constructor
    MyString larry("Larry");  // overloaded constructor
    MyString stooge {larry};     // copy constructor - larry is an l-value
    MyString stooges;            // no-args constructor

    empty = stooge;   // copy assignment operator - stooge is an l-value

    empty = "Funny";  // move assignment operator - "Funny" is an r-value

    empty.display();
    larry.display();
    stooge.display();
    empty.display();

    stooges = "Larry, Moe, and Curly";
    stooges.display();

    vector<MyString> stooges_vec;
    stooges_vec.push_back("Larry");  // Move constructor
    stooges_vec.push_back("Moe");    // Move constructor
    stooges_vec.push_back("Curly");  // Move constructor

    cout << "=== Loop 1 ==================" << endl;
    for (const MyString &s: stooges_vec)
        s.display();

    cout << "=== Loop 2 ==================" << endl;
    for (MyString &s: stooges_vec)
        s = "Changed";  // move assignment

    cout << "=== Loop 3 ==================" << endl;
    for (const MyString &s: stooges_vec)
        s.display();

    return 0;
}
