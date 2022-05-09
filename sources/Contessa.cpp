#include "Contessa.hpp"

Contessa::Contessa(Game &game, string name) : Player (game, name, "Contessa") {}
void Contessa::block(Assassin &player) 
{
    if(player.play!="AssasinCoup"){throw invalid_argument("Not today");}
        uint place = 0;
        for (Player &p : this->game.gameParticipant) 
        {
            if (!p.online)
            {
                this->game.gameParticipant.at(place).online = true;
                player.lastcoup = "";
                break;
            }
            place++;
        }
    this->play = "block";

}