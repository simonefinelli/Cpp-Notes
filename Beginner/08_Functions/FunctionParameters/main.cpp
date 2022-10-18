// Section 11
// Function Parmameters
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Prototypes
void pass_by_value1(int num);
void pass_by_value2(string s);
void pass_by_value3(vector<string> v);
void print_vector(vector<string> v);

int main() {
    int num {10};
    int another_num {20};

    cout << "num before calling pass_by_value1: " << num << endl;
    pass_by_value1(num); // num here is an argument and is called Actual Param
    cout << "num after calling pass_by_value1: " << num << endl;

    cout << "\nanother_num before calling pass_by_value1: " << another_num << endl;
    pass_by_value1(another_num);
    cout << "another_num after calling pass_by_value1: " << another_num << endl;

    string name {"Frank"};
    cout << "\nname before calling pass_by_value2: " << name << endl;
    pass_by_value2(name);
    cout << "name after calling pass_by_value2: " << name << endl;

    vector<string> stooges {"Larry", "Moe", "Curly"};
    cout << "\nstooges before calling pass_by_value3: ";
    print_vector(stooges);
    pass_by_value3(stooges);
    cout << "stooges after calling pass_by_value3: ";
    print_vector(stooges);

    cout << endl;
    return 0;
}

void pass_by_value1(int num) {  // num here is a parameters and is called Formal Param
    num = 1000;
}

void pass_by_value2(string s) {
    s = "Changed";
}

void pass_by_value3(vector<string> v) {  // Also vectors are passed by value by default
    v.clear();  // delete all vector elements
}

void print_vector(vector<string> v) {
    for (auto s: v)
        cout << s << " ";
    cout << endl;
}
