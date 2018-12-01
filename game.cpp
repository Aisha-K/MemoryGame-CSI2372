#include "game.h"

/**
 * Constructor for game
 * Initialized Board
 */
Game::Game(): b( *(new Board()) ), round(0){

}

/**
 * Gives the current round between 0 and 6
 */
int Game::getRound(){
    return round;
}

/**
 * Adds a player to the game
 */
void Game::addPlayer( const Player& p){
    
    //ensuring player of that side is not already in the game
    bool containsSide = false;
    for (const Player &player : players){
        if (player.getSide() == p.getSide())
            containsSide = true;
    }

    if (!containsSide)
        players.push_back(p);
}