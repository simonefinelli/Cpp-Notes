// Section 11
// Default Arguments

#include <iostream>
#include <iomanip>
#include "string"

using namespace std;

// Prototypes
double calc_cost(double base_cost, double tax_rate = 0.06, double shipping = 3.50); // defaults only in prototypes
void greeting(string name, string prefix = "Mr.", string suffix = "");

int main() {
    double cost;
    cout << fixed << setprecision(2);

    cost = calc_cost(100.0, 0.08, 4.25);  // no defaults
    cout << "Cost is: " << cost << " $" << endl;

    cost = calc_cost(100.0, 0.08);  // default shipping
    cout << "Cost is: " << cost << " $" << endl;

    cost = calc_cost(200.0);  // default tax_rate and shipping
    cout << "Cost is: " << cost << " $" << endl;

    greeting("Simox", "Mr.", "The king");
    greeting("M", "Professor");
    greeting("Z");
}

double calc_cost(double base_cost, double tax_rate, double shipping) {
    return base_cost + (base_cost * tax_rate) + shipping;
}

void greeting(string name, string prefix, string suffix) {
    string printable_name = prefix + " " + name + " " + suffix;
    cout << "Hello " << printable_name << endl;
}