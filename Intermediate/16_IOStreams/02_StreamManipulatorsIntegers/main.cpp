// Integer stream manipulators:
// dec, hex, oct, showbase uppercase, nouppercase, showpos

#include <iostream>
#include <iomanip>

int main() {
    int num {255};

    // displaying using different bases
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // displaying showing the base prefix for hex and oct
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;  // hex prefix: 0x
    std::cout << std::oct << num << std::endl;  // oct prefix: 0

    // display the hex value in uppercase
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;

    // display the + sign
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::showpos;  // + sign only for 10 base numbers
    std::cout << std::dec << num << std::endl;  //
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // setting using the set method (alternative)
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);

    // resetting to defaults
    std::cout << std::resetiosflags(std::ios::basefield);  // use decimal base
    std::cout << std::resetiosflags(std::ios::showbase);  // not show the base prefix
    std::cout << std::resetiosflags(std::ios::showpos);  //  not show positive sign
    std::cout << std::resetiosflags(std::ios::uppercase);  // not use uppercase

    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "Enter an integer : ";
    std::cin >> num;

    std::cout << "Decimal default  : " << num << std::endl;

    std::cout << "Hexadecimal      : " << std::hex << num << std::endl;
    std::cout << "Hexadecimal      : " << std::hex << std::uppercase << num << std::endl;
    std::cout << "Hexadecimal      : " << std::hex  << num << std::endl;
    std::cout << "Hexadecimal      : " << std::hex << std::nouppercase << num << std::endl;

    std::cout << "Octal            : " << std::oct << num << std::endl;
    std::cout << "Hexadecimal      : " << std::hex << std::showbase << num << std::endl;
    std::cout << "Octal            : " << std::oct << num << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}


