#include "rules.h"

// returns true is previous and current card match; false otherwise.
bool isValid(const Game& game){
    return ( game.getCurrentCard() == game.getPreviousCard() );
}

// returns true if the number of rounds has reached 7.
bool gameOver(const Game& game){
    return game.getRound()==7;
}

// returns true if there is only one active Player left.
bool roundOver(const Game& game){
    return false;
} 