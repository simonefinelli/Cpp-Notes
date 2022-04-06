/*
 * Vectors
 */
 
 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 int main() {
    
    // vector <char> vowels;  // empty vector
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};  // syntax used by cppreference.com
    cout << vowels[0] << endl;
    cout << vowels.at(4) << endl;
    
    // vector <int> test_scores (3);  // 3 elements all initialized to 0
    // vector <int> test_scores (3, 100);  // 3 elements all initialized to 100
    vector<int> test_scores {100, 98, 89};
    // cout << test_scores[4] << endl; // won't throw an exception
    // cout << test_scores.at(4) << endl;  // will throw an exception
    cout << "The vector has " << test_scores.size() << " elements." << endl;
    cout << "The elements are:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    
    cout << "\nEnter 3 test scores: ";
    cin >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);
    
    cout << "New test scores:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    
    int new_test_score = 0;
    cout << "\nEnter a test score to add to the vector: ";
    cin >> new_test_score;
    
    test_scores.push_back(new_test_score);
    
    cout << "\nTest scores are now: " << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << "The vector now has " << test_scores.size() << " elements." << endl;
    

    // Example with 2D-vector
    vector<vector<int>> movie_ratings =
    {
        {1, 2, 3},
        {5, 2, 1},
        {5, 4, 5}
    };
    
    cout << "\nHere are some ratings:" << endl;
    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings.at(2).at(2) << endl;
    
    
    return 0;
 }