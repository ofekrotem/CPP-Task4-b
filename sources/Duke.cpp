#include "Duke.hpp"
Duke::Duke(Game &game, string name) : Player (game, name, "Duke"){}
void Duke::block(Player &player) 
{
    if(player.play!="foreign_aid"){throw invalid_argument("Not today");}
    player.money-=2;
    this->play = "Dukeblock";
}
void Duke::tax() 
{
    this->game.checks(*this);
    this->game.incMoves();
    this->money +=3;
}