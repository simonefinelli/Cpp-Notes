// Section 13
// Copy Constructor - Deep Copy
#include <iostream>

/*
 * Deep copy when we use copy constructors with pointers can resolve all problems see with shallow copy.
 * Indeed, with deep copy we don't just copy the pointer, but we copy the data_ptr pointed too.
 *
 * So with deep copy each object have a pointer to own data_ptr storage in the heap.
 */

using namespace std;

class Deep {
private:
    int *data_ptr;  // a raw pointer
public:
    // Constructor
    Deep(int d) {
        data_ptr = new int;
        *data_ptr = d;
    }
    // Copy Constructor
    Deep(const Deep &source)
            : Deep {*source.data_ptr} {
        /*
         * The delegating constructor substitute the following code:
         *
         * data = new int;  // allocate new storage on the heap
         * *data = *source.data_ptr;  // copy data
         */

        cout << "Copy constructor  - deep copy" << endl;
    }

    void set_data_value(int d) { *data_ptr = d; }
    int get_data_value() { return *data_ptr; }

    // Destructor
    ~Deep() {
        delete data_ptr;
        cout << "Destructor freeing data_ptr" << endl;
    }
};



void display_deep(Deep s) {
    cout << s.get_data_value() << endl;
}  // So in this case we have an exact UNIQUE COPY of the original object
   // Therefor no problems like swallow copy when we call destructor!

int main() {

    Deep obj1 {100};
    display_deep(obj1);

    Deep obj2 {obj1};

    obj2.set_data_value(1000);

    return 0;
}
