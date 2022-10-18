// Section 13
// Const in Classes
#include <iostream>
#include <string>

using namespace std;

/*
 * TIP: the best practice is all getters should be const.
 *      in particular, any method in the class that doesn't modify the object
 *      should be const.
 */

class Player
{
private:
    std::string name;
    int health;
    int xp;
public:
    std::string get_name() const {  // consty method - const class can call that method
                                     // const is necessary either for getter (technically only read class attributes) methods because
                                     // the method could still modify the class attributes, so the compiler will give an error
        // xp = 42; // compiler error
        return name;
    }
    void set_name(std::string name_val)   {
        name = name_val;
    }
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()
        : Player {"None",0,0} {
}

Player::Player(std::string name_val)
        : Player {name_val,0, 0}  {
}

Player::Player(std::string name_val, int health_val, int xp_val)
        : name{name_val}, health{health_val}, xp{xp_val} {
}

void display_player_name(const Player &p) {  // we pass a CONST object
    cout << p.get_name() << endl;
}


int main() {

    const Player villain {"Villain", 100, 55};
    Player hero {"Hero", 100, 15};

    // villain.set_name("Super villain");  // compiler error
    // cout << villain.get_name() << endl;  // if we not use const in method firm this statement will raise an exception too
    cout << hero.get_name() << endl;

    display_player_name(villain);
    display_player_name(hero);  // line 42 could modify the object so if we don't use const the compiler will raise
                                   // an exception either for a non-const object



    return 0;
}