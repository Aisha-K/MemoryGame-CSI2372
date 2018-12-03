#include "rules.h"
#include "expertDisplay.h"
#include <iostream>

/**
 * Main method to act as a game engine
 */
int main(){

    //receiving game mode from user
    string userOrExpert;
    cout << "Do you want to play in (N)ormal mode or (E)xpert Rules mode? Enter 'N' or 'E': " <<endl;
    cin >> userOrExpert;
    std::transform(userOrExpert.begin(), userOrExpert.end(),userOrExpert.begin(), ::toupper);
    while ( !((userOrExpert.compare("E") == 0)||(userOrExpert.compare("N")) ==0 ) ){
        cout << "Invalid entry: 'E' or 'N' " << endl;
        cin >> userOrExpert;
        std::transform(userOrExpert.begin(), userOrExpert.end(),userOrExpert.begin(), ::toupper);
    }

    //receiving game display style
    string displayMode;
    cout << "Do you the display to be (N)ormal Display or (E)xpert Display? Enter 'N' or 'E': " <<endl;
    cin >> displayMode;
    std::transform(displayMode.begin(), displayMode.end(),displayMode.begin(), ::toupper);
    while ( !((displayMode.compare("E") == 0)||(displayMode.compare("N")) ==0 ) ){
        cout << "Invalid entry: 'E' or 'N' " << endl;
        cin >> displayMode;
        std::transform(displayMode.begin(), displayMode.end(),displayMode.begin(), ::toupper);
    }

    cout <<endl;
    Board *b;
    if (displayMode.compare("E") == 0){ //user wants to play on expert display mode
        b = new ExpertDisplay();
    } else {    //regular display mode
        b = new Board();
    }

    Game *g = new Game(*b);
    Rules r = Rules();
    Deck<Card>& cards = CardDeck::make_CardDeck();
    Deck<Reward>& rubies = RewardDeck::make_RewardDeck();

    vector<Player*> playersAdd;

    //getting player names, max of 4 players
    //creating and adding the players to the game
    cout << "Enter first players name " <<endl;
    string playerName;
    for (int i=0; i<4; ++i){
        cout << "Name: ";
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



    rubies.shuffle();

    while (!r.gameOver(*g)){
        b->reset(); //reset board
        cards.shuffle();
        
        cout << "\nRound " << g->getRound() <<endl <<endl;

        //resetting all players to active
        for (int i=0;i<playersAdd.size();++i){
            playersAdd[i]->setActive(true);
        }
        
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

                cout<<"Card reveal for player, " << p.getName() <<". Enter any key:\n";
                string s;
                cin >> s;  //pause to ensure other players do not see current players card reveal
                cout<< *g <<endl;
                b->reset(); //turns cards face down again
            }
            catch(...){ //player does not exist, throws exception
                
            }
        }

        //While the round isn't over the next active player takes their turn
        while (!r.roundOver(*g) ){

            //get next active player
            const Player &pnext = r.getNextPlayer(*g);


            string userCardSelection;
            cout << "Player, " << pnext.getName() <<" turn." <<endl;
            cout << "Select a card to turn over in this format: \"LetterNumber\", ex: \"A3\": ";
            cin >> userCardSelection;


            bool validEntry = false;
            //try user selection and only allow it if it's valid
            while (!validEntry){
                //ensuring correct length input
                while (userCardSelection.size() != 2){
                    cout << "The input much be of length 2 with form \"A3\". Re-enter: ";
                    cin >> userCardSelection;
                }

                try{
                    g->setCurrentCard(g->getCard(static_cast<Board::Letter>( (int)userCardSelection[0] -65 ) ,static_cast<Board::Number>( (int)userCardSelection[1] -49 ) ));
                    validEntry = true; //If exception not thrown then entry was valid
                }
                //exception thrown due to invalid entry
                catch(...){
                    cout << "Invalid entry: Ensure letter is from A-E and number is from 1-5. Re-enter:";
                    cin >> userCardSelection;
                }
            }

            //players flip was not valid so turn player inactive
            if (!r.isValid(*g) ){
                Player& pToSet = const_cast<Player&>(pnext);
                pToSet.setActive(false);
            }
            //displaying board after flip (but ensure flip was valid to update player activeness)
            cout << *g <<endl;

        }   //end round
        g->incrementRound();
        //giving the winner rubies reward
        for (Player* player: playersAdd){
            if ( player->isActive() )
                player->addReward( *(rubies.getNext()) );
        }

    } //end game
    //print each players rubies
    for (Player* player: playersAdd){
        player->setDisplayMode(true);
    }

    //print players based on largest amount of rubies to smallest
    vector<Player*> playersPrint = playersAdd;
    vector<Player*> playerPrintOrder;
    while (playersPrint.size() != 0){
        Player* playerRef = playersPrint[0];
        int indexOfHighest = 0;
        int currentIndex = 0;

        for (Player* p: playersPrint){
            if (p->getNRubies() > playerRef->getNRubies()){
                playerRef = p;
                indexOfHighest = currentIndex;
            }
            ++currentIndex;
        }
        playerPrintOrder.push_back(playerRef);
        playersPrint.erase(playersPrint.begin() + indexOfHighest);
    }

    for (Player* p: playerPrintOrder){
        cout << *p << endl;
    }
} //end main
