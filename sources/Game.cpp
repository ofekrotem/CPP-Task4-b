#include <algorithm>
#include "Game.hpp"
const int five = 5;
const int ten = 10;
using namespace coup;
    Game::Game(): moves(0), running(false){}

    Game::~Game() {}

    string Game::turn() 
    {
        return this->gameParticipant.at(uint(this->moves)).myName;
    }

    vector<string> Game::players() 
    {
        vector <string> activeParticipant;
        for (Player &player : this->gameParticipant) 
        {
            if (player.online)
            {
                activeParticipant.push_back(player.myName);
            }
        }
        return activeParticipant;
    }

    void Game::checks(Player &player)
    {
        if (this->gameParticipant.size() == 1){throw invalid_argument ("Only one user");}
        if (this->turn() != player.myName){throw invalid_argument ("Not your turn!");}
        if (player.money == ten){throw invalid_argument ("Yalla balagan - make a coup you have 10 coins!");}
    }
    void Game::checkwithoutCoup(Player &player)
    {
        if (this->gameParticipant.size() == 1){throw invalid_argument ("Only one user");}
        if (this->turn() != player.myName){throw invalid_argument ("Not your turn!");}
    }

    string Game::winner() 
    {
        if(!this->running){throw invalid_argument ("Game isn't running");}
        if(this->players().size() != 1){throw invalid_argument ("No winner yet, keep playing!");}
        return this->players().at(0);
    }

    void Game::addPlayer(Player &player) 
    {
        if (this->running){throw invalid_argument("Can't add player - game is already running");}
        if (this->gameParticipant.size() > five ){throw invalid_argument("Can't add player - Max players");}
        this->gameParticipant.push_back(player);
    }

    void Game::kick(Player &player) 
    {
        for (Player &p : this->gameParticipant) 
        {
            if (p.myName == player.myName)
            {
                if (!p.online){throw invalid_argument("Can't kick, he's already dead!");}
                p.online = false;
                this->incMoves();
                break;
            }
        }
    }

    void Game::incMoves()
    {
        for (uint i = this->moves+1; i < this->gameParticipant.size() + this->moves; ++i) 
        {
            if (this->gameParticipant.at(i % this->gameParticipant.size()).online) 
            {
                this->moves = i % this->gameParticipant.size();
                break;
            }
        }
    }