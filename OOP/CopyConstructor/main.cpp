// Section 13
// Copy Constructor
#include <iostream>
#include <string>

using namespace std;

/*
 * A copy constructor is called when:
 *  - passing object by value as a parameter of a method (function).
 *  - returning an object from a function by value.
 *  - constructing one object based on another of the same class.
 *
 *  By default, a default copy constructor will be created by compiler.
 *
 *  Normally the copy constructor is used when the class use RAW pointers.
 */

class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    // constructor
    Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
    // copy constructor
    Player(const Player &source);  // he accepts one param PASSED BY REFERENCE

    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() {return xp; }

    // Destructor
    ~Player() { cout << "Destructor called for: " << name << endl; }
};

// constructor implementation
Player::Player(std::string name_val, int health_val, int xp_val)
        : name{name_val}, health{health_val}, xp{xp_val} {
    cout << "Three-args constructor for " + name << endl;
}

// copy constructor implementation
Player::Player(const Player &source)
// : name(source.name), health(source.health), xp{source.xp} {
        : Player {source.name, source.health, source.xp}  {  // we make copies and use delegation
    cout << "Copy constructor - made copy of: " << source.name << endl;
}




void display_player(Player p) {  // p passed by value (copy)
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;
}  // we call destructor for p object because we made a copy of passed object and
   // when the function finished the p object is deleted from the stack with the function

int main() {
    Player empty {"XXXXXX", 100, 50};

    Player my_new_object {empty};  // copy (so the copy constructor is called)

    display_player(empty);  // copy (so the copy constructor is called)

    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};

    return 0;
}