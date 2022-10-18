/*
 * Challenge on Vectors
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> vector1;
    vector<int> vector2;
    
    vector1.push_back(10);
    vector1.push_back(20);
    cout << "Vector 1 has " << vector1.size() << " elements. The values are: ";
    cout << vector1.at(0) << " " << vector1.at(1) << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    cout << "Vector 2 has " << vector1.size() << " elements. The values are: ";
    cout << vector2.at(0) << " " << vector2.at(1) << endl;
    
    vector<vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    cout << "\nVector 2D contains: \n"
        << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl
        << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    
    
    vector1.at(0) = 1000;
    cout << "\nVector 1 now contains: "
        << vector1.at(0) << " " << vector1.at(1) << endl;
    
    cout << "\nVector 2D now contains: \n"
        << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl
        << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    
    
    return 0;
}