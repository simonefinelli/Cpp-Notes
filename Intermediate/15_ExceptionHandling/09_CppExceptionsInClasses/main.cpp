// Section 18
// catching std::exception exceptions
#include <iostream>

class DivideByZeroException : public std::runtime_error  {
public:
    DivideByZeroException() : std::runtime_error {"Cannot divide by zero"} {

    }
};

class NegativeValueException : public std::runtime_error {
public:
    NegativeValueException() : std::runtime_error {"one of your parameters is negative"} {

    }
};

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0)
        throw DivideByZeroException();
    else if (miles < 0 || gallons < 0)
        throw NegativeValueException();
    return static_cast<double>(miles) / gallons;
}

int main() {
    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;

    } catch (const DivideByZeroException &ex) {
        std::cerr << ex.what() << std::endl;
    } catch (const NegativeValueException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;
}
