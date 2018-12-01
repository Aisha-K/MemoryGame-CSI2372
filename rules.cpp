#include "rules.h"

/**
 * returns true is previous and current card match; false otherwise.
 */
bool Rules::isValid(const Game& game){
    return ( game.getCurrentCard() == game.getPreviousCard() );
}

/**
 * returns true if the number of rounds has reached 7.
 */
bool Rules::gameOver(const Game& game){
    return game.getRound()==7;
}

/**
 * returns true if there is only one active Player left.
 */
bool Rules::roundOver(const Game& game){
    int activePlayerCount = getNumberOfActivePlayers(game);

    //if there are more than 1 players active then round is not over
    if (activePlayerCount >1)
        return false;

    //round is over once there is only 1 player active
    return true;
}

/**
 * Helper function to return the number of active players in a game
 */
int Rules::getNumberOfActivePlayers(const Game& game) {
    int activePlayerCount = 0;
    
    for (int i=0; i<4; i++){
        try {
            Player p = game.getPlayer(Player::Side(i));
            if (p.isActive())
                activePlayerCount++;
        }
        catch(...){
            
        }
    }
    return activePlayerCount;
}

//-------TESTING-------
#ifdef DEBUG_RULES
#include <iostream>
int main(){
    //testing active player count

}
#endif