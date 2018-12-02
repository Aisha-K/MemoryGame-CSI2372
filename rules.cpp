#include "rules.h"

/**
 * Default constructor
 */
Rules::Rules(): currPlayerSide(0){
}

/**
 * returns true is previous and current card match; false otherwise.
 */
bool Rules::isValid(const Game& game){
    const Card* cCurr= game.getCurrentCard();
    const Card* cPrev= game.getPreviousCard();

    if (cPrev==nullptr){    //no cards or only 1 card flipped, must be valid
        return true;
    }

    //returns true if the cards have the same colour OR same animal
    return ( Card::FaceAnimal(*cCurr)==Card::FaceAnimal(*cPrev) || 
    Card::FaceBackground(*cCurr)==Card::FaceBackground(*cPrev) ) ;
}

/**
 * returns true if the number of rounds has reached 7.
 */
bool Rules::gameOver(const Game& game){
    return game.getRound()==7;
}

/**
 * returns true if there is only one active Player left.
 */
bool Rules::roundOver(const Game& game){
    int activePlayerCount = getNumberOfActivePlayers(game);

    //if there are more than 1 players active then round is not over
    if (activePlayerCount >1)
        return false;

    //round is over once there is only 1 player active
    return true;
}

/**
 * Helper function to return the number of active players in a game
 */
int Rules::getNumberOfActivePlayers(const Game& game) {
    int activePlayerCount = 0;
    
    for (int i=0; i<4; i++){
        try {
            Player p = game.getPlayer(Player::Side(i));
            if (p.isActive())
                activePlayerCount++;
        }
        catch(...){
            
        }
    }
    return activePlayerCount;
}


/**returns next available active player
*Atleast one player must be active for this function
*/
const Player& Rules::getNextPlayer(const Game& game){

    int totalPlayerCount = 0;
    
    for (int i=0; i<4; i++){    //getting total number of players
        try {
            Player p = game.getPlayer(Player::Side(i));
                totalPlayerCount++;
        }
        catch(...){
        }
    }

    if(currPlayerSide==totalPlayerCount){   //if we're at the last player, go back to frst player (side 0)
        currPlayerSide=0;
    }


    //gets player at currSide and increments to set it at next player
    const Player& nextPlayer= game.getPlayer( static_cast<Player::Side>(currPlayerSide ++ ) );

    if(!nextPlayer.isActive()){ //if this player is not active, get next player
        return getNextPlayer(game);
    }

    return nextPlayer;  //otherwise return the player we got
}



//-------TESTING-------
#ifdef DEBUG_RULES
#include <iostream>
int main(){
    //testing active player count
    Board *b= new Board();
    Game *g = new Game(*b);
    Player *p = new Player("Zaid");
    Player *x = new Player("Aisha");
    g->addPlayer(*p);
    g->addPlayer(*x);

    Rules r;
    cout << "\nTesting active player counts: " << r.getNumberOfActivePlayers(*g) <<endl;  // Output: 2


    //testing card flipping and match
    cout << boolalpha;
    cout << "Is it valid? no cards flipped: " << r.isValid(*g) <<endl;

    Card *c = g->getCard(Board::A,Board::three);
    g->setCurrentCard(c);
    Card *d = g->getCard(Board::B,Board::two);
    g->setCurrentCard(d);
    cout << "Is it valid? A3 & B2: " << r.isValid(*g) <<endl;

    Card *e = g->getCard(Board::D,Board::five);
    g->setCurrentCard(e);
    cout << "Is it valid? B2 & D5: " << r.isValid(*g) <<endl;

    cout << *g <<endl;


    //testing get next active player
    cout << "testing getNextPlayer: "<< r.getNextPlayer( *g );
    cout << "\ntesting getNextPlayer: "<< r.getNextPlayer( *g );
    p->setActive(false);
    cout << "\n testing getNextPlayer when zaid is inactive: "<< r.getNextPlayer( *g );
}
#endif