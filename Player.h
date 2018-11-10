#include <string>
class Player{
    std::string name;
    std::string sideOfBoard;
    int numOfRubies;
    bool isActive;

    public:
    std::string getName() const;
    void setActive(bool);
    
}