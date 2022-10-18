#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    string s0;
    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {"Kiwi"};
    string s4 {"apple"};
    string s5 {s1};  // Apple
    string s6 {s1, 0, 3};  // App
    string s7 (10, 'X');  // XXXXXXXXXX

//    cout << s0 << endl;             // no garbage
//    cout << s0.length() << endl;    // empty string

// Initialization
//    cout << "\nInitialization " << "\n------------------------------------------" << endl;
//    cout << "S1 is initialized to: " << s1 << endl;
//    cout << "S2 is initialized to: " << s2 << endl;
//    cout << "S3 is initialized to: " << s3 << endl;
//    cout << "S4 is initialized to: " << s4 << endl;
//    cout << "S5 is initialized to: " << s5 << endl;
//    cout << "S6 is initialized to: " << s6 << endl;
//    cout << "S7 is initialized to: " << s7 << endl;

// Comparison
//    cout << "\nComparison" << "\n------------------------------------------" << endl;
//    cout << boolalpha;
//    cout << s1  << " == " << s5 << ": " << (s1 == s5) << endl; 		            // True    Apple == Apple
//    cout << s1  << " == " << s2 << ": " << (s1 == s2) << endl;	            	// False   Apple != Banana
//    cout << s1  << " != " << s2 << ": " << (s1 != s2) << endl;		            // True    Apple != Banana
//    cout << s1  << " < " << s2 << ": " << (s1 < s2) << endl;;		            // True         Apple < Banana
//    cout << s2  << " > " << s1 << ": " <<(s2 > s1) << endl;		                // True         Banana > Apple
//    cout << s4  << " < " << s5 << ": " <<(s4 < s5) << endl;		                // False        apple >Apple
//    cout << s1  << " == " << "Apple" << ": " <<(s1 == "Apple") << endl;;	    // True Apple == Apple
//                                                                                // here "Apple" is a c-style
//                                                                                // literal (string constant)

// Assignment
//    cout << "\nAssignment" << "\n------------------------------------------" << endl;
//
//    s1 = "Watermelon";
//    cout << "s1 is now: " << s1 << endl;    // Watermelon
//    s2 = s1;
//    cout << "s2 is now: " << s2 << endl;    // Watermelon
//
//    s3 = "Frank";
//    cout << "s3 is now: " << s3 << endl;    // Frank
//
//    s3[0] = 'C';    // Crank
//    cout << "s3 change first letter to 'C': "  << s3 << endl;   // Crank
//    s3.at(0) = 'P';
//    cout << "s3 change first letter to 'P': "  << s3 << endl;   // Prank

// Concatenation

//    s3 = "Watermelon";
//    cout << "\nConcatenation" << "\n------------------------------------------" << endl;
//
//    s3 =  s5 + " and " + s2 + " juice";     // Apple and Banana juice
//    cout << "s3 is now: " << s3 << endl;    // Apple and Banana Juice

//    s3 = "nice " + " cold " + s5 + "juice";         // Compiler error

//  for loop
//    cout << "\nLooping" << "\n------------------------------------------" << endl;
//
//    s1 = "Apple";
//    for (size_t i {0}; i < s1.length(); ++i) {
//        char upper_letter = static_cast<char> (toupper(s1.at(i)));
//        cout << upper_letter << endl;      //  or s1[i]    APPLE
//    }

// Range-based for loop
//    for (char c : s1)
//        cout << c << endl;     // Apple

// Substring
//    cout << "\nSubstring" << "\n------------------------------------------" << endl;
//    s1 = "This is a test";
//
//    cout << s1.substr(0,4) << endl;	    // This
//    cout << s1.substr(5,2) << endl;	    // is
//    cout << s1.substr(10,4) << endl;   	// test
//    cout << s1.substr(18,4) << endl;   	// 'std::out_of_range' in compiling time

// Insert
//    cout << "\nInsert" << "\n------------------------------------------" << endl;
//    s1 = "NoSpace";
//
//    cout << s1.insert(2, " ") << endl;	    // No Space

// Swap
//    cout << "\nSwap" << "\n------------------------------------------" << endl;
//    s1 = "s1 string";
//    s2 = "s2 string";
//
//    s2.swap(s1);
//
//    cout << "S1 now is: " << s1 << endl;
//    cout << "S2 now is: " << s2 << endl;

// Erase
//    cout << "\nErase" << "\n------------------------------------------" << endl;
//
//    s1 = "This is a test";
//    s1.erase(0,5);     // Erase This from s1 results in "is a test"
//    cout << "s1 is now: " << s1<< endl;     // is a test

// getline
//    cout << "\nGetline" << "\n------------------------------------------" << endl;
//
//    string full_name {};
//
//    cout << "Enter your full name: ";
//    getline(cin, full_name);
//
//    cout << "Your full name is: " << full_name << endl;

// Find
    cout << "\nfind" << "\n------------------------------------------" << endl;

    s1 = "The secret word is Boo";
    string word {};

    cout << "Enter the word to find: ";
    cin >> word;

    size_t position = s1.find(word);
    if (position != string::npos)  // use string::npos to check if no index are found
        cout << "Found " << word << " at position: " << position << endl;
    else
        cout << "Sorry, " << word <<  " not found" << endl;

    return 0;
}
