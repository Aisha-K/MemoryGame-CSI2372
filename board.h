#ifndef BOARD_H
#define BOARD_H
#include"rewardDeck.h"
#include "card.h"


class Board{
    Deck<Reward>& rewardDeck;  // = RewardDeck::make_RewardDeck();
    
    //holds array of Strigns correspoding to display of the game
    //19 rows by 19 chars, 3*5 = 15, 15 + 4 spaces
    std::array<string,19> cardsDisplay;

    public:
    enum class Letter { A, B, C, D, E};     //corresponding to row
    enum class Number{ one, two, three, four, five};    //corresponds to column
    
    public:
    //add ctor Board, throws not enough cards exception
    Board();

    //functions below throw exception of type OutOfRange
    bool isFaceUp ( const Letter& , const Number&) const; 
    bool turnFaceUp(const Letter& , const Number&); 
    bool turnFaceDown(const Letter& , const Number&); 
    Card* getCard( const Letter&, const Number& );
    void setCard( const Letter&, const Number&, Card* );
    void reset();
    //add print function
};

#endif