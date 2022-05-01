// Section 13
// Move Constructor

/*
 * Refresh L-value and R-value:
 *      when you can refer to an object by name, or you
 *      can follow a pointer to get to an object, then that object is addressable,
 *      i.e. it's an L-VALUE; R-VALUES are everything else.
 *
 * In the context of MOVE SEMANTICS r-values refer to temporary objects that are
 * created by the compiler and objects returned from methods.
 * To reference an r-value we can use &&.
 *
 * For example, in the instruction:
 *      sum = 42 + 100;
 * 42 + 100 is evaluated and 142 is stored in an unnamed temporary value (this value is not addressable: r-value)
 * the r-value is then assigned to the l-value (sum).
 * With objects we have the same behavior, but with a lot of overhead if copy constructors are called
 * over and over, making copies of these temporary objects.
 *
 * So, R-value objects are the objects that move semantics addresses.
 *
 *
 * When copy constructors are called the compiler have to make a copy of the object (with deep copy
 * allocate new memory too) and that is computationally expensive!
 * The move constructor MOVES the object rather than copies it: this can be
 * extremely EFFICIENT!
 *
 * If we don't provide move constructors the copy constructor is called!
 *
 * TIP: use move constructor for efficiency.
 *
 * TIP: sometime we might not see the move constructors (sometime also for copy constructors) being called in the debugger.
 *  This is due to copy illusion (a compiler optimization the eliminates unnecessary copying).
 *  Another optimization is the RVO (Return Value Optimization): the compiler generates code that doesn't create a copy
 *  every return value form a function.
 *
 * Difference between l-value and r-value
 *  int x = 42;
 *
 *  int &l_ref = x;  // l-value reference
 *  l_ref = 10;      // change x to 10
 *
 *  int &&r_ref = 100;  // r-value reference
 *  r_ref = 200         // change r_ref to 200 - we just change the temporary variable
 *
 *  int &&x_ref = x;  // compiler error
 *
 * With Functions:
 *  int x = 42;  // x is an l-value
 *  void foo(int &n);
 *
 *  func(x);   // GOOD - x is an l-value
 *  func(10);  // BAD - 10 is an r-value -> compiler error: cannot bind non-const lvalue reference of type 'int&'to an rvalue of type 'int'
 *
 *  void foo1(int &&n);
 *
 *  func(x);    // BAD - x is an l-value
 *  func(100);  // GOOD - 100 is an r-value -> compiler error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
 */

#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int *data;  // raw pointer
public:
    // Constructor
    Move(int d);
    // Copy Constructor
    Move(const Move &source);
    // Move Constructor
    Move(Move &&source) noexcept;

    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }

    // Destructor
    ~Move();
};

Move::Move(int d)  {
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

// Copy ctor
Move::Move(const Move &source)
        : Move {*source.data} {
    cout << "Copy constructor  - deep copy for: " << *data << endl;
}

// Move ctor
Move::Move(Move &&source) noexcept  // move constructor simply move the resource that's on the heap (no copy)
        : data {source.data} {  // we stole the data
    source.data = nullptr;  // and than we set null out the source pointer
                            // this step is important, otherwise we end up like shallow copy
                            // TIP: we set null the temporary pointer that points to the r-value not the value of the origin al class
                            //      so we just destroy the object that we just moved setting its data pointer to null.
    cout << "Move constructor - moving resource: " << *data << endl;
}

Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

int main() {
    vector<Move> vec;

    vec.push_back(Move(10));  // without move constructor Move(N) is creating temporary objects, they are unnamed
                                 // (they are going to be R-values)
                                 // if the compiler is going to use the copy constructor we have several deep copies (inefficient)
                                 // Using the move constructor the compiler simply 'moves' the resource that's on the heap
                                 // Indeed, compiler copies the address of the resource (temporary r-value) from source to the current object and,
                                 // nulls out the pointer in the source pointer

    vec.push_back(Move(20));  // because 10,20,30,etc. are r-values the move constructors are called, so we avoid deep copies and
                                 // all is much more efficient
    vec.push_back(Move(30));
    vec.push_back(Move(40));
    vec.push_back(Move(50));
    vec.push_back(Move(60));
    vec.push_back(Move(70));
    vec.push_back(Move(80));


    return 0;
}