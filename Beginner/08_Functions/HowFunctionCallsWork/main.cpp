// Section 11
// How function calls work
// The call stack

/* What typically happens when main calls func1 (or any function calls another) ?
    There are other ways to archive the same results :)

    main:
        push space on the stack for the return value
        push space on the stack for the parameters
        push the return address (otherwise the fun can't come back)
        transfer control to func1 (jmp)
    func1:
        push the address of the previous activation record (move the stack pointer on the top)
        push any register values that will need to be restored before returning to the caller
        perform the code in func1
        restore the register values
        restore the previous activation record (move the stack pointer)
        store any function result
        transfer control to the return address (jmp)
    main:
        pop the parameters
        pop the return value
*/

#include <iostream>

using namespace std;

void func2(int &x, int y, int z) {
    x+= y + z;
}

int func1(int a, int b) {
    int result {};
    result = a + b;
    func2(result, a , b);
    return result;
}

int main() {
    int x {10};
    int y{20};
    int z{};
    z = func1(x,y);
    cout << z << endl;
    return 0;
}






