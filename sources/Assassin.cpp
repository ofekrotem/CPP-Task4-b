#include "Assassin.hpp"
const int six = 6;
const int seven = 7;
using namespace std;
using namespace coup;

Assassin::Assassin(Game &game, string name) : Player (game, name, "Assassin"){}
void Assassin::coup(Player &player) 
{
    if (this->coins() < 3 ){throw invalid_argument ("Not enough coins");}
    this->game.checks(*this);
    this->game.kick(player);
    if (this->coins() > six ) 
    {
        this->money-=seven;
        this->lastcoup = player.myName;
    }
    else 
    {
    this->money-=3;
    this->lastcoup = player.myName;
    this->play = "AssasinCoup";
    }
}