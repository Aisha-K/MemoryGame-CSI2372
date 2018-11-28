#include "cardDeck.h"
#include "card.h"

//public CardDeck method to make a card deck and return the same CardDeck throughout program execution
CardDeck& CardDeck::make_CardDeck(){
    static CardDeck c= CardDeck();  
    return c;
}

/**
 * returns next card in the card deck
 */
Card* CardDeck::getNext(){
    if(!isEmpty()){
        return cardsArr[nextCardIndex++];
    }

    //loops back around to return first card
    nextCardIndex=0;
    return cardsArr[nextCardIndex++];
}

/**
 * returns true if all cards have been handed out
 */
bool CardDeck::isEmpty() const{
    return nextCardIndex>=cardsArr.size();
}

int main(){

}