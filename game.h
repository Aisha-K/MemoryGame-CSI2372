#ifndef GAME_H
#define GAME_H
//#define DEBUG_GAME //runs unit tests in main
#include "board.h"
#include "player.h"
#include <vector>

class Game{
    Board &b;
    int round;
    vector<Player> players;
    const Card *prevCard;       //ptr to a const Card
    const Card *currCard;        //ptr to a const Card

    //cout << operator override
    friend std::ostream& operator<<(std:: ostream& os, const Game& game);
    //class methods
    public:
    Game();
    int getRound() const;
    void addPlayer( const Player& );
    const Player& getPlayer( Player::Side ) const;
    const Card* getPreviousCard() const;
    const Card* getCurrentCard() const;
    void setCurrentCard( const Card*);
    Card* getCard( const Board::Letter&, const Board::Number& );
    void setCard( const Board::Letter&, const Board::Number&, Card* );
 


};

#endif