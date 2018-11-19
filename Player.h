
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "reward.h"

class Player{

    enum class Side {top, bottom, left, right};

    std::string name;
    std::string sideOfBoard;
    int numOfRubies;
    bool isActive;
    Side side;

    public:
    std::string getName() const {return name;}
    void setActive(bool isActive);
    int getNRubies() const {return numOfRubies; }
    void addReward(const Reward&);
    void setDisplay(bool endOfGame);
    Side getSide() {return side;}
    void setSide(Side newSide) {side=newSide;}
    friend std::ostream& operator<<(std:: ostream& stream, const Player& player);

    
};

#endif