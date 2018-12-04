#include "reward.h"

//cout<< operator override
 std::ostream& operator<<(std:: ostream& os, const Reward& reward){
    int rubyVal= reward;
    os << "Ruby Value: " << rubyVal;
    return os;
}


//UNIT TESTING
#ifdef DEBUG_REWARD
#include <iostream>
int main(){
    Reward r(2);
    int rInt= r;
    std::cout<<"Testing cout of int conversion: "<< rInt;

}

#endif


