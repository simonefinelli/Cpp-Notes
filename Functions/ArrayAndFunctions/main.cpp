// Section 11
// Arrays and functions
#include <iostream>

using namespace std;

void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int value);


int main() {
    int my_scores[] {100, 98, 90, 86, 84};

    // arr is pass by reference for each example
    print_array(my_scores, 5);
    set_array(my_scores, 5, 100);
    print_array(my_scores, 5);

    cout << endl;
    return 0;
}

void print_array(const int arr[], size_t size) {  // whit const the array is read-only, and we can't change the values
    for (size_t i{0}; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // arr[0] = 50000; // compiler error

    // for (auto e : arr) {} is not possible because we don't now the end of the array
}

// set each array element to value
void set_array(int arr[], size_t size, int value) {
    for (size_t i{0}; i < size; ++i)
        arr[i] = value;
}



