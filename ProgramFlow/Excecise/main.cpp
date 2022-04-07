// Coding exercise 17
#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> vec {1, 2, 3};
    
    int result {0};
    
    if (vec.size() == 0 or vec.size() == 1) {
         result = 0;
    } else {
        for (size_t i {0}; i < vec.size(); i++) {
            for (size_t j {i+1}; j < vec.size(); j++) {
                 result += vec.at(i) * vec.at(j);
                 cout << i << j << endl;
            }
        }
    }
    
   cout<<"result: " << result << endl;
   return 0;
}