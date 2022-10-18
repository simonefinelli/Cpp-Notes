// Section 12
// Challenge

/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes

  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.

  The function should return a pointer to the newly allocated array.

  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.

  For example,

  Below is the output from the following code which would be in main:

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    cout << "Array 1: " ;
    print(array1,5);

    cout << "Array 2: " ;
    print(array2,3);

    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);

   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/

#include <iostream>

using namespace std;

// prototypes
void print(const int *arr1, size_t arr1_length);
int *apply_all(const int *arr1, size_t arr1_length, const int *arr2, size_t arr2_length);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    cout << "Array 1: \n";
    print(array1,array1_size);

    cout << "\nArray 2: \n";
    print(array2,array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "\nResult: \n" ;
    print(results, results_size);

    delete [] results;  // release memory from the heap

    return 0;
}

void print(const int *const arr1, size_t arr1_length) {  // we could use reference instead of pure pointers

    for (size_t i = 0; i < arr1_length; i++)
        cout << *(arr1 + i) << " ";  // arr1[i] works fine and is called pointer-subscript notation. Instead *(arr1 + i) is called pointer-offset notation
    cout << endl;

    // with the two const parameters we can't do these:
    // arr1 = nullptr; // we can't assign another pointer
    // arr1[3] = 100;  //we can't assign another int

}

int *apply_all(const int *const arr1, size_t arr1_length,
               const int *const arr2, size_t arr2_length) {

    // allocate new memory on the heap for the new array
    int *new_arr;  // pointer that will point to new memory allocation
    new_arr = new int [arr1_length * arr2_length]; // we allocate 15 integers on the heap

    size_t index = 0;
    for (size_t i = 0; i < arr2_length; i++)
        for (size_t j = 0; j < arr1_length; j++) {
            new_arr[index] = *(arr2 + i) * *(arr1 + j);  // arr2[i] * arr1[j]
            index++;
        }

    return new_arr;
}

