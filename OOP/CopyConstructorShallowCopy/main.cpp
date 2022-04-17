// Section 13
// Copy Constructor - Shallow Copy
// Note: this program will crash (free(): double free detected in tcache 2)
#include <iostream>

using namespace std;

/*
 * Shallow copy is the default behaviour provided by the compiler generated copy constructor.
 * Shallow copy does member-wise copying of all the objet attributes, so if we have a pointer
 * the original object and the copy both pointing to the same area on the heap; because only
 * the point address is copied.
 *
 * We can have a problem: when we release the storage in the destructor the original object
 * still refers to the released storage (program will crash (hopefully) if the program try to access
 * the released area on the heap)!
 *
 * We can use Deep Copy to prevent this!
 */

class Shallow {
private:
    int *data_ptr;  // we have a raw POINTER to an integer as data member
public:
    // Constructor
    Shallow(int d) {
        data_ptr = new int;  // allocate storage on the heap dynamically. Remember that `new` return a pointer to the allocated memory.
        *data_ptr = d;
    };
    // Copy Constructor
    Shallow(const Shallow &source)
            : data_ptr(source.data_ptr) {  // copying only the pointer address (member-wise copy)
                                   // doing this the source object and the newly created object BOTH point to the SAME
                                   // data AREA on the heap!
        cout << "Copy constructor  - shallow copy" << endl;
    };

    void set_data_value(int d) { *data_ptr = d; }
    int get_data_value() { return *data_ptr; }

    // Destructor
    ~Shallow() {
        delete data_ptr;  // free storage on the heap
        cout << "Destructor freeing data" << endl;
    }
};


void display_shallow(Shallow s) {
    cout << s.get_data_value() << endl;
}

int main() {

    Shallow obj1 {100};
    display_shallow(obj1);  // a copy of the object shallow will be created inside the function.
                               // when the function is done, the copy of the object will be destroyed and the destructor id called.
                               // so the original object now points to an invalid area of the heap.

    Shallow obj2 {obj1};
    obj2.set_data_value(1000);

    return 0;
}