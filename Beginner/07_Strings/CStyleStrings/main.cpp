#include <iostream>
#include <cstring>  // for c-style string functions
#include <cctype>  // for character-based functions

using namespace std;

int main() {
    char first_name[20] {};
    char last_name[20] {};
    char full_name[50] {};
    char temp[50] {};

//    cout << "Please enter your first name: ";
//    cin >> first_name;
//    cout << "Please enter your last name: ";
//    cin >> last_name;
//
//    cout << "Hello, " << first_name << " your first name has "
//         << strlen(first_name) << " characters." << endl;
//    cout << "and your last name, " << last_name << " has "
//         << strlen(last_name) << " characters." << endl;
//
//    strcpy(full_name, first_name);
//    strcat(full_name, " ");
//    strcat(full_name, last_name);
//    cout << "Your full name is: " << full_name << endl;

    cout << "Enter your full name: ";
    cin.getline(full_name, 50);  // we can read the string also with space
    cout << "Yuor full name is " << full_name << endl;

    if (strcmp(full_name, "simox f") == 0)
        cout << "The strings are equal!" << endl;
    else
        cout << "The strings are not equal!" << endl;

    for (size_t i {0}; i < strlen(full_name); i++) {
        if (isalpha(full_name[i]))
            full_name[i] = toupper(full_name[i]);
    }
    cout << "Your full name is " << full_name << endl;
    cout << endl;

    strcpy(temp, "alex");
    strcpy(full_name, "zlex");
    cout << "Result of comparing " << temp << " and " << full_name << ": " << strcmp(temp, full_name) << endl;
    cout << "Result of comparing " << full_name << " and " << temp << ": " << strcmp(full_name, temp) << endl;

    /*
     * strcmp return < 0 if the first string lessically became before the second string
     * strcmp return > 0 if the first string lessically became after the second string
     * strcmp return 0 if the strings are the same
     *
     * - From doc
     * It  returns an integer less than, equal to, or greater than
     * zero if s1 is found, respectively, to be less than,  to  match,  or  be
     * greater than s2.
     */

    cout << endl;
    return 0;
}
