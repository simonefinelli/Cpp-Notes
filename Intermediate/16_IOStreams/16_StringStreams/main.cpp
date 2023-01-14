// String streams

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

/*
 * String streams allow us to read/write from strings in memory (like files).
 * They are very useful, for example, for data validation.
 *
 * There are 3 classes that allow us to use string streams:
 *  - stringstream: read and write from string streams.
 *  - istringstream: read form string streams.
 *  - ostringstream: write to string streams.
 *
 * Using string stream is very easy:
 *  1. declare a sitringstream (from 3 before) object;
 *  2. connect it to a std::string;
 *  3. Read/Write data from/to the string stream using formatted I/O.
 */

int main() {
    int num{};
    double total{};
    std::string name{};

    /*******************************
     * Reading from a stringstream *
     *******************************/
    std::string info {"Moe 100 1234.5"};
    std::istringstream iss {info};  // istringstream object

    iss >> name  >> num >>  total;  // stream extraction operator
    std::cout << std::setw(10) << std::left << name
              << std::setw(5) << num
              << std::setw(10) << total << std::endl;

    std::cout << "\n---------------------------------------" << std::endl;

    /*******************************
     * Writing to a stringstream *
     *******************************/
    std::ostringstream oss {};  // ostringstream object
    oss << std::setw(10) << std::left << name
        << std::setw(5) << num
        << std::setw(10) << total << std::endl;
    std::cout << oss.str() << std::endl;  // get the string from ostringstream


    std::cout << "\n----------- Data validation -----------" << std::endl;

    std::string first_name {};
    int age {};
    std::string entry {};
    bool done = false;
    do {
        std::cout << "Please, enter your first name and age: ";
        std::getline(std::cin, entry);
        // validation
        std::istringstream validator {entry};
        if (validator >> first_name >> age)
            done = true;
        else
            std::cout << "Sorry, those input is not valid!" << std::endl;
    } while (!done);

    std::cout << "You entered: " << first_name  << " "<< age << std::endl;

    std::cout << std::endl;
    return 0;
}

