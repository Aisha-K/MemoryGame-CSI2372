
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "reward.h"

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
    friend std::ostream& operator<<(std:: ostream& stream, const Player& player);

    
};

#endif