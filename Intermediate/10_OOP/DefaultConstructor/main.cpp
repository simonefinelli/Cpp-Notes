// Section 13
// Default Constructors

#include <iostream>
#include "Player.h"

using namespace std;

int main() {

    Player simox("Simox", 100, 1343);
    simox.set_name("SimoX");
    cout << "The name is: " << simox.get_name() << endl;


    return 0;
}
