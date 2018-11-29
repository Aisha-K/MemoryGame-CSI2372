#ifndef BOARD_H
#define BOARD_H
#define DEBUG_BOARD
#include "rewardDeck.h"
#include "cardDeck.h"
#include "card.h"
#include <exception>



class Board{
    Deck<Reward>& rewardDeck;  // = RewardDeck::make_RewardDeck();
    Deck<Card>& cardDeck;

    std::array<Card*,25> cardsOnBoard;


    //cout << operator override
    friend std::ostream& operator<<(std:: ostream& os, const Board& board);
    
    //holds array of Strigns correspoding to display of the game
    //19 rows by 19 chars, 3*5 = 15, 15 + 4 spaces
    std::array<string,19> cardsDisplay;

    public:
    enum Letter { A, B, C, D, E};     //corresponding to row
    enum Number{ one, two, three, four, five};    //corresponds to column
    
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

    //helper functions

    // returns index corresponding to the first row of the display where the card corresponding
    //to the given Letter is stored, (same for the column if a Number is given)
    template<typename T>
    int getFirstIndexOfCard(T enumtype) const{
        return (enumtype*4);
    }

    //returns index in the array of card pointers that the number and letter correspond to
    int getCardIndex(const Letter& letter, const Number& number) const;

};

#endif