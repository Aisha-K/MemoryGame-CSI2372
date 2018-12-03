#include "expertDisplay.h"


ExpertDisplay::ExpertDisplay(){
    makeCardsDisplay();
}

void ExpertDisplay::makeCardsDisplay(){
    for( auto& row: eCardsDisplay){
        row=  "                                                                                              ";             //one row is 95 char long
    }
}



bool ExpertDisplay::turnFaceUp(const Letter& let, const Number& num){
    Board::turnFaceUp(let, num);
    faceUpCards.push_back( cardsOnBoard[ getCardIndex(let, num) ]  );

    int size= faceUpCards.size();
    int column= (size-1)*4;         //column where card starts

    //displaying card
    (eCardsDisplay[0]).replace(column, 3, (*getCard(let,num))(0) );
    (eCardsDisplay[1]).replace(column, 3, (*getCard(let,num))(1) );
    (eCardsDisplay[2]).replace(column, 3, (*getCard(let,num))(2) );

    (eCardsDisplay[3]).replace(column, 2, enumPosToString(let, num) );  //Adding position, ex:"A0"
}


//returns a string representation from enum letter and num, ex: A0 to "A0"
bool ExpertDisplay::turnFaceDown(const Letter& let, const Number& num){
    Board::turnFaceDown(let, num);
    //FINISH
}



string ExpertDisplay::enumPosToString(const Board::Letter& let, const Board::Number& num){
    int letterEnum =let;
    int numEnum = num;
    return ( static_cast<char>(let +65) + std::to_string(numEnum+1) );
}

//reset to all blank spaces
void ExpertDisplay::reset(){
    Board::reset();
    makeCardsDisplay();
}

//called by cout<< function
void ExpertDisplay::print(ostream& where) const{
    for( auto row: eCardsDisplay){
        where<< row << "\n";
    }
}

#ifdef DEBUG_EXPERTDISPLAY
#include <iostream>

int main(){

    Board * e= new ExpertDisplay();

    //board before any cards are turned over
    cout<< *e << endl;

    //testing board display after cards turned over
    e->turnFaceUp(Board::B, Board::one);
    e->turnFaceUp(Board::A, Board::two);
    std::cout<< *e;



}

#endif