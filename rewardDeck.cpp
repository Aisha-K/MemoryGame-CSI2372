#include "rewardDeck.h"
//#include <iostream>

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
}


Reward* RewardDeck::getNext(){
    if(!isEmpty()){
        return rewardsArr[nextRewardIndex++];
    }

    //loops back around to return first card
    nextRewardIndex=0;
    return rewardsArr[nextRewardIndex++];
}

/**
 * returns true if all cards have been handed out
 */
bool RewardDeck::isEmpty() const{
    return nextRewardIndex>=rewardsArr.size();
}



// int main(){
//      RewardDeck& r= RewardDeck::make_RewardDeck();

//     for(Reward* p: r.rewardsArr){
//             std::cout<< *p << ", ";
//     }
//         std::cout<<" ....  \n";

//     while(!r.isEmpty()){
//         std::cout<< *(r.getNext())<<" ";
//     }
//     std::cout<<" .... \n";

//     r.shuffle();

//     for(Reward* p: r.rewardsArr){
//             std::cout<< *p<<", ";
//     }

//     std::cout<<" .... \n";

//     for(int i=0; i<7; i++){
//         std::cout<< *(r.getNext())<<" ";
//     }
//     std::cout<<" .... \n";


//  }