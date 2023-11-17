// Section 13
// Accessing Class Members

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/****************************************************************************************************
 * Encapsulation: objects contain DATA (attributes) and OPERATIONS (methods) that work on that data *
 * **************************************************************************************************/

class Player {

public:
    // attributes (class instances)
    string name;
    int health;
    int xp;

    // methods
    void talk(const string &text) {cout << name << " says " << text << endl;}

    bool is_dead();
};

class Account {

public:
    // attributes (class instances)
    string name = "Account";
    double balance = 0.0;

    // methods
    bool deposit(double bal) {
        balance += bal;
        cout << "In deposit" << endl;
        return true;
    }

    bool withdraw(double bal) {
        balance -= bal;
        cout << "In withdraw" << endl;
        return true;
    }
};


int main() {

    Player player1;  // create a new Player object

    // we can access to attributes and methods with '.' operator
    player1.name = "Simox";
    player1.health = 1000;
    player1.xp = 0;

    player1.talk("Hi there!");

    // Using Pointers

    Player *player2 = new Player;
    // to access the members of a class we can use dereferencing method or '->'
    (*player2).name = "XXXXX";  // in the dereferencing we have to use () because '.' has more priority than '*' (dereferencing operator)
    (*player2).health = 2000;
    player2->xp = 150;  // arrow operator directly makes dereferencing ad access to the class members

    player2->talk("I will help you!");

    delete player2;

    /*****************************************************/

    Account account1;
    account1.name = "Simox's Account";
    account1.balance = 3423.73;

    account1.deposit(500.94);
    account1.withdraw(86.0);


    return 0;
}
