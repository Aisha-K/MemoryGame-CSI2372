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

    class NoMoreCardsException : std::exception {
        public:
        const char * what () const throw (){
    	return "Exception: Not enough cards to make a deck";
        }
    };
    
    enum Letter { A, B, C, D, E};     //corresponding to row
    enum Number{ one, two, three, four, five};    //corresponds to column

    private:
    //holds array of Strigns correspoding to display of the game. 19 rows by 19 chars, 3*5 = 15, 15 + 4 spaces
    std::array<string,19> cardsDisplay;

    
    public:
    Board();     //ctor Board, throws not enough cards exception

    //functions below throw exception of type OutOfRange
    bool isFaceUp ( const Letter& , const Number&) const; 
    virtual bool turnFaceUp(const Letter& , const Number&); 
    virtual bool turnFaceDown(const Letter& , const Number&); 
    Card* getCard( const Letter&, const Number& );
    void setCard( const Letter&, const Number&, Card* );
    virtual void reset();

    //virtual destructorno implementation needed 
    //the responsibility of destructing the cards is external (external aggregation)
    virtual ~Board(){} 


    protected:
    //helper functions
    void checkForException(const Letter&, const Number&) const;
    int getCardIndex(const Letter& letter, const Number& number) const; //returns index in the array of card pointers that the number and letter correspond to
    int getCardIndex(const Card* card);
    virtual void print(ostream& where) const;
    //void modifyAlreadyFaceUpCard(const Letter&, const Number&, const Card* );


    private:
    friend std::ostream& operator<<(std:: ostream& os, const Board& board);  //cout << operator override
    void initializeDeck();

    // returns index corresponding to the first row of the display where the card corresponding
    //to the given Letter is stored, (same for the column if a Number is given)
    template<typename T>
    int getFirstIndexOfCard(T enumtype) const{
        return (enumtype*4);
    }

    void makeCardsDisplay();



};

#endif