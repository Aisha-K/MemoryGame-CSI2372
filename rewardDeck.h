
#ifndef REWARDDECK_H
#define REWARDDECK_H

//#define DEBUG_REWARDDECK

#include "deck.h"
#include "reward.h" 

class RewardDeck : public Deck<Reward> {

    #ifdef DEBUG_REWARDDECK     //set to priate to test functionality of private functions
    public:
    #endif

    static std::array<Reward*,7> rewardsArr;
    int nextRewardIndex;

    RewardDeck(){nextRewardIndex=0;}
    //private copy and assignment operators to prevent assignning/copying
    RewardDeck& operator=(const RewardDeck& rewardDeck);
    RewardDeck(const RewardDeck& rewardDeck);

    //overriding abstract class methods
    bool isEmpty() const; 
    void shuffle();
    Reward* getNext();

    ~RewardDeck();

public:
   static RewardDeck& make_RewardDeck();

};

#endif