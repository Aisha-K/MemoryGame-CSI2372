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


/**
 * Calls corresponding getCard of board
 */
Card* Game::getCard( const Board::Letter& letter, const Board::Number& num){
    return b.getCard(letter, num);
}

/**
 * Calls corresponding setCard of board
 */
void Game::setCard( const Board::Letter& letter, const Board::Number& num, Card* card){
    return b.setCard(letter,num, card);
}

/**
 * Returns the preious card that was turned, i.e. card turned by prev player
 */
const Card* Game::getPreviousCard(){
    return prevCard;
}

/**
 * Returns current card
 */
const Card* Game::getCurrentCard(){
    return currCard;
}

/**
 * sets current card by updating prev card and current card
 */
void Game::setCurrentCard( const Card* givenCard){
    prevCard = currCard;
    currCard = givenCard;
}