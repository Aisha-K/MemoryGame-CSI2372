
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "reward.h"

class Player{

    public:
        enum Side {top, bottom, left, right};

    private:
    std::string name;
    std::string sideOfBoard;
    int numOfRubies;
    bool isPlayerActive;
    Side side;

    public:
    std::string getName() const {return name;}
    void setActive(bool active) { isPlayerActive=active; }
    bool isActive() const {return isPlayerActive;}
    int getNRubies() const {return numOfRubies; }
    void addReward(const Reward&);
    void setDisplay(bool endOfGame);
    Side getSide() const {return side;}
    void setSide(Side newSide) {side=newSide;}
    friend std::ostream& operator<<(std:: ostream& os, const Player& player);

    
};

#endif