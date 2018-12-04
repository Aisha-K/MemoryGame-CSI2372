#include "expertDisplay.h"
#include <iostream>

//constructor
ExpertDisplay::ExpertDisplay(){
    makeCardsDisplay();
}

//initializing rows
void ExpertDisplay::makeCardsDisplay(){
    for( auto& row: eCardsDisplay){
        row=  "                                                                                              ";             //one row is 95 char long
    }
}


//to turn the card at (letter,num) to face up
//parent call throws exceptions
bool ExpertDisplay::turnFaceUp(const Letter& let, const Number& num){
    bool b = Board::turnFaceUp(let, num);

    if(b){
    faceUpCards.push_back( cardsOnBoard[ getCardIndex(let, num) ]  );

    int size= faceUpCards.size();
    int column= (size-1)*4;         //column where card starts

    //displaying card
    (eCardsDisplay[0]).replace(column, 3, (*getCard(let,num))(0) );
    (eCardsDisplay[1]).replace(column, 3, (*getCard(let,num))(1) );
    (eCardsDisplay[2]).replace(column, 3, (*getCard(let,num))(2) );

    (eCardsDisplay[3]).replace(column, 2, enumPosToString(let, num) );  //Adding position, ex:"A0"
    }

    return b;
}



//Getting card index in cards array corresponding to the letter and number
int ExpertDisplay::getIndexOfCard(const Board::Letter& letter, const Board::Number& number) const{
    //checking for exception (invalid entry)
    checkForException(letter,number);

    int letterEnum =letter;
    int numEnum = number;
    string numLet = ( static_cast<char>(letter +65) + std::to_string(numEnum+1) );


    int index = eCardsDisplay[3].find( numLet) /4;

    return index;
}

//function to turn the card face down if not previously face down and then remove it from the display
bool ExpertDisplay::turnFaceDown(const Letter& let, const Number& num){
    
    bool b = Board::turnFaceDown(let, num);

    //only turn face down if it isn't already face down
    if (b){
        int index = getIndexOfCard(let,num);
        //std::cout<<let<<" "<<num<<" turn face down \n";
        faceUpCards.erase(faceUpCards.begin() + index);
        
        //Adding four empties to the end of row
        for (string& row: eCardsDisplay){
            row.replace(index*4, 4, "" );    //removing from the current display
            row += "    ";  //adding empties to end of row
        }

    }
    return b;
}


//returns string corresponding to letter and number
string ExpertDisplay::enumPosToString(const Board::Letter& let, const Board::Number& num){
    int letterEnum =let;
    int numEnum = num;
    return ( static_cast<char>(let +65) + std::to_string(numEnum+1) );
}

//reset to all blank spaces
void ExpertDisplay::reset(){
    faceUpCards.clear();
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


int main(){

    Board *e= new ExpertDisplay();

    //board before any cards are turned over
    cout<< *e << endl;

    //testing board display after cards turned over
    e->turnFaceUp(Board::B, Board::one);
    e->turnFaceUp(Board::A, Board::two);
    std::cout<< *e;

    //testing swap, with setCard
    Card* card= e->getCard( Board::A, Board::two );
    e->setCard(Board::B, Board::one, card);
    std::cout<< "testing swapping prev two turned up cards \n"<<*e;

    //testing board display
    e->turnFaceDown(Board::A,Board::two);
    std::cout<<"turned A2 face down \n"<< *e;

    //testing swap, with setCard
    card= e->getCard( Board::A, Board::two );
    e->setCard(Board::B, Board::one, card);
    std::cout<< "testing swapping face down adn face up card \n";
    std::cout<<*e;
    e->turnFaceUp(Board::A,Board::two);
    std::cout<<"turned A2 face up \n"<< *e;

    card= e->getCard( Board::A, Board::two );
    e->turnFaceDown(Board::B,Board::one);
    std::cout<<"turned B1 face down \n"<< *e;
    e->setCard(Board::B, Board::one, card);
    std::cout<< "testing swapping face down and face up card \n";
    std::cout<<*e;
}

#endif