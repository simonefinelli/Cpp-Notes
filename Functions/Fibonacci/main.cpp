// Section 11
// Recursion - Fibonacci
#include <iostream>

using namespace std;
// Section 11
// Recursion - Fibonacci

#include <iostream>

using namespace std;
unsigned long long fibonacci(unsigned long long n);

int main() {
    unsigned long long fib5 = fibonacci(20);   // 5
    // cout << fibonacci(30) << endl;	// 832040
    // cout << fibonacci(40) << endl; // 102334155

    cout << "\nFibonacci of 5 is: " << fib5 << endl;   // 5
    return 0;
}

unsigned long long fibonacci(unsigned long long n) {
    static unsigned counter = 0;
    cout << "Function called the " << ++counter << " time!" << '\n';  // \n is faster than endl
    if (n <= 1)
        return n;	             // base cases
    return fibonacci(n-1) + fibonacci(n-2); // recursion
}
