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
void ExpertRules::Crab(Game& g){

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
 * fuction to return if entered string has correct format
 */
Card* ExpertRules::getUserEntry(){
 
}

#ifdef DEBUG_EXPERTRULES
int main(){
    Board *b = new Board();
    Game *g = new Game(*b);
    ExpertRules *e = new ExpertRules();

    g->setCurrentCard( g->getCard(Board::C,Board::two) );
    std::cout << *g << endl;
    //testing if correct card special ability is called
    e->specialRule(*g,*b);
}
#endif

