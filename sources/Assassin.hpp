#ifndef ASSASSIN_HPP
#define ASSASSIN_HPP
#include <iostream>
#include <string>
#include "Player.hpp"
#pragma once
using namespace std;
using namespace coup;

class Assassin : public Player
{
public:
    string lastcoup ="";
    Assassin(Game &game, string name);
    void coup(Player &player);
};


#endif
