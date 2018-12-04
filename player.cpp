#include "player.h"

/**
 * Player constructor
 */
Player::Player(std::string playerName): name(playerName), numOfRubies(0)
                                    ,isPlayerActive(true),gameEnded(false) {
}


/**
 * return the name of the player
 */
std::string Player::getName() const 
{
    return name;
}

/**
 * Sets player status to active or inactive
 */
void Player::setActive(bool active) {
     isPlayerActive=active;
}

/**
 * Returns whether the player is active or not
 */
bool Player::isActive() const 
{
    return isPlayerActive;
}

/**
 * Returns the amount of rubies that the player has won
 */
int Player::getNRubies() const {
    return numOfRubies; 
}


/**
 * Add a reward with a given amount of rubies
 */
void Player::addReward(const Reward& r){
    numOfRubies += (int)r;
}

/**
 * Sets variable indicating the game has ended
 */
void Player::setDisplayMode(bool endOfGame){
    gameEnded = endOfGame;
}

/**
 * Returns the side of the player
 */
Player::Side Player::getSide() const {
    return side;
}

/**
 * Sets the side of the player to the side provided as arguement
 */
void Player::setSide(Side newSide) {
    side=newSide;
}

//cout<< operator override
std::ostream& operator<<(std:: ostream& os, const Player& player){
    if (!player.gameEnded){
        os << player.getName() << ": ";
    
    //get player side as string
     switch ( player.getSide() ){
         case Player::Side::top : os<< "top "; break;
         case Player::Side::bottom : os<< "bottom "; break;
         case Player::Side::right : os<< "right "; break;
         case Player::Side::left : os<< "left "; break;
     }

    if(player.isActive() ){
        os<< "(active)";}
    else{
        os<< "(inactive)";}
    } else {
        os << player.getName() << ": "<< player.getNRubies() << " rubies";
    }

    return os;
}

//-------TESTING------
#ifdef DEBUG_PLAYER
#include <iostream>
int main(){

    //testing pre game end output
    Player *p = new Player("Zaid");
    p->setSide(Player::left);
    std::cout << "Game active output test:\n" << *p << std::endl;

    //testing post game end output
    std::cout << "\nGame ended output test:" << std::endl;
    p->setDisplayMode(true);
    std::cout << *p << std::endl;
}
#endif