#include "expertRules.h"
#include <iostream>


ExpertRules::ExpertRules(): blockedCard(nullptr){
}

/**
 * decides which function to call for the special ability
 * returns true if player is still active after their special move
 * returns false if player's move was invalid(wrong cards matched) so they should now be inactive
 */
bool ExpertRules::specialRule(Game& g, Board& b){
    //receiving current card to check for exceptional rules based on card animal
    const Card* currCard = g.getCurrentCard();
    Card::FaceAnimal animal = *currCard;

    bool validMove =false;
    switch(animal){
        //Animal was a crab
        case 0:
            cout << "Crab special ability called" <<endl;
            validMove = Crab(g);
            break;
        //Animal was a Penguin
        case 1:
            cout << "Penguin special ability called" <<endl;
            validMove = Penguin(g,b);
            break;
        //Animal was a Octopus
        case 2:
            cout << "Octopus special ability called" <<endl;
            validMove = Octopus(g);
            break;
        //Animal was a Turtle
        case 3:
            cout << "Turtle special ability called" <<endl;
            validMove = Turtle(g);
            break;
        //Animal was a Walrus
        case 4:
            cout << "Walrus special ability called" <<endl;
            validMove = Walrus(g);
            break;
    }

    return validMove;
}

/**
 * player must immediately turn over another card
 */
bool ExpertRules::Crab(Game& g){
    bool userStillActive = true;    //if user is still active after their second card move
    cout << "You can now go again. ";
    
    bool validEntry = false;
    
    while (!validEntry){
        string input = getUserEntry();

        try{
            g.setCurrentCard(g.getCard(static_cast<Board::Letter>( (int)input[0] -65 ) ,static_cast<Board::Number>( (int)input[1] -49 ) ));
            validEntry = true; //If exception not thrown then entry was valid
        }
        //exception thrown due to invalid entry
        catch(...){
            cout << "Can't turn that card face up, choose another. ";
        }
    }

    //checking if user should be out or not. If out then return false, and if user still active then return true
    //players flip was not valid so turn player inactive
    if (!isValid(g) ){
        userStillActive = false;
    }

    return userStillActive;
}

bool ExpertRules::Penguin(Game& g, Board& b){
    return true;
} 

bool ExpertRules::Octopus(Game& g){
    return true;
} 

/**
 * Next player in current round is skipped
 */
bool ExpertRules::Turtle(Game& g){
    cout << "Player " << getNextPlayer(g).getName() << " turn skipped" << endl;
    return true;
} 

bool ExpertRules::Walrus(Game& g){
    return true;
}

/**
 * function to allow user to select a card
 */
string ExpertRules::getUserEntry(){
    string userCardSelection;
    cout << "Select a card to turn over in this format: \"LetterNumber\", ex: \"A3\": ";
    cin >> userCardSelection;

    //ensuring length
    while (userCardSelection.size() != 2){
        cout << "The input much be of length 2 with form \"A3\". Re-enter: ";
        cin >> userCardSelection;
    }

    //ensuring bounds
    while (   (((int)userCardSelection[0] -65)<0)  || (((int)userCardSelection[0] -65)>4) ||
            (((int)userCardSelection[1] -49)<0) || (((int)userCardSelection[1] -49)>4)  ){
        cout << "Invalid entry: Ensure letter is from A-E and number is from 1-5. Re-enter:";
        cin >> userCardSelection;
    }

    return userCardSelection;
}

#ifdef DEBUG_EXPERTRULES
int main(){
    Board *b = new Board();
    Game *g = new Game(*b);

    Player *p1 = new Player("Player1");
    Player *p2 = new Player("Player2");
    g->addPlayer(*p1);
    g->addPlayer(*p2);

    ExpertRules *e = new ExpertRules();
    //----TEST1----
    //special rule for crab
    g->setCurrentCard( g->getCard(Board::A,Board::five) );
    std::cout << *g << endl;
    //testing if correct card special ability is called
    e->specialRule(*g,*b);      //doing special rule corresponding to card flipped

    //---TEST2----
    const Player &pnext = e->getNextPlayer(*g);
    cout << "Player, " << pnext.getName() <<" turn." <<endl;
    //special rule for turtle
    g->setCurrentCard( g->getCard(Board::D,Board::five) );
    std::cout << *g << endl;
    //testing if correct card special ability is called
    e->specialRule(*g,*b);      //doing special rule corresponding to card flipped
}
#endif

