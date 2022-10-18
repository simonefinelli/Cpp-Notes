// Exercise 27: Save a penny (using recursion)

#include <iostream>
#include <climits>

using namespace std;

// function prototypes
double duplicate_saving(int, double = 0.01);

int main() {
    unsigned short int days;  // 0 ~ 65535

    cout << "Digit the days and the amount to save: ";
    cin >> days;

    double saving_amount = duplicate_saving(days);

    cout << "The amount saved in " << days << " days is: "
         << saving_amount << " $" << endl;
}

double duplicate_saving(int days, double amount) {
    if (days <= 1) {
        return amount;
    } else {
        return duplicate_saving(--days, amount) * 2;  //  duplicate_saving(--days, amount) * 2
        // TIP
        // using days-- doesn't work because days is incremented after the call of the function
        // (++ and -- operands have an unpredictable behavior!)
        // We should use `days -= 1` or do days-- in a separate row!
    }
}

