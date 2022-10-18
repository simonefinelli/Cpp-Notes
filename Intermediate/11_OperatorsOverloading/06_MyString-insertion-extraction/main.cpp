// Section 14
// MyString - overload stream insertion (<<) and extraction (>>) operators

/*
 * These operators allow us to deal with streams.;
 *
 * In this case it doesn't make sense to implement the insertion/extraction
 * operators as member methods. When we overload an operator as a member method,
 * the lhs (left-hand side) object must be an object of the class we're overloading.
 * This means that we would have to write MyString obj on the left size of the
 * stream operator.
 * Ex:
 *    MyString name("Simox");
 *    name << std::cout;
 *
 * So use non-member functions is the right choice!
 *
 */


#include <iostream>
#include "MyString.h"

using namespace std;


int main() {

    MyString larry {"Larry"};
    MyString moe {"Moe"};
    MyString curly;

    cout << "Enter the third stooge's first name: ";
    cin >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    cout << "\nEnter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    return 0;
}