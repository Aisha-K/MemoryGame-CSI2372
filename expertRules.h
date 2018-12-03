#ifndef EXPERTRULES_H
#define EXPERTRULES_H
#define DEBUG_EXPERTRULES
#include "rules.h"


class ExpertRules: public Rules{
    Card* blockedCard;

    public:
    ExpertRules();
    bool specialRule(Game& , Board& ); //decides which function to call for the special ability

    private:

    bool Octopus(Game&);    //exchange pos with an adjacent card
    bool Penguin(Game& , Board&);    //p can turn a face up card face down
    bool Walrus(Game&);     //p can block a face down card
    bool Crab(Game&, Board&);   //player must immediately turn over another card
    bool Turtle(Game&); //next player in cur round is skipped

    //helper functions
    string getUserEntry();

};

#endif