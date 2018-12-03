#ifndef EXPERTRULES_H
#define EXPERTRULES_H
#include "rules.h"


class ExpertRules: public Rules{
    Card* blockedCard;

    public:
    ExpertRules();

    private:
    bool isValid();     //do we need custom one?

    void specialRule(Game& , Board& ); //decides which function to call for the special ability
    void Octopus(Game&);    //exchange pos with an adjacent card
    void Penguin(Game& , Board&);    //p can turn a face up card face down
    void Walrus(Game&);     //p can block a face down car
    void Crab(Game&);   //player must immediately turn over another card
    void Turtle(Game&); //next player in cur round is skipped



};

#endif