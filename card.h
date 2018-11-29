#ifndef CARD_H_
#define CARD_H_
#include <string>
using namespace std;

class Card{
    friend class CardDeck;

    enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
    enum FaceBackground {Red, Green, Purple, Blue, Yellow};
    string FaceAnimalString[5] = {"C","P","O","T","W"};
    string FaceBackgroundString[5] = {"r","g","p","b","y"};
    int numRows;

    FaceAnimal face;
    FaceBackground colour;
    private:
        Card(FaceAnimal face, FaceBackground colour, int rows=3);
        Card& operator=(const Card& card);
        Card(const Card& card);
        int getNRows() const;

    public:
        string operator() (int i) const;
        //For conversion of such FaceAnimal A = c;      where c is a Card object
        operator FaceAnimal() const{return face;}
        operator FaceBackground() const{return colour;}
};

#endif
