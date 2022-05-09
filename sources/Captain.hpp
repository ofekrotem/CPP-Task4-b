#ifndef CAPTAIN_HPP
#define CAPTAIN_HPP
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
using namespace coup;

class Captain : public Player
{
public:
    Captain(Game &game, string name);
    static void block(Player &player);
    void steal(Player &player);
    Player *stoleFrom;
};


#endif
