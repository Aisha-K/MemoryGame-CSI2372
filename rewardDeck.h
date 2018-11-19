
#ifndef REWARDDECK_H
#define REWARDDECK_H

#include "deck.h"

class Reward; //forward declaration

class RewardDeck : public Deck<RewardDeck> {
    Reward *rewardPtr;
    //Reward reward;

public:
    RewardDeck();

    //has frienc access to reward, will create objects of type Reward
    Reward* Reward(int rubyValue);




};

#endif