#include "board.h"
#include <iostream>

/**
 * Function to return true if card at position (letter,number) is faced up
*/
bool Board::isFaceUp ( const Letter& letter, const Number& number) const{
    getCardIndex(letter, number); //checking if a valid position was entered, throws exception of type OutOfRange if not valid

    int row = getFirstIndexOfCard(letter);
    int col = getFirstIndexOfCard(number);

    //the first position of the card (upper left corner) doesn't equal z so it must be face up
    if ((cardsDisplay[row])[col] != *"z"){
        return true;
    }

    return false;
}

/**
 * Board constructor
 * initializes board and all variables
 * shuffles and selects card to be used in this game
*/
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

    /**returns index in the array of card pointers that the number and letter correspond to
    *throws OutOfRange exception if card is out of range
    */
    int Board::getCardIndex(const Letter& letter, const Number& num) const{

        if( letter==C && num==three){   //if blank card
            throw std::out_of_range ("Exception: Position C3 holds no card");
        }

        if( letter>D || num>five){   //if blank card
            throw std::out_of_range ("Excception: Out of range");
        }

        return letter*5 + num;       //5 cards per row, number = column
    }


    /**
     * returns the card corresponding to (Letter,Num) of the board
    */
    Card* Board::getCard( const Letter& letter, const Number& num){
        
        return cardsOnBoard[ getCardIndex(letter, num) ];
    }

    /**
     * Replaces the card corresponding to (Letter,Num) of the board
     * with the card pointer provided as the third arguement
    */
    void Board::setCard( const Letter& letter, const Number& num, Card* cardPtr){
        cardsOnBoard[ getCardIndex(letter, num) ]= cardPtr;


        if(isFaceUp(letter, num)){  //updates string array so display shows new card, if it was already face up

                //getting index of first position of the card, so top left value of card pos
                int row = getFirstIndexOfCard(letter);
                int col = getFirstIndexOfCard(num);
                //replacing the string array's representation of the card to the face up representation
                (cardsDisplay[row]).replace(getFirstIndexOfCard(num), 3, (*getCard(letter,num))(0) );
                (cardsDisplay[row+1]).replace(getFirstIndexOfCard(num), 3, (*getCard(letter,num))(1) );
                (cardsDisplay[row+2]).replace(getFirstIndexOfCard(num), 3, (*getCard(letter,num))(2) );
        }
        
    }

/**
 * overwriting board "cout <<" operation to display the entire board in a board like manner
*/
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
    getCardIndex(let, num); //checking if a valid position was entered, throws exception of type OutOfRange if not valid

    //If the card is already faceup then return false
    if (isFaceUp(let,num)){
        return false;
    }

    //getting index of first position of the card, so top left value of card pos
    int row = getFirstIndexOfCard(let);
    int col = getFirstIndexOfCard(num);
    //replacing the string array's representation of the card to the face up representation
    (cardsDisplay[row]).replace(getFirstIndexOfCard(num), 3, (*getCard(let,num))(0) );
    (cardsDisplay[row+1]).replace(getFirstIndexOfCard(num), 3, (*getCard(let,num))(1) );
    (cardsDisplay[row+2]).replace(getFirstIndexOfCard(num), 3, (*getCard(let,num))(2) );

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

    cout << *b <<endl;

    //testing getCard, and setCard by swapping 2 cards 
    b->turnFaceUp(Board::Letter::D,Board::Number::four);
    cout << "Displaying two cards to be swapped \n" << *b <<endl;

    Card* card1=b->getCard(Board::Letter::D,Board::Number::three);  
    Card* card2=b->getCard(Board::Letter::D,Board::Number::four);
    b->setCard(Board::Letter::D,Board::Number::three, card2);   
    b->setCard(Board::Letter::D,Board::Number::four, card1);

    cout << "Display once both cards swapped \n" << *b <<endl;

    cout<<"Testing throwing exceptions: ";

    try{
        card1=b->getCard(Board::Letter::C,Board::Number::three);
    }
    catch(exception& e){
        cout<<"\n Trying getCard with position C3: " << e.what();
    }

    try{
        b->turnFaceUp(Board::Letter::E,Board::Number::three); 
    }
    catch(exception& e){
        cout<<"\n Trying turnFaceUp with position E3: " << e.what() <<"\n";
    }


}

#endif