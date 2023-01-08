// Read data in a File
#include <iostream>
#include <fstream>  // to work with files

int main() {
    std::ifstream in_file;  // ifstream open the file in read mode
    std::string word;
    int num;
    double total;

    // open the file
    in_file.open("../test.txt");  // ../ because the executable is on debug dir

    // check if the file was opened correctly
    if (!in_file) {
        std::cerr << "Problem opening file!" << std::endl;
        return 1;
    }

    // read the content of the file
    in_file >> word >> num >> total;
    std::cout << word << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;

    // close the file
    in_file.close();

    return 0;
}
