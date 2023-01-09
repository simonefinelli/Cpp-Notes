/*
 * Challenge 3
 * Word counter - Solution 1
 * This solution reads word by word the file text and check if it contains
 * the word to find.
*/

#include <iostream>
#include <fstream>

using namespace std;

bool find_occurrences(const string &word_read, const string &word_to_find);

int main() {
    std::ifstream in_file;
    string word {};

    // ask the user to insert the word to find
    cout << "Enter the substring to search for: ";
    cin >> word;

    // open the file
    in_file.open("../romeoandjuliet.txt");
    if (!in_file) {
        std::cerr << "Problem opening file!" << std::endl;
        return 1;
    }

    // read the data
    unsigned total_occurrences {0};
    std::string word_read {};
    while (in_file >> word_read) {
        if (find_occurrences(word_read, word))
            total_occurrences ++;
    }

    // close the file
    in_file.close();

    cout << "The substring \"" << word << "\" was found " << total_occurrences
         << " times!" << endl;

    return 0;
}

/**
 * Check if the word is equal to another word.
 * @param word_read Word to analyze.
 * @param word_to_find Word to find.
 * @return True if the two words are equals False otherwise.
 */
bool find_occurrences(const string &word_read, const string &word_to_find) {
    size_t position = word_read.find(word_to_find);

    if (position != string::npos)
        return true;
    else
        return false;
}
