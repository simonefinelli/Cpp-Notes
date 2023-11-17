// Section 13
// Constructors and Destructors

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;


int main() {

    { // just for learning scope: just to create a block code
        Player player1;
        player1.set_name("SimoX");
    } // destructor is caller when a class object is out-of-scope

    {
        Player player2;
        player2.set_name(string("Player 2"));

        Player player3(string("Player 3"));

        Player player4("Player 4", 100,1000);
        player4.set_name("Player 42");
    } // the destructors are called in the reverse order (se debugger to se the behaviour)

    auto *enemy = new Player;
    enemy->set_name("Enemy 1");

    auto *final_boss = new Player("Last Boss", 99'999, 9'999);
    final_boss->set_name("Bad Boss");

    delete enemy;  // destructor is called
    delete final_boss; // destructor is called


    return 0;
}
