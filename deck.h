#ifndef DECK_H
#define DECK_H
#include <array>
#include <algorithm>    // std::random_shuffle
#include <random>

template<class C> //can write <typename C> too
class Deck{
    public:
        virtual bool isEmpty() const=0; 
        virtual void shuffle()=0;
        virtual C* getNext()=0;

};


#endif