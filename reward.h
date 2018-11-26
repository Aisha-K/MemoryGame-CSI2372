#include<ostream>
#include "rewardDeck.h"

#ifndef REWARD_H
#define REWARD_H


class Reward{
    friend class RewardDeck;
    int rubyValue; //can be values 1 to 4, inclusive

    Reward(int rubyVal): rubyValue(rubyVal){}  //constructor
    friend std::ostream& operator<<(std:: ostream& os, const Reward& reward);
    //private copy and assignment ctors
    Reward& operator=(const Reward& reward);
    Reward(const Reward& reward);

    public:
    //For conversion of reward to int
    operator int() const{return rubyValue;}


};

#endif