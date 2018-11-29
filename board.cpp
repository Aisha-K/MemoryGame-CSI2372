#include "board.h"
#include <iostream>

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

Board::Board():rewardDeck(RewardDeck::make_RewardDeck()),
                cardDeck(CardDeck::make_CardDeck()){
    int currentRow = 1;
    for ( auto &tableRow : cardsDisplay){
        if (currentRow++ %4 != 0){
            for (int i=1; i<tableRow.size()+1; ++i){
            if (i%4 == 0){
                tableRow[i-1] = " ";
            } else{
                //if middle card then leave it blank (checking +1 indexes to help with modulus of 4)
                if (((currentRow == 10)||(currentRow ==11)||(currentRow ==12)) && ((i==9)||(i==10)||(i==11) )){
                    tableRow[i-1] = " ";
                } else {
                    tableRow[i-1] = "z";
                }
            }
        }
        } else {
            for (int i=1; i<tableRow.size()+1; ++i){
                tableRow[i-1] = " ";
            }
        }
    }
     std::array<std::array<string,19>,19> cardsDisplay;
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

#ifdef DEBUG_BOARD
int main(){
    //creating board to test on
    Board *b = new Board();
    //testing the output of the default board
    cout << *b <<endl;

    //testing isFaceUp and turnFaceUp
    cout << std::boolalpha << "testing is faceup, pre turnover: " <<
    b->isFaceUp(Board::Letter::D,Board::Number::three) << endl;

    //b->turnFaceUp(Board::Letter::D,Board::Number::three);
    cout << "testing is faceup, post turnover: " <<
    b->isFaceUp(Board::Letter::D,Board::Number::three) << endl;

}
#endif