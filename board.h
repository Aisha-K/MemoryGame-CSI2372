#ifndef BOARD_H
#define BOARD_H

class Card;

class Board{
    //holds array of Strigns correspoding to display of the game

    enum class Letter { A, B, C, D, E};     //corresponding to row
    enum class Number{ one, two, three, four, five};    //corresponds to column
    
    public:
    //add ctor Board

    //functions below throw exception of type OutOfRange
    bool isFaceUp ( const Letter& , const Number&) const; 
    bool turnFaceUp(const Letter& , const Number&); 
    bool turnFaceDown(const Letter& , const Number&); 
    Card* getCard( const Letter&, const Number& );
    void setCard( const Letter&, const Number&, Card* );
    void reset();
    //add print function, throws exception of type NoMoreCards
};

#endif