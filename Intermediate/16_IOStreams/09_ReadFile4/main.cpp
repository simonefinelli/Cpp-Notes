// Read data in a File using unformatted get (char by char)
#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;

    // open the file
    in_file.open("../poem.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    // read the data
    char c {};
    while (in_file.get(c)) {  // get one character at a time
        std::cout << c;
    }
    std::cout << std::endl;

    // close the file
    in_file.close();

    return 0;
}