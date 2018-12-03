#ifndef BOARD_H
#define BOARD_H
//#define DEBUG_BOARD
#include "rewardDeck.h"
#include "cardDeck.h"
#include "card.h"
#include <exception>



class Board{


    public:
    //cardsOnBoard must be made public to be able to flip cards through Game class with the public methods definitions we were given
    // See setCurrentCard in Game for more
    std::array<Card*,25> cardsOnBoard;
    
    enum Letter { A, B, C, D, E};     //corresponding to row
    enum Number{ one, two, three, four, five};    //corresponds to column

    private:
    //holds array of Strigns correspoding to display of the game. 19 rows by 19 chars, 3*5 = 15, 15 + 4 spaces
    std::array<string,19> cardsDisplay;
    //cout << operator override
    friend std::ostream& operator<<(std:: ostream& os, const Board& board);

    
    public:
    //ctor Board, throws not enough cards exception
    Board();

    //functions below throw exception of type OutOfRange
    bool isFaceUp ( const Letter& , const Number&) const; 
    virtual bool turnFaceUp(const Letter& , const Number&); 
    virtual bool turnFaceDown(const Letter& , const Number&); 
    Card* getCard( const Letter&, const Number& );
    void setCard( const Letter&, const Number&, Card* );
    virtual void reset();


    protected:
    //helper functions
    void checkForException(const Letter&, const Number&) const;
    void initializeDeck();
    // returns index corresponding to the first row of the display where the card corresponding
    //to the given Letter is stored, (same for the column if a Number is given)
    template<typename T>
    int getFirstIndexOfCard(T enumtype) const{
        return (enumtype*4);
    }

    //returns index in the array of card pointers that the number and letter correspond to
    int getCardIndex(const Letter& letter, const Number& number) const;

    void makeCardsDisplay();

    virtual void print(ostream& where) const;

    void turnAlreadyFaceUpCardFaceUp(Board::Letter let, Board::Number num, Card* card);

};

#endif