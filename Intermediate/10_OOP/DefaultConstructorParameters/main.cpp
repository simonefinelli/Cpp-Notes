// Section 13
// Default Constructor Parameters
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    std::string name;
    int health;
    int xp;

public:
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0)  // default parameters
            : name{name_val}, health{health_val}, xp{xp_val} {
        cout << "Three-args constructor" << endl;
    }

    //  Player() {}    // will cause a compiler error because in the previous constructor no params constructor is already allowed
};


int main() {

    Player empty;
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};

    return 0;
}