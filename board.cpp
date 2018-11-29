#include "board.h"

/**
 * Function to return true if card at position (letter,number) is faced up
*/
bool Board::isFaceUp ( const Letter& letter, const Number& number) const{
    int row = getFirstIndexOfCard(letter);
    int col = getFirstIndexOfCard(number);

    //the first position of the card (upper left corner) doesn't equal z so it must be face up
    if (cardsDisplay[row][col] != "z"){
        return true;
    }

    return false;
}

//Board::Board(){
//
//}