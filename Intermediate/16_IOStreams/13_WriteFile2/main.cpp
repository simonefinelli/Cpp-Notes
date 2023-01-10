// Section 19
// Write File 2 - copy an existing file in another new file

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream in_file {"../poem.txt"}; // open a file
    std::ofstream out_file {"../poem_out.txt"}; // create a file
    if (!in_file) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }
    if (!out_file) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }

    std::string line {};
    while (std::getline(in_file, line)) // read the file line by line
        out_file << line << std::endl; // write on file

    // close the files
    in_file.close();
    out_file.close();

    std::cout << "File copied" << std::endl;

    return 0;
}
