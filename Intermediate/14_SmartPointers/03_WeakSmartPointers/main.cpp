// Section 17
// Weak smart pointers

/*
 * A weak pointer provides a non-owning weak reference or weak reference to a
 * shared manage object.
 *
 * Properties:
 *  - Points to an object of type T on the heap (weak_ptr<T>)
 *  - Does not participate in owning relationship
 *  - Always created from a shared_ptr
 *  - Does not increment or decrement reference use count.
 *     So the weak pointer does NOT affect the lifetime of the objects that
 *     it is pointing to.
 *
 * Uses:
 *  1. These pointers are used to prevent strong reference cycles (circular reference),
 *      which could prevent objects from being deleted.
 *  2. When we have a pointer that we use to temporarily reference another object,
 *      we could not own them!
 *
 * Circular Reference (one-to-one relationship between classes):
 *  Class A refers to Class B  // A contains shared_ptr<B>
 *  Class B refers to Class A  // B contains shared_ptr<A>
 *
 *  With shared pointers, when the objects instantiated from A and B go out of scope
 *  they will be destroyed from the stack, but their shared resources on the heap
 *  will not be destroyed, and we have a memory leak (A keeps B alive, and B keeps
 *  A alive).
 *
 *  The solution is to make one of the pointers non-owning (weak)!
 */


#include <iostream>
#include <memory>

using namespace std;

class B;    // forward declaration (similar to function prototypes),
            // otherwise class A does not found the class B!

class A {
    std::shared_ptr<B> b_ptr;  // shared pointer to B
public:
    void set_B(std::shared_ptr<B> &b) {
        b_ptr = b;
    }
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B {
    std::weak_ptr<A> a_ptr;  // use a weak pointer to break the strong circular reference
                             // with shared_ptr, destructors never called (objs will remain on the heap - leak memory)
public:
    void set_A(std::shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};

int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);
    b->set_A(a);

    return 0;
}
