// Section 19
// Write File 2 - copy an existing file in another new file (char by char)

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

    char c;
    while (in_file.get(c)) // read the file char by char
        out_file.put(c); // write on file the char

    // close the files
    in_file.close();
    out_file.close();

    std::cout << "File copied" << std::endl;

    return 0;
}



