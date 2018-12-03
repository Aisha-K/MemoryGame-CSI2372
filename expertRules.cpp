#include "expertRules.h"
#include <iostream>


ExpertRules::ExpertRules(): blockedCard(nullptr){
}

/**
 * decides which function to call for the special ability
 */
void ExpertRules::specialRule(Game& g, Board& b){
    //receiving current card to check for exceptional rules based on card animal
    const Card* currCard = g.getCurrentCard();

    Card::FaceAnimal animal = *currCard;
    switch(animal){
        //Animal was a crab
        case 0:
            cout << "Crab special ability called" <<endl;
            Crab(g);
            break;
        //Animal was a Penguin
        case 1:
            cout << "Penguin special ability called" <<endl;
            Penguin(g,b);
            break;
        //Animal was a Octopus
        case 2:
            cout << "Octopus special ability called" <<endl;
            Octopus(g);
            break;
        //Animal was a Turtle
        case 3:
            cout << "Turtle special ability called" <<endl;
            Turtle(g);
            break;
        //Animal was a Walrus
        case 4:
            cout << "Walrus special ability called" <<endl;
            Walrus(g);
            break;
    }
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

void ExpertRules::Penguin(Game& g, Board& b){

} 

void ExpertRules::Octopus(Game& g){

} 

void ExpertRules::Turtle(Game& g){

} 

void ExpertRules::Walrus(Game& g){

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
    ExpertRules *e = new ExpertRules();

    g->setCurrentCard( g->getCard(Board::A,Board::two) );
    std::cout << *g << endl;
    //testing if correct card special ability is called
    e->specialRule(*g,*b);      //doing special rule corresponding to card flipped
}
#endif

