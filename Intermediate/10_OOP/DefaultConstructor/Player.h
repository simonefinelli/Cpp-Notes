#ifndef DEFAULTCONSTRUCTOR_PLAYER_H
#define DEFAULTCONSTRUCTOR_PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int health;
    int xp;

public:
    /*
     * if we not provide any constructors the compiler generate a Default Constructor when an object is created!
     * A default constructor is a constructor with No Args!
     *
     */

    /*
     * if we provide a constructor (either with args or not) the default constructor is never created!
     */
    Player(std::string name_val, int health_val, int xp_val) {
        name = name_val;
        health = health_val;
        xp = xp_val;
    }

    void set_name(std::string name_val);
    std::string get_name();
};


#endif //DEFAULTCONSTRUCTOR_PLAYER_H
