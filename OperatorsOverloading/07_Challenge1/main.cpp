// Section 14
// Challenge - using member-class overload operators

#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    cout << boolalpha << endl;
    MyString a {"frank"};
    MyString b {"frank"};

    cout << "===== Equality/Inequality operator =====" << endl;
    cout << "a==b: " << (a==b) << endl;  // true
    cout << "a!=b: " << (a!=b) << endl;  // false

    b = "george";
    cout << "a==b: " << (a==b) << endl;  // false
    cout << "a!=b: " << (a!=b) << endl;  // true

    cout << "\n===== Less/Greater than operators =====" << endl;
    cout << "a<b: " << (a<b) << endl;   // true
    cout << "a>b: " << (a>b) << endl;   // false

    cout << "\n===== Minus operators =====" << endl;
    MyString s1 {"FRANK"};
    s1 = -s1;
    cout << "-s1: " << s1 << endl;  // frank

    cout << "\n===== Concatenation operators =====" << endl;
    s1 = s1 + "*****" + "!!!";
    cout << "s1 + \"*****\": " << s1 << endl;  // frank*****!!!

    s1 += "-----";       // frank*****!!!-----
    cout << "s1 += \"-----\": " << s1 << endl;

    MyString s2 {"12345"};
    s1 = s2 * 3;
    cout << "s1 * 3: " << s1 << endl;  // 123451234512345

    MyString s3 {"abcdef"};
    s3 *= 5;
    cout << "s3 *= 5: " << s3 << endl;  // abcdefabcdefabcdefabcdefabcdef

    MyString s4 {"SimoX"};
    s4 += (MyString {"*-*"} * 2);
    cout << "s4: " << s4 << endl;  // SimoX*-**-*

    cout << "\n===== Increment operator =====" << endl;

    MyString s = "Frank";
    ++s;
    cout << "++s: " << s << endl;  // FRANK
    
    s = -s; 
    cout << "-s: " << s << endl;   // frank
    
    MyString result;
    result = ++s;                           
    cout << "++s: " << s << endl;          // FRANK
    cout << "result: " << result << endl;  // FRANK

    s = "Frank";
    s++;
    cout << "s++: " << s << endl;  // FRANK
    
    s = -s;
    cout << "-s: " << s << endl;   // frank
    result = s++;
    cout << "s++: " << s << endl;           // FRANK
    cout << "result: " << result << endl;  // frank

    return 0;
}
