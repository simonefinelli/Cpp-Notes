// Section 12
// Dynamic Memory

#include <iostream>

using namespace std;

int main() {

    int *int_ptr = nullptr;

    int_ptr = new int;  // `new` allocate a new memory portion in the HEAP
    cout << "The address of the pointer is: " << int_ptr << endl;
    delete int_ptr;  // `delete` release the allocated space

    cout << "\n-------------------------------------\n";

    size_t size = 0;
    double *temp_ptr = nullptr;

    cout << "How many temps? ";
    cin >> size;

    // while (true) // to fill the heap
    temp_ptr = new double[size];  // the prt contains the address of the first location of the c-style array
    cout << temp_ptr << endl;

    // temp_prt = nullptr; if we run this we lost the referenciation and get into a MEMORY LEAK.
    // we can't get back the original address of the array (except if we saved it somewhere)

    delete [] temp_ptr;  // deallocate all the memory of the array

    // Furthermore, if we deallocate the memory and we try to access again at the address
    // we have un unpredictable behaviour

    return 0;
}
