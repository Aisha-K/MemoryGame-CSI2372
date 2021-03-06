#ifndef RULES_H
#define RULES_H

#include "game.h"

class Rules{
    int currPlayerSide;

    public:
    Rules();
    virtual bool isValid(const Game&); // returns true is previous and current card match; false otherwise.
    bool gameOver(const Game&); // returns true if the number of rounds has reached 7.
    bool roundOver(const Game&); // returns true if there is only one active Player left.
    const Player& getNextPlayer(const Game& );

    //virtual rules destructor to allow for destruction of ExpertRules child class
    virtual ~Rules();

    //helper functions
    protected:
    #ifdef DEBUG_RULES
    public:
    #endif
    int getNumberOfActivePlayers(const Game&);
    int cardsTurnedUp;
};

#endif