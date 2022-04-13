// Section 13
// Constructor Initialization Lists

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    std::string name {"XXXXXXX"};
    int health;
    int xp;
public:
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

/*
 * Player::Player() {
 *      name{"None"}; // assignment NOT initialization. This can be inefficient because the var name is already been created at this point,
 *                                                      and we just override the content.
 *      health{0};  // assignment NOT initialization
 *      xp{0};  // assignment NOT initialization
 * }
 */

Player::Player()
        : name{"None"}, health{0}, xp{0} {  // constructor list: we INITIALIZE the data members to our dat values as they're created.
                                               // so constructor list is an EFFICIENT way to do constructor initialization
                                               // Now the initialization happens before the body of the constructor is executed.
}

Player::Player(std::string name_val)
        : name{name_val}, health{0}, xp{0} {  // TIP: the order of the list is irrelevant: the data members will be initialized
                                              // in the order that they were declared in the class declaration
}

Player::Player(std::string name_val, int health_val, int xp_val)
        : name{name_val}, health{health_val}, xp{xp_val} {

}

int main() {

    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};

    return 0;
}