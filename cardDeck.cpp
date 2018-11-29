#include "cardDeck.h"
#include "card.h"
#include <iostream>

//initialization of static var cardsArr
std::array<Card*,25> CardDeck::cardsArr={};

CardDeck::CardDeck(): nextCardIndex(0) {
    
    int arrayPos = 0;
    //populating cardsArr
    for (int face = Card::FaceAnimal::Crab; face != Card::FaceAnimal::Walrus +1; ++face){
        for (int background= Card::FaceBackground::Red; background != Card::FaceBackground::Yellow +1; ++background){
            cardsArr[arrayPos] = new Card(  Card::FaceAnimal(face), Card::FaceBackground(background));
            ++arrayPos;
        }

    }
}

//public CardDeck method to make a card deck and return the same CardDeck throughout program execution
CardDeck& CardDeck::make_CardDeck(){
    static CardDeck c = CardDeck();  
    return c;
}

/**
 * returns next card or nullptr if deck is empty
 */
Card* CardDeck::getNext(){
    if(!isEmpty()){
        return cardsArr[nextCardIndex++];
    }

    return nullptr;
}

void CardDeck::shuffle(){
    nextCardIndex = 0;
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(cardsArr), std::end(cardsArr), rng);
}

/**
 * returns true if all cards have been handed out
 */
bool CardDeck::isEmpty() const{
    return nextCardIndex>=cardsArr.size();
}

#ifdef DEBUG_CARDDECK
//main function for debugging
int main(){
    //creating card
    Deck<Card>& c= CardDeck::make_CardDeck();
    //printing the cards
    cout << "The cards are (unshuffled):" <<endl;
    //outputting cards
    while (!c.isEmpty()){
        Card* cardToTest = c.getNext();
        for (int i=0;i<3; ++i){
            cout<< (*cardToTest)(i) <<endl;
        }
        cout << endl;
    }

    //testing shuffle
    cout << "The cards are (shuffled):" <<endl;
    c.shuffle();
    while (!c.isEmpty()){
        Card* cardToTest = c.getNext();
        for (int i=0;i<3; ++i){
            cout<< (*cardToTest)(i) <<endl;
        }
        cout << endl;
    }
}
#endif