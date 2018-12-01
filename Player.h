
#ifndef PLAYER_H
#define PLAYER_H
//#define DEBUG_PLAYER

#include <string>
#include "reward.h"

class Player{

    public:
        //enum type for the side of the board
        enum Side {top, bottom, left, right};

    //class variables
    private:
    std::string name;
    int numOfRubies;
    bool isPlayerActive;
    Side side;
    bool gameEnded;

    //class methods
    public:
    Player(std::string);
    std::string getName() const;
    void setActive(bool active);
    bool isActive() const;
    int getNRubies() const;
    void addReward(const Reward&);
    void setDisplayMode(bool endOfGame);
    Side getSide() const;
    void setSide(Side newSide);
    friend std::ostream& operator<<(std:: ostream& os, const Player& player);

};

#endif