#ifndef DUKE_HPP
#define DUKE_HPP
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
using namespace coup;

class Duke : public Player
{
public:
    Duke(Game &game, string name);
    void block(Player &player);
    void tax();
};

#endif
