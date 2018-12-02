#include "game.h"

/**
 * Constructor for game
 * Initialized Board
 */
Game::Game(Board &b): b(b), round(0), prevCard(nullptr), currCard(nullptr){

}

/**
 * Gives the current round between 0 and 6
 */
int Game::getRound() const{
    return round;
}

/**
 * Adds a player to the game
 * Ensures a player with that side doesn't previously exist
 */
void Game::addPlayer( const Player& p){
    
    Player newP = p;
    //ensuring players have a unique size and more then 4 players can't exist (same side conflict)
    if (players.size() < 4){
        newP.setSide( Player::Side(players.size())  );
        players.push_back(newP);
    }
}

/**
 * Returns the player at the side specified
 * If side specified doesn't exist, then throws exception
 */
const Player& Game::getPlayer( Player::Side s) const{
    
    for (const Player &player : players){
        if (player.getSide() == s)
            return player;
    }

    //throws exception if side isn't in range
    throw std::out_of_range ("Exception: Side not in players");
}


/**
 * Calls corresponding getCard of board
 */
Card* Game::getCard( const Board::Letter& letter, const Board::Number& num){
    return b.getCard(letter, num);
}

/**
 * Calls corresponding setCard of board
 */
void Game::setCard( const Board::Letter& letter, const Board::Number& num, Card* card){
    return b.setCard(letter,num, card);
}

/**
 * Returns the preious card that was turned, i.e. card turned by prev player
 */
const Card* Game::getPreviousCard() const{
    return prevCard;
}

/**
 * Returns current card
 */
const Card* Game::getCurrentCard() const{
    return currCard;
}

/**
 * sets current card by flipping given card and updating prev card and current card
 * however, if the card is already face up, turns it face down (for expert mode)
 */
void Game::setCurrentCard( const Card* givenCard){
    //updating current and prev card
    prevCard = currCard;
    currCard = givenCard;

    //getting the index of the card (needed to retrieve letter and number so we can call turnFaceUp)
    int cardIndex=0;
    for(Card* cardOnBoard : b.cardsOnBoard){
        if(cardOnBoard==givenCard){
            break;
        }
        ++cardIndex;
    }

    //getting the letter and number that the positions corresponds
    Board::Letter letter = static_cast<Board::Letter> (cardIndex/5);
    Board::Number num = static_cast<Board::Number> (cardIndex%5 );

    bool  turned= b.turnFaceUp(letter,num);

    // //if the card is already face up, we turn it face down
    if(!turned){
        b.turnFaceDown(letter,num);
    }
    
}


std::ostream& operator<<(std:: ostream& os, const Game& game){
    os << game.b << "\n";
    for (const Player &player : game.players){
        os << "\n" << player;
    }

    return os;
}


#ifdef DEBUG_GAME
#include <iostream>
int main(){
    Board *b = new Board();

    Game *game= new Game(*b);
    std::cout <<"new game state \n";
    std::cout << *game;

    //testing setting the player and game output w/ players
    Player *p = new Player("Zaid");
    Player *x = new Player("Aisha");
    Player *y = new Player("Pentel");
    Player *z = new Player("Bob");
    Player *w = new Player("Katarina");     //shouldn't be added (already 4 players)

    game->addPlayer(*p);
    game->addPlayer(*x);
    game->addPlayer(*y);
    game->addPlayer(*z);
    game->addPlayer(*w);

    cout << *game <<endl;

    //testing getCurrentcard when no card has been flipped yet
    std::cout<<"Testing get Current when no card has been flipped yet:  ";
    const Card* card0=game->getCurrentCard();
    if(card0==nullptr){
        std::cout<<"nullptr, no card has been flipped yet \n\n";
    }

    //test getCard and setCurrentCard by seeing if corresponding cards were flipped
    Card* card1=game->getCard(Board::A, Board::one);
    game->setCurrentCard(card1);
    card1=game->getCard(Board::B, Board::three);
    game->setCurrentCard(card1);
    Card* card2=game->getCard(Board::E, Board::five);
    game->setCurrentCard(card2);
    std::cout << "testing getCard and setCurrentCard by flipping cards at pos A1, B3, and E5 \n"<<*game<<endl<<endl;

    //test getCurrentCard, getPrevCard
    const Card* card3=game->getCurrentCard();
    const Card* card4= game->getPreviousCard();
    std::cout<<"Testing getCurrentCard and getPrevCard by printing out their middle rows\n";
    std::cout<< "current: "<< (*card3)(1)<<" previous: "<< (*card4)(1) <<"\n\n";

    //test setCard
    game->setCard(Board::E, Board::five, card1);
    game->setCard(Board::B, Board::three, card2);
    std::cout <<"testing setCard by switcing B3 and E5\n\n" << *game <<endl <<endl;

    //testing setCurrentCard when we want to turn a card face down
    game->setCurrentCard(card2);
    std::cout<<"Testing turning card at B3 down by calling setCurrentCard again\n"<< *game << endl<< endl;
}

#endif