#ifndef CARD_H_
#define CARD_H_

class Card{
    enum FaceAnimal {crab, penguin, octopus, turtle, walrus};
    enum FaceBackground {red, green, purple, blue, yellow};

    FaceAnimal face;
    FaceBackground colour;
    int getNRows();
    private:
        Card(FaceAnimal face, FaceBackground colour);
        Card& operator=(const Card& card);
        Card(const Card& card);
};

#endif
