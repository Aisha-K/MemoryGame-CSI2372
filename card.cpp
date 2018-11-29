#include "card.h"
#include <iostream>

//card constructor
Card::Card(FaceAnimal faceVal, FaceBackground colourVal, int rows): face(faceVal),
            colour(colourVal), numRows(rows) {
}

//Override for assignment operator to prevent assignment of cards
Card& Card::operator=(const Card& card){return *this;}
//Override for copy constructor to prevent copying of cards
Card::Card(const Card& card){}

//returns the number of rows for the card
int Card::getNRows() const{
    return numRows;
}

//returns the string corresponding to the row i for a card
string Card::operator()(int i){
    //enum returns an index so can use it with string of names to get card row string
    string row;

    if (i==0 || i==2){
        row.append(FaceBackgroundString[colour]);
        row.append(FaceBackgroundString[colour]);
        row.append(FaceBackgroundString[colour]);
    }else{
        row.append(FaceBackgroundString[colour]);
        row.append(FaceAnimalString[face]);
        row.append(FaceBackgroundString[colour]);
    }

    return row;
}