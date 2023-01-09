// Challenge 2
// Automated Grader

#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream in_file;
    std::string right_answers {};
    std::string name {};
    std::string test_scores {};
    unsigned total {}, number_of_students {};
    double avg {};

    // open the file
    in_file.open("../responses.txt");
    if (!in_file) {
        std::cerr << "Problem opening file!" << std::endl;
        return 1;
    }

    // read the right answers (only first row)
    in_file >> right_answers;


    // read the scores of people

    std::cout << std::setw(10) << std::left << "Student"
              << std::setw(7) << std::right << "Score"
              << std::endl;
    std::cout << std::setfill('=');
    std::cout << std::setw(17) << std::left << "" << std::endl;
    std::cout << std::setfill('.');
    while (in_file >> name >> test_scores) {
        unsigned personal_score {0};
        for (size_t i = 0; i < test_scores.size(); i++) {
            if (test_scores.at(i) == right_answers.at(i))
                personal_score++;
        }
        total += personal_score;
        number_of_students++;
        std::cout << std::setw(10) << std::left << name
                  << std::setw(7) << std::right <<  personal_score
                  << std::endl;
    }
    std::cout << std::setfill('=');
    std::cout << std::setw(17) << std::left << "" << std::endl;

    // calculate the avg
    avg = static_cast<double>(total) / number_of_students;
    std::cout << std::setfill(' ');
    std::cout << std::setw(10) << std::right << std::setprecision(2) << std::fixed << "Avg"
              << std::setw(7) << std::right << avg
              << std::endl;

    // close the file
    in_file.close();

    return 0;
}
