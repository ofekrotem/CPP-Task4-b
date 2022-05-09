#ifndef CONTESSA_HPP
#define CONTESSA_HPP
#include <iostream>
#include <string>
#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;
using namespace coup;

class Contessa : public Player
{
public:
    Contessa(Game &game, string name);
    void block(Assassin &player);
};


#endif
