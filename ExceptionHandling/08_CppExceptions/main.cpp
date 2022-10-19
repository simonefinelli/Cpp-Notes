// Section 18
// catching std::exception exceptions

#include <iostream>
#include <string>
#include <vector>

int main() {

    try {
        for (int i=0; i< 100; i++)
            auto *s = new std::string[999999999];
    }
    catch (const std::bad_alloc &ex) {
        std::cerr << ex.what() << std::endl;
    }

    std::vector<int> vec {1,2,3,4,5};
    try {
        std::cout << vec.at(10);
    }
    catch (const std::out_of_range &ex) {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "Bye!" << std::endl;
    return 0;
}
