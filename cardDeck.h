#ifndef CARDDECK_H_
#define CARDDECK_H_

#include "deck.h"
#include "card.h" 

class CardDeck: public Deck<Card>{
    static std::array<Card*,25> cardsArr;
    int nextCardIndex;

    private:
        CardDeck();
        //private copy and assignment operators to prevent assignning/copying
        CardDeck& operator=(const CardDeck& cardDeck);
        CardDeck(const CardDeck& cardDeck);

        //overriding abstract class methods
        bool isEmpty() const; 
        void shuffle();
        Card* getNext();

    public:
        static CardDeck& make_CardDeck();
};

#endif