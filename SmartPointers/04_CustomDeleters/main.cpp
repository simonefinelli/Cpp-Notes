// Section 17
// Custom deleters for smart pointers

/*
 * Custom deleters are called when smart pointers are destroyed.
 *
 * Sometimes when we destroy a smart pointer, we need more than to just destroy
 * the object on the heap.
 *
 * These are a special use-cases (we will not run into very often)
 *
 * If we use custom deleters we cannot use make_share or make_unique for the creation.
 * That because if we have to provide a special deleter, maybe we need a specialized way
 * to create them too!
 *
 * We can provide custom deleters by:
 *  - Functions
 *  - Lambdas
 *  - and so on ...
 */

#include <iostream>
#include <memory>

class Test {
private:
    int data;
public:
    Test()
        : data{0} {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }
    Test(int data)
        : data {data} {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }
    int get_data() const {
        return data;
    }
    ~Test() {
        std::cout << "Test destructor (" << data << ")" << std::endl;
    }
};

void my_deleter(Test *ptr) {  // using raw pointer to manage to object that the smart pointer is referencing
    std::cout << "Using my custom function deleter" << std::endl;
    // ...
    // custom code
    // ...
    delete ptr;
}

int main() {

    {
        // Custom destruction using a function
        std::shared_ptr<Test> ptr1 {new Test{42}, my_deleter};  // the function my_deleter will be called when the
                                                                 // smart pointer will be out of scope.
    }

    std::cout << "==============================" << std::endl;

    {
        // Custom destruction using a Lambda Expression
        std::shared_ptr<Test> ptr2 (new Test{10}, [] (Test *ptr)
            {
                std::cout << "Using my custom lamdba deleter" << std::endl;
                // ...
                // custom code
                // ...
                delete ptr;
            }
        );
    }

    return 0;
}