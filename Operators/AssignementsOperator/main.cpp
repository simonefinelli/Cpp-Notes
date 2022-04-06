#include <iostream>

using namespace std;

int main() {
    // initialization
    int num1 = 10;
    int num2 = 20;
    
    // assignments
    num1 = 100;
    num2 = num1 = 42;
    
    cout << "Num1 is " << num1 << endl;
    cout << "Num2 is " << num2 << endl;
    
    /* NOT ALLOWED
     * 
     * 100 = num1;
     * 
     * const int num3 = 1;
     * num3 = 10;
     */
    
    return 0;
}