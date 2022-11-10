// Boolean Stream Manipulators: boolalpha and noboolalpha

/*
 * Manipulators allow us to manipulate the stream (console, files, etc.).
 */

#include <iostream>
#include <iomanip>  // for manipulators

int main() {
    // by default C++ show a bool variable as 0 and 1
    std::cout << "noboolalpha - default  (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "noboolalpha - default  (10 == 20) : " << (10 == 20)  << std::endl;

    // set to true/false formatting
    std::cout << std::boolalpha;  // change to true/false using a manipulator
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;

    // setting still stays
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;

    // return to 0/1
    std::cout << std::noboolalpha;
    std::cout << "noboolalpha  (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "noboolalpha  (10 == 20) : " << (10 == 20)  << std::endl;

    // Set back to true/false using setf method
    std::cout.setf(std::ios::boolalpha);
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;

    // resets to default which is 0/1
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "Default  (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "Default  (10 == 20) : " << (10 == 20)  << std::endl;
    return 0;
}