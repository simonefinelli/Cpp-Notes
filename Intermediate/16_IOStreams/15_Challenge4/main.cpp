#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream in_file {"../romeoandjuliet.txt"}; // open a file
    std::ofstream out_file {"../romeoandjuliet_out.txt"}; // create a file
    if (!in_file) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }
    if (!out_file) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }

    std::string line {};
    unsigned line_counter {1};
    while (std::getline(in_file, line)) { // read the file line by line
        if (line == "\r") {  // in this file \r is in the empty line
            out_file << std::endl; // write on file empty line
        }
        else {
            out_file << std::setw(10) << std::left << line_counter << line
                     << std::endl;
            line_counter++;
        }
    }

    // close the files
    in_file.close();
    out_file.close();

    std::cout << "File copied" << std::endl;

    return 0;
}
