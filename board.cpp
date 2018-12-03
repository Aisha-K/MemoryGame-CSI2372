#include "board.h"
#include <iostream>

/**
 * Function to return true if card at position (letter,number) is faced up
 * Exception thrown if out of range
*/
bool Board::isFaceUp ( const Letter& letter, const Number& number) const{
    //checking for exception (invalid entry)
        checkForException(letter,number);
    
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
*/
Board::Board(): cardsOnBoard({}){
    makeCardsDisplay();
    //Selecting cards to be on board
    initializeDeck();
}


void Board::makeCardsDisplay(){
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
}

    /**returns index in the array of card pointers that the number and letter correspond to
    *throws OutOfRange exception if card is out of range
    */
    int Board::getCardIndex(const Letter& letter, const Number& num) const{

        //checking for exception (invalid entry)
        checkForException(letter,num);

        return letter*5 + num;       //5 cards per row, number = column
    }


    /**
     * returns the card corresponding to (Letter,Num) of the board
     * Will throw an exception out of range if (Letter,Num) invalid
     * (Throws exception in getCardIndex method)
    */
    Card* Board::getCard( const Letter& letter, const Number& num){
        //checking for exception (invalid entry)
        checkForException(letter,num);

        return cardsOnBoard[ getCardIndex(letter, num) ];
    }

    /**
     * Swaps the card given and the card at position letter,num
     * Also checks wether they were face down or face up to set the correct face
    */
    void Board::setCard( const Letter& letter, const Number& num, Card* card2Ptr){
        //checking for exception (invalid entry)
        checkForException(letter,num);

        //getting the index of the card (needed to retrieve letter and number)
        int card2Index=0;
        for(Card* cardOnBoard : cardsOnBoard){
            if(cardOnBoard==card2Ptr){
                break;
            }
            ++card2Index;
        }

        //getting the letter and number that the positions corresponds
        Board::Letter c2Let = static_cast<Board::Letter> (card2Index/5);
        Board::Number c2Num = static_cast<Board::Number> (card2Index%5 );
        
        //checking wether the cards were face up
        bool C1FaceUp = isFaceUp(letter, num);
        bool C2FaceUp= isFaceUp(c2Let, c2Num);

        //swapping ptrs
        Card* card1Ptr= cardsOnBoard[ getCardIndex(letter, num) ];
        cardsOnBoard[ getCardIndex(letter, num) ]= card2Ptr;
        cardsOnBoard[ card2Index ]= card1Ptr ;

        if( C2FaceUp ){  //updates string array so display shows new card, if it was already face up
             turnAlreadyFaceUpCardFaceUp(letter, num, card2Ptr);
        }
        else{ turnFaceDown(letter,num);
        }
        if(C1FaceUp){   //updates string array so display shows new card, if it was already face up
            turnAlreadyFaceUpCardFaceUp(c2Let,c2Num, card1Ptr);
        }
        else{ turnFaceDown(c2Let,c2Num);
        }
    }


//helper function to set an already face up card face up
void Board::turnAlreadyFaceUpCardFaceUp(Board::Letter let, Board::Number num, Card* card){
    //getting index of first position of the card, so top left value of card pos
    int row = getFirstIndexOfCard(let);
    int col = getFirstIndexOfCard(num);
    //replacing the string array's representation of the card to the face up representation
    (cardsDisplay[row]).replace(col, 3, (*card)(0) );
    (cardsDisplay[row+1]).replace(col, 3, (*card)(1) );
    (cardsDisplay[row+2]).replace(col, 3, (*card)(2) );    
}

/**
 * overwriting board "cout <<" operation to display the entire board in a board like manner
*/
 std::ostream& operator<<(std:: ostream& os, const Board& board){
     board.print( os );
     return os;
}

void Board::print(ostream& os) const{
    string boardPrefixes[5] = {"A","B","C","D","E"};
    int currentPrefixIndex = 0;
    string BoardString = "";
    for (int i=0; i< cardsDisplay.size(); ++i){
        if ((i % 4)==1)
            BoardString = BoardString + boardPrefixes[currentPrefixIndex++] + " ";
        else
            BoardString = BoardString + "  ";

        for (int x=0; x<cardsDisplay.size(); ++x){
            BoardString = BoardString+cardsDisplay[i][x];
        }
        BoardString = BoardString + "\n";
    }

    BoardString = BoardString + "\n" + "   1   2   3   4   5" +"\n";
    os << BoardString;

}

/**
 * Function to turn the card at specified (Letter,Number) face up
 * Returns false if card at (Letter,Number) is already face up
 * Throws exception if specified location out of bounds
*/
bool Board::turnFaceUp(const Letter& let, const Number& num){
    //checking for exception (invalid entry)
    checkForException(let,num);
    
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

/**
 * Changes state of specified card to face down
 * Returns false if card at already face down
 * Throws exception if specified location out of bounds
*/
bool Board::turnFaceDown(const Letter& let, const Number& num){
    //checking for exception (invalid entry)
    checkForException(let,num);
    
    //card already face down
    if (!isFaceUp(let,num)){
        return false;
    }

    //getting index of first position of the card, so top left value of card pos
    int row = getFirstIndexOfCard(let);
    int col = getFirstIndexOfCard(num);
    //replacing the string array's representation of the card to the face up representation
    (cardsDisplay[row]).replace(getFirstIndexOfCard(num), 3, "zzz" );
    (cardsDisplay[row+1]).replace(getFirstIndexOfCard(num), 3, "zzz" );
    (cardsDisplay[row+2]).replace(getFirstIndexOfCard(num), 3, "zzz" );

    //true since successfully turned over
    return true;
}

/**
 * Reset's all cards back to face down
 */
void Board::reset(){
    for ( auto &tableRow : cardsDisplay){
        for (int i=0; i< tableRow.size(); ++i){
            if (tableRow[i] != *" "){
                tableRow[i] = *"z";
            }
        }
    }
    initializeDeck();

}

void Board::initializeDeck(){

    Deck<Card>& cardDeck = CardDeck::make_CardDeck();

    for(int i=0; i<cardsOnBoard.size(); ++i){
        cardsOnBoard[i] = cardDeck.getNext();
    }
}

void Board::checkForException(const Letter& letter, const Number& num) const{
    if( letter==C && num==three){   //if blank card in centre
            throw std::out_of_range ("Exception: Position C3 holds no card");
        }

        if( letter>E || letter<A || num>five || num<one ){   //if out of bounds
            throw std::out_of_range ("Exception: Out of range");
        }
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
    b->setCard(Board::Letter::D,Board::Number::four, card1);  
    cout << "Display once both cards swapped \n" << *b <<endl;
    Card* card2=b->getCard(Board::Letter::A,Board::Number::one);
    b->setCard(Board::Letter::D,Board::Number::three, card2); 
    cout << "Display once A1 and D3 swapped \n" << *b <<endl;

    //Testing throwing exceptions
    cout<<"Testing throwing exceptions: ";

    try{
        card1=b->getCard(Board::Letter::C,Board::Number::three);    //Testing blank position C3
    }
    catch(exception& e){
        cout<<"\n Trying getCard with position C3: " << e.what();
    }

    try{    //testing enum Number equivalent to int 5 using static_cast (should fail because we only have 5 enums mapped to int's 0-4)
        b->turnFaceUp(Board::Letter::A, static_cast<Board::Number>(5) ) ; 
    }
    catch(exception& e){
        cout<<"\n Trying turnFaceUp with position A6: " << e.what();
    }

        try{
        b->getCard( static_cast<Board::Letter>(-1) , Board::Number::five) ; 
    }
    catch(exception& e){    //testing enum letter equivalent to int -1 using static_cast (should fail because we only have 5 enums mapped to int's 0-4)
        cout<<"\n Trying getCard with position enum Letter=-1 and column 5: " << e.what() <<"\n";
    }

    cout <<endl;
    
    //resetting board
    b->reset();
    cout << "Board reset:" <<endl << *b <<endl;

    cout << "Testing turn card down" <<endl;
    b->turnFaceUp(Board::Letter::D,Board::Number::two);
    cout << "Facedown succesful? " << b->turnFaceDown(Board::Letter::D,Board::Number::two) <<endl;
}

#endif