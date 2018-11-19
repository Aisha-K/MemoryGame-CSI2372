#include "player.h"


void Player::addReward(const Reward&){

}

void Player::setDisplay(bool endOfGame){

}

std::ostream& operator<<(std:: ostream& os, const Player& player){
    //if endOGame=false
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

    //if endOfgame = true ...
    // os << player.getName() << ": "<< plyer.getNRubies() << "rubies";

    return os;
}

