#include <string>
#include "Reward.h"

#ifndef PLAYER_H

class Player{
    std::string name;
    std::string sideOfBoard;
    int numOfRubies;
    bool isActive;

    public:
    std::string getName() const;
    void setActive(bool);
    int getRubies() const;
    void addReward(const Reward&);
    void setDisplay(bool endOfGame);
    
};

#endif