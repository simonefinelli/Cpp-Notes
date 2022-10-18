// Section 9
// Range based for loop

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    
//    int scores[] {10, 20, 30};
//    
//    for (int score : scores)
//        cout << score << endl;
//        
//    cout << endl;
//    
//    // same as before
//    for (auto score : scores)
//        cout << score << endl;

//    vector<double> tempetatures {13.3, 23.08, 20.78};
//    double total {};
//    
//    for (auto temp : tempetatures)
//        total += temp;
//    
//    cout << fixed << setprecision(1);
//    cout << "Average temp: " 
//         << ((total != 0.0) ? total / tempetatures.size() : 0)
//         << endl;
    
    for (auto c : "This is a string!")
        cout << c << endl;
    
    cout << endl;
    return 0;
}