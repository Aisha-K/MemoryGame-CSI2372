#include<ostream>
#include "rewardDeck.h"

#ifndef REWARD_H
#define REWARD_H

class Reward{
    int rubyValue;

    friend RewardDeck Reward(int rubyValue);
    friend std::ostream& operator<<(std:: ostream& stream, const Reward& reward);

};

#endif