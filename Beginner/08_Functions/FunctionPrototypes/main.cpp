// Section 11
// Function Prototypes
// Area of Circle and Volume of a Cylinder
#include <iostream>

using namespace std;

const double pi {3.14159};

// prototypes
void area_circle();
void volume_cylinder();
double calc_area_circle(double radius);
double cal_volume_cylinder(double radius, double height);

int main() {

    area_circle();

    volume_cylinder();

    return 0;
}

void area_circle() {
    double radius {};
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    cout << "The area of a circle with radius " << radius << " is "
         << calc_area_circle(radius) << endl;  // radius here is called ARGUMENT
}

void volume_cylinder() {
    double radius {}, height {}, volume;
    cout << "\nEnter the radius and the height of the cylinder: ";
    cin >> radius >> height;

    volume = cal_volume_cylinder(radius, height);

    cout << "The volume of the cylinder is: " << volume << endl;
}

double calc_area_circle(double radius) {  // radius here is called PARAMETER
    double area;
    area = pi * radius * radius;

    return area;
}

double cal_volume_cylinder(double radius, double height) {
    double volume;
    volume = calc_area_circle(radius) * height;

    return volume;
}
