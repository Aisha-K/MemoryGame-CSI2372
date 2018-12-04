#include "rewardDeck.h"

std::array<Reward*,7> RewardDeck::rewardsArr={new Reward(1), new Reward(1), new Reward(1), new Reward(2), new Reward(2), new Reward(3), new Reward(4)};


/**
 * Using the singleton design pattern, same instance of RewardDeck will always be returned
 */
RewardDeck& RewardDeck::make_RewardDeck(){
    static RewardDeck r= RewardDeck();  
    return r;
}

void RewardDeck::shuffle(){
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(rewardsArr), std::end(rewardsArr), rng);
    nextRewardIndex=0;
}

/**
 * returns next card or nullptr if deck is empty
 */
Reward* RewardDeck::getNext(){
    if(!isEmpty()){
        return rewardsArr[nextRewardIndex++];
    }

    return nullptr;
}

/**
 * returns true if all cards have been handed out
 */
bool RewardDeck::isEmpty() const{
    return nextRewardIndex>=rewardsArr.size();
}

/**
 * Destructor for child class RewardDeck
 * Deletes all rewards and frees up their memory
 */
RewardDeck::~RewardDeck(){
    for (Reward* r: rewardsArr){
        delete r;
    }
}


#ifdef DEBUG_REWARDDECK
#include <iostream>
int main(){
     RewardDeck& r= RewardDeck::make_RewardDeck();  //create rewarddeck

    for(Reward* p: r.rewardsArr){       //printing rewards from variable rewardsArr std::array directly
        std::cout<< *p << ", ";
    }
        std::cout<<" \n";

    while(!r.isEmpty()){                    //printing rewards using getNext
        std::cout<< *(r.getNext())<<", ";
    }
    std::cout<<" \n";

    r.shuffle();    //shuffle

    for(Reward* p: r.rewardsArr){   //printing rewards from variable rewardsArr std::array directly
        std::cout<< *p<<", ";
    }

    std::cout<<"  \n";

     RewardDeck& r2= RewardDeck::make_RewardDeck();       //make new deck

    for(int i=0; i<7; i++){
        std::cout<< *(r2.getNext())<<", ";
    }
    std::cout<<"  \n";


 }
 #endif