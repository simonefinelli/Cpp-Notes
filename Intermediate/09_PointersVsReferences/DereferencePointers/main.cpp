// Section 12
// Dereferencing Pointers

/**
 * Dereferencing a pointer -> Access the data we're pointing to
 * `*` is the dereferencing operator
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int score = 100;
    int *score_prt = &score;
    cout << *score_prt << endl;

    *score_prt = 200;
    cout << *score_prt << endl;
    cout << score << endl;

    cout << "\n-------------------------\n" << endl;

    double high_temp = 100.7;
    double low_temp = 37.4;
    double *temp_ptr;

    temp_ptr = &high_temp;
    cout << *temp_ptr << endl;

    temp_ptr = &low_temp;
    cout << *temp_ptr << endl;

    cout << "\n-------------------------\n" << endl;

    string name = "Frank";
    string *string_prt = &name;

    cout << *string_prt << endl;
    name = "James";
    cout << *string_prt << endl;

    cout << "\n-------------------------\n" << endl;

    vector<string> stooges = {"Larry", "Moe", "Curly"};
    vector<string> *vector_prt;

    vector_prt = &stooges;

    cout << "First stooge: " << (*vector_prt).at(0) << endl;  // parentheses are needed because of priority behavior. Indeed, `.` has a higher precedence than `*` (dereference operator)
                                                                 // vector_prt->at(0) also works

    cout << "Stooges: ";
    for (const string &stooge : *vector_prt) {
        cout << stooge << " ";
    }
    cout << endl;


    return 0;
}
