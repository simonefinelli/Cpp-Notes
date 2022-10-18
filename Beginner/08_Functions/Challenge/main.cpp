// Section 11
// Challenge
/*
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses functions.

    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.

        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the menu_mean and so forth
*/

#include <iostream>
#include <vector>

using std::cout, std::cin, std::endl, std::vector;

// Prototypes for displaying the menu and getting user selection
void display_menu();
char get_selection();
// Menu handling function prototypes
void menu_show_numbers(const vector<int> &numbers);
void menu_add_number(vector<int> &numbers);
void menu_mean(const vector<int> &numbers);
void menu_smallest(const vector<int> &numbers);
void menu_largest(const vector<int> &numbers);
void menu_find(const vector<int> &numbers);
void menu_clear(vector<int> &numbers);
void menu_quit();
void menu_unknown();
// Prototypes for functions that work with the list
void display_list(const vector<int> &list);
double calculate_mean(const vector<int> &list);
int get_smallest(const vector<int> &list);
int get_largest(const vector<int> &list);
bool find_in_list(const vector<int> &list, int target);
void clear_list(vector<int> &list);


int main() {
    char user_input;
    vector<int> numbers {};

    do {

        display_menu();

        user_input = get_selection();

        switch (user_input) {
            case 'P':
                menu_show_numbers(numbers);
                break;
            case 'A':
                menu_add_number(numbers);
                break;
            case 'M':
                menu_mean(numbers);
                break;
            case 'S':
                menu_smallest(numbers);
                break;
            case 'L':
                menu_largest(numbers);
                break;
            case 'F':
                menu_find(numbers);
                break;
            case 'C':
                menu_clear(numbers);
                break;
            case 'Q':
                menu_quit();
                break;
            default:
                menu_unknown();
        }
    } while (user_input != 'Q');

    return 0;
}

void display_menu() {
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Find a number" << endl;
    cout << "C - Clear all numbers" << endl;
    cout << "Q - Quit" << endl;
}

char get_selection() {
    // Variant that return only uppercase char

    char choice;

    cout << "Enter your choice: ";
    cin >> choice;

    return static_cast<char> (toupper(choice));
}

void menu_show_numbers(const vector<int> &numbers) {
    if (!numbers.empty()) {
        display_list(numbers);
    } else {
        cout << "[] - the list is empty" << endl;
    }
}

void menu_add_number(vector<int> &numbers) {
    int number_to_add;
    cout << "Insert an integer: ";
    cin >> number_to_add;
    numbers.push_back(number_to_add);
    cout << "Added the number: " << number_to_add << endl;
}

void menu_mean(const vector<int> &numbers) {
    if (!numbers.empty()) {
        cout << "The mean is: " << calculate_mean(numbers) << endl;
    } else {
        cout << "Unable to calculate the mean - numbers is empty!" << endl;
    }
}

void menu_smallest(const vector<int> &numbers) {
    if (!numbers.empty()) {
        cout << "The smallest number is: " << get_smallest(numbers)
             << endl;
    } else {
        cout << "Unable to determine the smallest number "
                "- numbers is empty!" << endl;
    }
}

void menu_largest(const vector<int> &numbers) {
    if (!numbers.empty()) {
        cout << "The largest number is: " << get_largest(numbers)
             << endl;
    } else {
        cout << "Unable to determine the largest number "
                "- numbers is empty!" << endl;
    }
}

void menu_find(const vector<int> &numbers) {
    if (!numbers.empty()) {
        int target;

        cout << "Insert the number to find: ";
        cin >> target;

        if (find_in_list(numbers, target))
            cout << target << " is in the list!" << endl;
        else
            cout << target << " is not in the list!" << endl;

    } else {
        cout << "List is empty!" << endl;
    }
}

void menu_clear(vector<int> &numbers) {
    if (!numbers.empty()) {
        clear_list(numbers);
        cout << "List cleaned!" << endl;
    } else {
        cout << "List empty!" << endl;
    }
}

void menu_quit() {
    cout << "Goodbye!" << endl;
}

void menu_unknown() {
    cout << "Unknown selection, please try again!" << endl;
}

void display_list(const vector<int> &list) {
    cout << "[";
    for (auto n: list) {
        cout << ' ' << n << ' ';
    }
    cout << "]" << endl;
}

/**
 * Calculate the mean of the list.
 *
 * @param list vector that contains the integers.
 * @return mean of integers.
 */
double calculate_mean(const vector<int> &list) {
    int total {};
    for (auto n : list)
        total += n;
    float mean = static_cast<float> (total) / float (list.size());

    return mean;
}

/**
 * Find the smallest integer in the list.
 *
 * @param list vector that contains the integers.
 * @return the smallest integer.
 */
int get_smallest(const vector<int> &list) {
    int smallest {list.at(0)};
    for (auto n : list)
        if (n < smallest) smallest = n;

    return smallest;
}

/**
 * Find the largest integer in the list.
 *
 * @param list vector that contains the integers.
 * @return the largest integer.
 */
int get_largest(const vector<int> &list) {
    int largest {list.at(0)};
    for (auto n : list)
        if (n > largest) largest = n;

    return largest;
}

bool find_in_list(const vector<int> &list, int target) {
    for (auto n : list) {
        if (n == target)
            return true;
    }
    return false;
}

void clear_list(vector<int> &list) {
    list.clear();
}
