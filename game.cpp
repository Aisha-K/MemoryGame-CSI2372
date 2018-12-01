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
 * Ensures a player with that side doesn't previously exist
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

/**
 * Returns the player at the side specified
 * If side specified doesn't exist, then throws exception
 */
const Player& Game::getPlayer( Player::Side s){
    
    for (const Player &player : players){
        if (player.getSide() == s)
            return player;
    }

    //throws exception if side isn't in range
    throw std::out_of_range ("Exception: Side not in players");
}