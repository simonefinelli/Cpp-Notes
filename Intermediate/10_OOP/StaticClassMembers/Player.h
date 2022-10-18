#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player
{
private:
   static int num_players;  // a static variable is shared between objects
                            // if we try to initialize a static variable here
                            // the compiler will raise an exception
   std::string name;
   int health;
   int xp;
public:
    Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
    // Copy constructor
    Player(const Player &source);

    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() {return xp; } 

    // Destructor
    ~Player();
    
    static int get_num_players();
    
};

#endif // _PLAYER_H_
