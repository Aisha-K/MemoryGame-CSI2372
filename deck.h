#ifndef DECK_
#define DECK_

template<class C> //can write <typename C> too
class Deck{
    bool isEmpty() const;
    void shuffle();
    C* getNext();

};


#endif