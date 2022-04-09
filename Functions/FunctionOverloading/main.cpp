// Section 11
// Function Overloading (Great example of polymorphism)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);
// TIP
/* don't do this
 * void print(int=42);
 * void print(double=42.42);
 *
 * print(); the compiler get in error because he doesn't know which to call
 *          so be careful when declaring DEFAULTS values
 */

int main() {
    print(100);    // int
    print('A');     //  character is always promoted to int should print 65 ASCII ('A')

    print(123.5);   // double
    print(123.3F);  // Float is promoted to double so the function is the same as before

    print("C-style string");  // C-style string is converted to a C++ string so the function is the same as below

    string s {"C++ string"};
    print(s);       // C++ string

    print("C-style string", s); // First argument is converted to a C++ string

    vector<string> three_stooges {"Larry", "Moe", "Curly"};
    print(three_stooges);

    cout << endl;
    return 0;
}

void print(int num) {
    cout << "Printing int: " << num << endl;
}

void print(double num) {
    cout << "Printing double: " << num << endl;
}

void print(string s) {
    cout << "Printing string: " << s << endl;
}

void print(string s, string t) {
    cout << "Printing 2 strings: " << s << " and " << t << endl;
}

void print(vector<string> v) {
    cout << "Printing vector of strings: " ;
    for (auto s: v)
        cout << s + " ";
    cout << endl;
}

