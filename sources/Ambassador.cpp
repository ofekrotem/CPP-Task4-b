#include "Ambassador.hpp"
const int ten = 10;
using namespace std;
using namespace coup;

Ambassador::Ambassador(Game &game, string name) : Player(game,name, "Ambassador"){}

void Ambassador::transfer (Player &player1, Player &player2)
{
    this->game.checks(*this);
    if (player1.money == 0){throw invalid_argument(player1.myName +" doesn't have any money");}
    player1.money-=1;
    player2.money+=1;
    this->game.incMoves();
}

void Ambassador::block(Captain &player) 
{
    if (this->money == ten){throw invalid_argument ("You have 10 coins, you have to coup");}
    if(player.myRole!="Captain"){throw invalid_argument("You can't block him!");}
    if (player.play == "steal")
    {
        player.money -=2;
        player.stoleFrom->money += 2;
    }
}