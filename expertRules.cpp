#include "expertRules.h"

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
            Crab(g);

        //Animal was a Penguin
        case 1:
            Penguin(g,b);

        //Animal was a Octopus
        case 2:
            Octopus(g);

        //Animal was a Turtle
        case 3:
            Turtle(g);

        //Animal was a Walrus
        case 4:
            Walrus(g);
    }
}

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

#ifdef DEBUG_EXPERTRULES
int main(){

}
#endif