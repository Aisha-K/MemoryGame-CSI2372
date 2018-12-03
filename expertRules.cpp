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
            validMove = Crab(g,b);
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
bool ExpertRules::Crab(Game& g,Board &b){
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
    } else {    //player flip was valid so do it's special effect
        cout << g <<endl;
        userStillActive = specialRule(g,b);
    }

    return userStillActive;
}

/**
 * p can turn a face up card face down
 */
bool ExpertRules::Penguin(Game& g, Board& b){

    //if first card then don't let player turn a card face down
    if (g.getPreviousCard() == nullptr ){
        cout << "You can not use powers of Penguin card since this is the first card" << endl;
        return true;
    }


    //ensuring user selected a valid face up card
    bool validEntry = false;
    //loop to turn card facedown
    cout << "You can turn a face up card to face down. ";
    while(!validEntry){
        string input = getUserEntry();

        bool turnDownWorked = false;

        try{
            turnDownWorked = b.turnFaceDown(static_cast<Board::Letter>( (int)input[0] -65 ) ,static_cast<Board::Number>( (int)input[1] -49 ));
            if (turnDownWorked){    //If turn down returned true then entry was valid
                validEntry = true;
            }else{      //turnDown did not work so entry was not valid
                validEntry = false;
                cout << "Can't turn that card face down, choose another. ";
            }
        }catch(...){
            cout << "Can't turn that card face down, choose another. ";
        }
    }
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

/**
 * A facedown card can be blocked for the next player
 */
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

    Player *p1 = new Player("Name1");
    Player *p2 = new Player("Name2");
    g->addPlayer(*p1);
    g->addPlayer(*p2);

    ExpertRules *e = new ExpertRules();
    //----TEST0----
    g->setCurrentCard( g->getCard(Board::B,Board::two) );   //should not ask for card to turn down
    e->specialRule(*g,*b);      //doing special rule corresponding to card flipped
    cout << *g << endl;

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
    //testing if correct card special ability is called
    e->specialRule(*g,*b);      //doing special rule corresponding to card flipped
    std::cout << *g << endl;


    //----TEST3---
    g->setCurrentCard( g->getCard(Board::B,Board::one) );   //should ask for card to turn down
    cout << *g << endl;
    e->specialRule(*g,*b);      //doing special rule corresponding to card flipped
    cout << *g << endl;
}
#endif

