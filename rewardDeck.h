#include "cardDeck.h"


#ifndef REWARDDECK_H
#define REWARDDECK_H

class Reward;

class RewardDeck{
    Reward *rewardPtr;
    //Reward reward;

public:
    RewardDeck();

    //has frienc access to reward, will create objects of type Reward
    Reward* Reward(int rubyValue);




};

#endif