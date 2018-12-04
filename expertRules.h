#ifndef EXPERTRULES_H
#define EXPERTRULES_H
#include "rules.h"


class ExpertRules: public Rules{
    Card* blockedCard;

    public:
    ExpertRules();
    bool specialRule(Game& , Board& ); //decides which function to call for the special ability
    void checkBlocked(Card*);
    bool isValid(const Game&);

    //class methods
    private:
    bool Octopus(Game&, Board& b);    //exchange pos with an adjacent card
    bool Penguin(Game& , Board&);    //p can turn a face up card face down
    bool Walrus(Game&, Board&);     //p can block a face down card
    bool Crab(Game&, Board&);   //player must immediately turn over another card
    bool Turtle(Game&); //next player in cur round is skipped

    //helper functions
    string getUserEntry();

    ~ExpertRules();

};

#endif