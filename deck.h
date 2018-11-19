#ifndef DECK_H
#define DECK_H

template<class C> //can write <typename C> too
class Deck{
    bool isEmpty() const;
    void shuffle();
    C* getNext();

};


#endif