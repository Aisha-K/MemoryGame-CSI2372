#include "card.h"

//card constructor
Card::Card(FaceAnimal faceVal, FaceBackground colourVal): face(faceVal),
            colour(colourVal) {
}

//Override for assignment operator to prevent assignment of cards
Card& Card::operator=(const Card& card){return *this;}
//Override for copy constructor to prevent copying of cards
Card::Card(const Card& card){}

int main(){

}