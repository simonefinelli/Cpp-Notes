// Section 9
// For loop

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
//    for (int i {}; i < 10; i++)
//        cout << i << endl;
    
//    for (int i {100}; i < 300; i+=50)
//        cout << i << endl;

//    for (int i {10}; i > 0; i--)
//        cout << i << endl;

//    for (int i {10}; i <= 100; i+=10) {
//        if (i % 15 == 0)
//            cout << i << endl;
//    }

//    for (int i {}, j {8}; i <= 5; i++, j--)
//        cout << i << " + " << j << " = " << i + j << endl;

//    for (int i {1}; i <= 100; i++) {
//        cout << i << " ";
//        if (i % 10 == 0)
//            cout << endl;
//    }
//    
//    cout << endl;
//    
//    // same as before
//    for (int i {1}; i <= 100; i++)
//        cout << i << ((i % 10 == 0) ? "\n" : " ");

    vector<int> nums {10, 20, 30, 40, 50};
    
    for (unsigned i {}; i < nums.size(); i++)
        cout << nums.at(i) << endl;
    
    cout << endl;
    return 0;
}