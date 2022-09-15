// Section 18
// Stack Unwinding

/*
 * Suppose we have a function and it throws an exception. If the function does not
 * handle the exception (with try/catch), then the faction terminates and it is
 * removed from the call stack. Then the C++ looks at the call stack to determine
 * the function that is at the top, since that function must have called the function
 * that just terminated. If this function used a try block, then the catch handlers
 * are checked for a match, and if one id found, it is fired, and the program continues.
 * But if there is no try block or a catch that matches, then the function is removed
 * from the call stack, and the process repeats up to the main function. If the
 * exception is not handled in the main either, then the program terminates abnormally.
 * This behaviour is called STACK UNWINDING.
 */

#include <iostream>

void func_a();
void func_b();
void func_c();

void func_a() {
    std::cout << "Starting func_a" << std::endl;
    func_b();
    std::cout << "Ending func_a" << std::endl;
}

void func_b() {
    std::cout << "Starting func_b" << std::endl;
    func_c();
    std::cout << "Ending func_b" << std::endl;
}

void func_c()  {
    std::cout << "Starting func_c" << std::endl;
    throw 100;
    std::cout << "Ending func_c" << std::endl;
}

int main() {

    std::cout << "Starting main" << std::endl;
    try {
        func_a();
    }
    catch (int &ex) {
        std::cout << "Caught error in main" << std::endl;
    }
    std::cout << "Finishing main" << std::endl;
    return 0;
}
