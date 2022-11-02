// Section 18
// Miles per Gallon program

/*
 * What is exception handling?
 *  It is about dealing with extraordinary situations.
 *
 * Many are the causes that bring up to that situations, like:
 *  - insufficient resources
 *  - missing resources
 *  - invalid operations
 *  - range violations
 *  - underflow and overflow
 *  - etc.
 *
 * Definitions:
 *  - Exception
 *      an object or primitive type that signals that an error has occurred.
 *  - Throwing/Raising an exception
 *      an error will occur
 *  - Catching an exception
 *      handling the exception
 *
 * TIP: the best practice is to throw by value and catch by reference.
 *
 * NOTE: exceptions should be used only for synchronous code.
 */

#include <iostream>

int main() {
    int miles {};
    int gallons {};
    double miles_per_gallon;

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    try {
        if (gallons == 0)
            throw 0;  // better practice is to use objects
        miles_per_gallon = static_cast<double>(miles) / gallons;  // with int the program crash, with floats we can get -/+inf or nan (0/0)
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (int &ex) {
        std::cerr << "Sorry, the following exception raised: " << ex << std::endl;  // another way to print a message error
    }

    std::cout << "Bye!" << std::endl;

    return 0;
}
