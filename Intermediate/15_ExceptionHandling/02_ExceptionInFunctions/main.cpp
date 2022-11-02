// Section 18
// Exceptions in Functions

/*
 * If we want to catch an exception there must be at least one try/catch
 * in one of the functions on the stack.
 */

#include <iostream>

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0)
        throw 0;  // better practice is to use objects
    return static_cast<double>(miles) / gallons;
}

int main() {
    int miles {};
    int gallons {};
    double miles_per_gallon;

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (int &ex) {
        std::cerr << "Tried to divide by zero!" << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;
}

