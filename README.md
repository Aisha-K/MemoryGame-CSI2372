
Running the game:
- Compile then run
- It will run the main loop for the game

Debugging:

Class debug compile switches:
Class          |    Debug Command
-----------------------------------
Card                DEBUG_CARD
Reward              DEBUG_REWARD
Player              DEBUG_PLAYER
Board               DEBUG_BOARD
Game                DEBUG_GAME
CardDeck            DEBUG_CARDDECK
RewardDeck          DEBUG_REWARDDECK
Rules               DEBUG_RULES
ExpertDisplay       DEBUG_EXPERTDISPLAY
ExpertRules         DEBUG_EXPERTRULES

- to Debug run the game with a debug switch enabled via compile time debug define switches
- For ex: To run debug for Game use command g++ *.cpp -DDEBUG_GAME
    - Then run the compiled file and it will run the appropriate debugging for that class
