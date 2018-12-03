#ifndef EXPERTRULES_H
#define EXPERTRULES_H
#define DEBUG_EXPERTRULES
#include "rules.h"


class ExpertRules: public Rules{
    Card* blockedCard;

    public:
    ExpertRules();
    void specialRule(Game& , Board& ); //decides which function to call for the special ability

    private:

    void Octopus(Game&);    //exchange pos with an adjacent card
    void Penguin(Game& , Board&);    //p can turn a face up card face down
    void Walrus(Game&);     //p can block a face down card
    bool Crab(Game&);   //player must immediately turn over another card
    void Turtle(Game&); //next player in cur round is skipped

    //helper functions
    string getUserEntry();

};

#endif