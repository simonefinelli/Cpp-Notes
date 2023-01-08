// Read data in a File using a loop
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    std::ifstream in_file;
    std::string name;
    int num;
    double total;

    // open the file
    in_file.open("../test.txt");
    if (!in_file) {
        std::cerr << "Problem opening file!" << std::endl;
        return 1;
    }

    // read the data
    while (in_file >> name >> num >> total) {
        std::cout << std::setw(10) << std::left << name
                  << std::setw(10) << num
                  << std::setw(10)  << total
                  << std::endl;
    }

    // close the file
    in_file.close();

    return 0;
}
