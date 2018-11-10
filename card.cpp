#include "card.h"

//card constructor
Card::Card(FaceAnimal faceVal, FaceBackground colourVal): face{faceVal},
            colour{colourVal} {
}

Card& Card::operator=(const Card& card){}
Card::Card(const Card& card){}