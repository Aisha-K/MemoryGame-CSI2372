#include "board.h"
#include <iostream>

/**
 * Function to return true if card at position (letter,number) is faced up
*/
bool Board::isFaceUp ( const Letter& letter, const Number& number) const{
    int row = getFirstIndexOfCard(letter);
    int col = getFirstIndexOfCard(number);

    //the first position of the card (upper left corner) doesn't equal z so it must be face up
    if ((cardsDisplay[row])[col] != *"z"){
        return true;
    }

    return false;
}

Board::Board():rewardDeck(RewardDeck::make_RewardDeck()),
                cardDeck(CardDeck::make_CardDeck()), cardsOnBoard({}){
    for ( auto &tableRow : cardsDisplay){
        tableRow = "                   ";
    }
    int currentRow = 1;
    for ( auto &tableRow : cardsDisplay){
        if (currentRow++ %4 != 0){
            for (int i=1; i<tableRow.size()+1; ++i){
            if (i%4 == 0){
                tableRow[i-1] = *" ";
            } else{
                //if middle card then leave it blank (checking +1 indexes to help with modulus of 4)
                if (((currentRow == 10)||(currentRow ==11)||(currentRow ==12)) && ((i==9)||(i==10)||(i==11) )){
                    tableRow[i-1] = *" ";
                } else {
                    tableRow[i-1] = *"z";
                }
            }
        }
        } else {
            for (int i=1; i<tableRow.size()+1; ++i){
                tableRow[i-1] = *" ";
            }
        }
    }


    //Selecting cards to be on board
    cardDeck.shuffle();
    for(int i=0; i<cardsOnBoard.size(); ++i){
        cardsOnBoard[i] = cardDeck.getNext();
    }
}

    //returns index in the array of card pointers that the number and letter correspond to
    int Board::getCardIndex(const Letter& letter, const Number& number) const{
        return letter*5 + number;
    }


    Card* Board::getCard( const Letter& letter, const Number& num){
        return cardsOnBoard[ getCardIndex(letter, num) ];
    }

    void Board::setCard( const Letter& letter, const Number& num, Card* cardPtr){
        cardsOnBoard[ getCardIndex(letter, num) ]= cardPtr;
        
    }

 std::ostream& operator<<(std:: ostream& os, const Board& board){
    string BoardString = "";
    for (int i=0; i< board.cardsDisplay.size(); ++i){
        for (int x=0; x<board.cardsDisplay.size(); ++x){
            BoardString = BoardString + board.cardsDisplay[i][x];
        }
        BoardString = BoardString + "\n";
    }
    os << BoardString;
    return os;
}

/**
 * Function to turn the card at specified (Letter,Number) face up
 * Returns false if card at (Letter,Number) is already face up
 * Throws exception if specified location out of bounds
*/
bool Board::turnFaceUp(const Letter& let, const Number& num){
    //If the card is already faceup then return false
    if (isFaceUp(let,num)){
        return false;
    }

    //true since successfully turned over
    return true;
}

//---------TESTING------------
#ifdef DEBUG_BOARD
int main(){
    //creating board to test on
    Board *b = new Board();
    //testing the output of the default board
    cout << *b <<endl;

    //testing isFaceUp and turnFaceUp
    cout << std::boolalpha << "testing is faceup, pre turnover: " <<
    b->isFaceUp(Board::Letter::D,Board::Number::three) << endl; //false

    b->turnFaceUp(Board::Letter::D,Board::Number::three);
    cout << "testing is faceup, post turnover: " <<
    b->isFaceUp(Board::Letter::D,Board::Number::three) << endl; //true

}
#endif