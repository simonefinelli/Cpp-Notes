// Section 17
// Shared smart pointers

/*
 * The shared pointer is a smart pointer that provides a shared ownership of the objects on the heap.
 *
 * Properties:
 *  - Points to an object of type T on the heap (shared_ptr<T>)
 *  - It is NOT unique: there can many shred_ptr pointing to the same object on the heap.
 *  - Shared ownership relationship
 *  - Can be assigned and copied (note that we copy the pointers address not the objects that they are pointing)
 *  - Can be moved (for efficiency)
 *  - Do not support managing arrays by default
 *  - To take trace of all the pointers instantiated, we use a counter (reference counting).
 *     When the reference count becomes 0 we can safely destroy the pointer.
 *
 * Declaration:
 *  shared_ptr<int> p1 {new int {42}};
 *  shared_ptr<Account> p2 = {new Account {"Larry"}};
 *  auto p3 = make_shared<T>();  // since C++ 11, despite make_unique<>() (C++ 14)
 *
 * Useful methods:
 *  ptr.use_count() returns the number of shared pointers that are currently referring to the heap object.
 */

#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "SavingsAccount.h"

class Test {
private:
    int data;
public:
    Test()
        : data {0} {
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


void display(std::shared_ptr<Test> p) {
    std::cout << "Use count: " << p.use_count() << std::endl;  // 2
}

using namespace std;

int main() {
//    shared_ptr<int> p1 {new int {100}};
//    cout << "Use count: "<< p1.use_count () << endl;  // 1
//
//    shared_ptr<int> p2 {p1}; // shared ownership - we are using copy constructor
//    cout << "Use count p1: "<< p1.use_count () << endl;  // 2 - because now p1 and p2 are referencing the same int
//    cout << "Use count p2: "<< p2.use_count () << endl;  // 2 - same result (as expected)
//
//    p1.reset();	// p1 is nulled out (p1 == nullptr): use_count is decremented;
//    cout << "Use count p1 after reset: "<< p1.use_count() << endl;  // 0
//    cout << "Use count p2 after reset: "<< p2.use_count() << endl;  // 1 - p2 is still referring to the int
//                                                                    // when p2 goes out of scopes the int is deallocated

//    cout << "\n==========================================" << endl;
//
//    shared_ptr<Test> ptr = make_shared<Test>(100);
//    display(ptr);  // by copy
//    cout << "1. Use count: " << ptr.use_count() << endl;  // 1
//
//    {
//        shared_ptr<Test> ptr1 = ptr;
//        cout << "2. Use count: " << ptr.use_count() << endl;  // 2
//        {
//            shared_ptr<Test> ptr2 = ptr;
//            cout << "3. Use count: " << ptr.use_count() << endl;  // 3
//            ptr.reset();  // ptr is nulled out
//        }
//        cout << "4. Use count: " << ptr1.use_count() << endl;  // 1
//        cout << "5. Use count: " << ptr.use_count() << endl;  // 0
//    }
//    cout << "6. Use count: " << ptr.use_count() << endl;  // 0

    cout << "\n==========================================" << endl;

    shared_ptr<Account> acc1 = make_shared<TrustAccount>("Frodo", 10000, 3.1);
    shared_ptr<Account> acc2 = make_shared<CheckingAccount>("Bilbo", 5000);
    shared_ptr<Account> acc3 = make_shared<SavingsAccount>("Gandalf", 6000);

    vector<shared_ptr<Account>> accounts {};
    accounts.push_back(acc1);  // copy - another shared pointer is created (shared ownership)
    accounts.push_back(acc2);  // copy - another shared pointer is created (shared ownership)
    accounts.push_back(acc3);  // copy - another shared pointer is created (shared ownership)

    for (const auto &acc: accounts) {
        cout << *acc << endl;
        cout << "Use count: " << acc.use_count() << endl;
    }
    /*
     * Now, the vector goes out of scope first, so it is going to be destroyed;
     * but the Trust, Checking and Savings Account on the heap, will not be destroyed yet.
     * Indeed, first the shared pointers in the vector are destroyed (now count
     * will be 1 for each shared pointers), than the Account objects,
     * pointing by acc1, acc2 and acc3 shared pointers, will be deallocated from the heap!
     */

    cout << "==========================================" << endl;

    return 0;
}
