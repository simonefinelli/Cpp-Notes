// Section 12
// Simple Pointers

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int num = 10;
    cout << "Value of num is: " << num << endl;
    cout << "The sizeof of num is: " << sizeof num  << " bytes" << endl;
    cout << "Address of num is: " << &num << endl;

    cout << endl;

    int *p;  // read like: p is a pointer to an integer
    cout << "Value of p is ADDRESS: " << p << endl;
    cout << "The sizeof of p is : " << sizeof p  << " bytes" << endl;  // the number of bytes that are used to store a pointer
    cout << "Address of p is: " << &p << endl;
    p = nullptr;  // the address nullprt point nowhere
    cout << "Now value of p is ADDRESS: " << p << endl;

    cout << endl;

    int *p1 = nullptr;
    double *p2 = nullptr;
    unsigned long long *p3 = nullptr;
    vector<string> *p4 = nullptr;
    string *p5 = nullptr;
    cout << "The sizeof of p1: " << sizeof p1  << " bytes" << endl;
    cout << "The sizeof of p2: " << sizeof p2  << " bytes" << endl;
    cout << "The sizeof of p3: " << sizeof p3  << " bytes" << endl;
    cout << "The sizeof of p4: " << sizeof p4  << " bytes" << endl;
    cout << "The sizeof of p5: " << sizeof p5  << " bytes" << endl;

    cout << endl;

    int score = 10;
    double high_temp = 100.7;
    int *score_ptr;

    score_ptr = &score;
    cout << "Value of score is: " << score << endl;
    cout << "Address of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << " (address of score)" << endl;

//    score_ptr = &high_temp;  // compiler error `cannot convert ‘double*’ to ‘int*’ in assignment`

    return 0;
}
