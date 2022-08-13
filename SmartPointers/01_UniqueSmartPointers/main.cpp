// Section 17
// Unique smart pointers

/*
 * The Unique Pointer is a simple smart pointer that is VERY EFFICIENT and can
 * be used in typical pointer use case.
 *
 * The idea is simple: allocate storage, use it and then free.
 *
 * Properties:
 *  - Points to an object of type T on the heap (unique_ptr<T>)
 *  - It is unique: there can only be one pointing to the object on the heap
 *  - Strong ownership relationship between the pointer and what it points to
 *  - Cannot be copied or assigned: copy constructors and copy assignment operators are not available.
 *       vector<unique_ptr<int>> v;
 *       unique_ptr<int> ptr {new int {42}};
 *       v.push_back(ptr);  // ERROR - copy not allowed
 *       v.push_back(move(ptr));  // ptr lose the ownership of the pointer and pass the ownership to the vector.
 *                                // ptr will be set to null pointer!
 *  - Can be moved
 *  - When the pointer is destroyed (out of scope), what it points to is automatically destroyed (property of unique)
 *
 *  Useful methods:
 *   - .get() returns the address of the pointer
 *   - .reset() sets a pointer to nullptr (can be useful in some case)
 *
 *  Best way to INITIALIZE the Unique Pointer (C++ 14)
 *   unique_ptr<int> p1 = make_unique<int>(100);
 *   unique_ptr<Account> p2 = make_unique<Account>("Curly", 5000);
 *   auto p3 = make_unique<Player>("Hero", 100, 100);
 */

#include <iostream>
#include <memory>  // for smart pointers
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
    Test(int d)
        : data {d} {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }
    int get_data() const {
        return data;
    }
    ~Test() {
        std::cout << "Test destructor (" << data << ")" << std::endl;
    }
};

using namespace std;

int main() {
//    cout << "Normal Declaration" << endl;
//    Test t {42};
//
//    cout << "\nRaw Pointer" << endl;
//    Test *t1 = new Test {10};
//    delete t1;

//    cout << "Unique Pointers" << endl;
//    unique_ptr<Test> t2 {new Test {100}};  // note the destructor call in the terminal
//    auto t3 = make_unique<Test>(1'000);
//
//    std::unique_ptr<Test> t4;  // the pointer is pointing to nullptr (nowhere)
//    // t4 = t2;  // compiler error: assign not allowed!
//    t4 = std::move(t2);  // t2 lost the ownership, the ownership is moved to t4
//    if(!t2)
//        cout << "t2 is nullptr now!" << endl;

    cout << "Unique Pointers for Account Classes" << endl;

    unique_ptr<Account> a1 = make_unique<CheckingAccount>("Frodo", 42'000);  // if we use auto now, we can't take advantage of dynamic polymorphism!
    cout << *a1 << endl;
    a1->deposit(42);
    cout << *a1 << endl;

    cout << "\nUsing vector" << endl;
    vector<unique_ptr<Account>> accounts {};
    accounts.push_back(make_unique<CheckingAccount>("Sam", 1000));
    accounts.push_back(make_unique<SavingsAccount>("Gandalf", 100'000, 0.73));
    auto bilbo_account = make_unique<TrustAccount>("Bilbo", 1'000'000, 10.5);
    accounts.push_back(move(bilbo_account));

    for (const unique_ptr<Account> &a : accounts) {
        cout << *a << endl;
    }
    // TIP: the reference (&a) is important,
    // otherwise C++ compiler tries to make a copy and a compiler error will raise!

    return 0;
}
