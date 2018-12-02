#include "rules.h"
#include <iostream>

/**
 * Main method to act as a game engine
 */
int main(){

    //receiving game mode from user
    string userOrExpert;
    cout << "Do you want to play in (N)ormal mode or (E)xpert mode? Enter 'N' or 'E': " <<endl;
    cin >> userOrExpert;
    std::transform(userOrExpert.begin(), userOrExpert.end(),userOrExpert.begin(), ::toupper);
    while ( !((userOrExpert.compare("E") == 0)||(userOrExpert.compare("N")) ==0 ) ){
        cout << "Invalid entry: 'E' or 'N' " << endl;
        cin >> userOrExpert;
        std::transform(userOrExpert.begin(), userOrExpert.end(),userOrExpert.begin(), ::toupper);
    }
    Board *b = new Board();
    Game *g = new Game(*b);
    Rules r = Rules();

    vector<Player*> playersAdd;

    //getting player names, max of 4 players
    //creating and adding the players to the game
    cout << "Enter first players names " <<endl;
    string playerName;
    for (int i=0; i<4; ++i){
        cin >> playerName;
        Player *p = new Player(playerName);
        playersAdd.push_back(p);
        g->addPlayer(*p);

        if (i< 3){
            string addAnotherPlayer;
            cout << "Would you like to add another player? 'Y' for Yes, 'N' for No: ";
            cin >> addAnotherPlayer;
            //ensuring valid entry for add another player
            std::transform(addAnotherPlayer.begin(), addAnotherPlayer.end(),addAnotherPlayer.begin(), ::toupper);
            while ( !((addAnotherPlayer.compare("Y") == 0)||(addAnotherPlayer.compare("N")) ==0 ) ){
                cout << "Invalid entry: Enter 'Y' or 'N' :" << endl;
                cin >> addAnotherPlayer;
                std::transform(addAnotherPlayer.begin(), addAnotherPlayer.end(),addAnotherPlayer.begin(), ::toupper);
            }

            //user wants to stop adding players with only 1 player added (NO!)
            if ((i<1)&& (addAnotherPlayer.compare("N") == 0) ){
                cout << "You must have atleast 2 players, Enter player name:" << endl;
            } //User is has at least 2 entries so listen to their result and exit loop
            else if ( (addAnotherPlayer.compare("N") == 0) )
                break;
        }

    } cout <<endl;

    //Revealing players positions
    
    for (int i=0; i<4; i++){
        try {
            Player p = g->getPlayer(Player::Side(i)); //gets player at side i (top,bottom,left,right)

            //choosing cards to display based on which side they player is at
            switch ( i ){
                case 0 : b->turnFaceUp(Board::A, Board::two);
                    b->turnFaceUp(Board::A, Board::three);
                    b->turnFaceUp(Board::A, Board::four);
                break;
                case 1 :b->turnFaceUp(Board::E, Board::two);
                    b->turnFaceUp(Board::E, Board::three);
                    b->turnFaceUp(Board::E, Board::four); 
                break;
                case 2 : b->turnFaceUp(Board::B, Board::one);
                    b->turnFaceUp(Board::C, Board::one);
                    b->turnFaceUp(Board::D, Board::one);
                break;
                case 3 : b->turnFaceUp(Board::B, Board::five);
                    b->turnFaceUp(Board::C, Board::five);
                    b->turnFaceUp(Board::D, Board::five);
                break;
            }

            cout<<"Card reveal for player, Enter any key: " << p.getName() <<"\n";
            cin.get();  //pause to ensure other players do not see current players card reveal
            cout<< *g;
            b->reset(); //turns cards face down again
        }
        catch(...){ //player does not exist, throws exception
            
        }
    }


    while (!r.gameOver(*g)){
        b->reset(); //reset board
        //resetting all players to active
        for (int i=0;i<playersAdd.size();++i){
            playersAdd[i]->setActive(true);
        }

        


    }
    
}