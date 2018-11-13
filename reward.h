#include<ostream>
#include "rewardDeck.h"

#ifndef REWARD_H
#define REWARD_H


class Reward{
    int rubyValue;

    //gives friend access to the function Reward* Reward(int rubyValue) in class rewardDeck, which will create Reward objects
    friend Reward* RewardDeck::Reward(int rubyValue);

    Reward(int rubyVal): rubyValue(rubyVal){};  //constructor
    friend std::ostream& operator<<(std:: ostream& stream, const Reward& reward);

};

#endif