#ifndef EXPERTDISPLAY_H
#define EXPERTDISPLAY_H
//#define DEBUG_EXPERTDISPLAY
#include "board.h"

class ExpertDisplay: public Board{
    
    std::array<string,4> eCardsDisplay;  //hold 5 rows, first 3 to display cards
    std::vector<Card*> faceUpCards;

    //cout << operator override
    //friend std::ostream& operator<<(std:: ostream& os, const Board& board);

    public:
    ExpertDisplay();

    private:
    void makeCardsDisplay();
    string enumPosToString(const Board::Letter& let, const Board::Number& num);
    bool turnFaceUp(const Letter& , const Number&); 
    bool turnFaceDown(const Letter& , const Number&); 
    void reset();
    void setCard( const Letter& letter, const Number& num, Card* card2Ptr);

    void print(ostream& where) const;

    int getIndexOfCard(const Letter& , const Number&) const;

};

#endif