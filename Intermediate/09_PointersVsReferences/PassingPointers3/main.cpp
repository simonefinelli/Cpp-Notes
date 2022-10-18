// Section 12
// Passing Pointers 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<string> *const  v) {  // v is a constant pointer that points a constant vector
    // (*v).at(0) = "Funny";  // with const we get a compiler error

    for (const string &str : *v)  // *v we dereference the pointer to get the collection (vector of names)
        cout << str << " ";
    cout << endl;

    // v = nullptr;  // memory leak
}

void display(int *array, int sentinel) {
    while (*array != sentinel)
        cout << *array++ << " ";
    cout << endl;
}

int main() {

    cout << "-----------------------------" << endl;
    vector<string> stooges {"Larry", "Moe", "Curly"};
    display(&stooges);

    cout << "\n-----------------------------" << endl;
    int scores[] {100,98,97,79,85,-1};
    display(scores, -1);

    cout  << endl;
    return 0;
}

