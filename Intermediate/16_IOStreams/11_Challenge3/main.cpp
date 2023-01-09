/*
 * Challenge 3
 * Word counter - Solution 1
 * This solution reads line by line the file text and find the occurrences
 * in the line read.
*/

#include <iostream>
#include <fstream>

using namespace std;

unsigned find_occurrences(const string &phrase, const string &word_to_find);

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
    std::string line {};
    while (std::getline(in_file, line)) {
        unsigned occurr = find_occurrences(line, word);
        total_occurrences += occurr;
    }

    // close the file
    in_file.close();

    cout << "The substring \"" << word << "\" was found " << total_occurrences
         << " times!" << endl;

    return 0;
}

/**
 * Count the number of times a word appears in a phrase
 * @param phrase Phrase to analyze.
 * @param word_to_find Word to find.
 * @return Total of occurrences found.
 */
unsigned find_occurrences(const string &phrase, const string &word_to_find) {
    size_t pos = 0;
    size_t index;
    unsigned occurrences {0};
    while((index = phrase.find(word_to_find, pos)) != string::npos) {
        pos = index + 1; // next position
        occurrences++;
    }

    return occurrences;
}
