#ifndef CARD_H_
    enum FaceAnimal {crab, penguin, octopus, turtle, walrus};
    enum FaceBackground {red, green, purple, blue, yellow};

class Card{

    FaceAnimal face;
    FaceBackground colour;
    int getNRows();
    private:
        Card(FaceAnimal face, FaceBackground colour);
        Card& operator=(const Card& card);
        Card(const Card& card);
};

#endif