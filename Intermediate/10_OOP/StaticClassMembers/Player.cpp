#include "Player.h"

// static data are typically initializate here
int Player::num_players {0};

Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
        ++num_players;  // increase the count
                        // TIP: increase the variable only in one constructor
}

Player::Player(const Player &source)
       : Player {source.name, source.health, source.xp}  {
}

Player::~Player() {
    --num_players;  // best place to decrement the static variable
}

int Player::get_num_players() {  // a static method can only access to a static class data members
                                 // static key only in class definition (.h file)
    return num_players;
}


