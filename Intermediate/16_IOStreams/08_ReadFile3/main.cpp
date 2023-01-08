// Read data in a File using getline
#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;

    // open the file
    in_file.open("../poem.txt");
    if (!in_file) {
        std::cerr << "Problem opening file!" << std::endl;
        return 1;
    }

    // read the data
    std::string line {};
    while (std::getline(in_file, line)) {
        std::cout << line << std::endl;
    }

    // close the file
    in_file.close();

    return 0;
}