#include "board.h"
#include "player.h"
#include <vector>

class Game{
    Board &b;
    int round;
    vector<Player> players;

//class methods
Game();
int getRound();
void addPlayer( const Player& );
Player& getPlayer( Player::Side );
const Card* getPreviousCard();
const Card* getCurrentCard();
void setCurrentCard( const Card*);
Card* getCard( const Board::Letter&, const Board::Number& );
void setCard( const Board::Letter&, const Board::Number&, Card* );


};