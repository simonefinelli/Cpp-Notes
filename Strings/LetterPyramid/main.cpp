/*
 * Write a C++ program that displays a Letter Pyramid.
 * Prompt the user to enter a string and then from that string display a Letter Pyramid as follows:
 *
 * Input string "ABC"
 *
 *    A
 *   ABA
 *  ABCBA
 *
 *  Written by SimoX
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input_string {};

    cout << "Enter a string: ";
    cin >> input_string;

    size_t n_spaces {input_string.size() - 1};

    for (size_t i {0}, offset {1}; i < input_string.size(); i++, offset++) {

        // print initial spaces
        int s {};
        while (s < n_spaces) {
            cout << " ";
            s++;
        }

        // print chars sequence
        for (size_t j {0}; j < offset; j++)
            cout << input_string.at(j);
        for (size_t k {i}; k > 0; k--)
            cout << input_string.at(k - 1);
        cout << endl;

        n_spaces--;
    }

    return 0;
}
