// Section 13
// Accessing Modifiers

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
 * Private:
 *   - The class members declared as private can be accessed only inside the class.
 *   - Only the member functions or the friend functions are allowed to access the private data members of a class.
 *
 * Public:
 *   - All the class members declared under public will be available to everyone.
 *   - The data members and member functions declared public can be accessed by other classes too.
 */


class Player {

private:
    // attributes (class instances)
    string name = "Player 1";
    int health;
    int xp;

public:
    // methods
    void talk(const string &text) {cout << name << " says " << text << endl;}

    bool is_dead();
};


int main() {

    Player player1;

    // player1.name = "Player 1";  // compiler error

    player1.talk("Hello there!");

    return 0;
}