// Section 13
// Declare Classes and Objects

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/****************************************************************************************************
 * Encapsulation: objects contain DATA (attributes) and OPERATIONS (methods) that work on that data *
 * **************************************************************************************************/

class Player {
    // attributes (class instances)
    string name;
    int health;
    int xp;

    // methods
    void talk(string);
    bool is_dead();
};

class Account {
    // attributes (class instances)
    string name = "Account";
    double balance = 0.0;

    // methods
    bool deposit(double);
    bool withdraw(double);
};


int main() {

    Account simox_account;
    Account x_account;

    Player Simox;  // object
    Player hero;   // object

    // create objects on the heap
    Player *enemy = nullptr;
    enemy = new Player;

    Player players[] = {Simox, hero};

    vector<Player> enemies = {Simox};
    enemies.push_back(hero);

    delete enemy;

    return 0;
}
