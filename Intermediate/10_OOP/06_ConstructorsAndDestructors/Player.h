#ifndef CONSTRUCTORSANDDESTRUCTORS_PLAYER_H
#define CONSTRUCTORSANDDESTRUCTORS_PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    int health;
    int xp;

public:
    // overloaded constructors
    Player() {
        std::cout << "No args constructor called" << std::endl;
    }
    Player(std::string) {
        std::cout << "String arg constructor called" << std::endl;
    };
    Player(std::string name, int health, int xp) {
        std::cout << "Three args constructor called" << std::endl;
    };

    // public methods
    void set_name(const std::string& name_val);

    // destructor - each class have only one destructor
    ~Player() {
        std::cout << "Destructor called for " << name << std::endl;
    };


};


#endif //CONSTRUCTORSANDDESTRUCTORS_PLAYER_H
