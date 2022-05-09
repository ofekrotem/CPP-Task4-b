#include "Player.hpp"
using namespace std;
using namespace coup;
const int seven = 7;
const int nine = 9;

Player::Player(Game &game1, string &name1, string role) : game(game1), myName(name1) , money(0), online(true), play("")
{
    this->myRole = move(role);
    this->game.addPlayer(*this);
}

void Player::income() 
{
    this->game.checks(*this);
    this->game.running = true;
    this->money ++;
    this->game.incMoves();
    this->play = "income";
}
void Player::foreign_aid()
{
    this->game.checks(*this);
    if (this->coins() > nine ){
        throw invalid_argument ("You have 10 coins, you have to coup");}
    this->money +=2;
    this->game.incMoves();
    this->play = "foreign_aid";

}
void Player::coup(Player &player)
{
    this->game.checkwithoutCoup(*this);
    if (this->coins() < seven ){throw invalid_argument ("Not enough coins for coup");}
    if (!player.online){throw invalid_argument (player.myName+" is already out of the game");}
    this->game.kick(player);
    this->money-=seven;
    this->coupName = player.myName;
    this->play = "PlayerCoup";
}

string Player::role() const{return this->myRole;}
int Player::coins() const{return this->money;}
void Player::dies() {this->online = false;}

