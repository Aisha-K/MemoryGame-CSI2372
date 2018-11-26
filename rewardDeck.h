
#ifndef REWARDDECK_H
#define REWARDDECK_H

#include "deck.h"
#include "reward.h" 

class RewardDeck : public Deck<Reward> {
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


public:
   static RewardDeck& make_RewardDeck();

};

#endif