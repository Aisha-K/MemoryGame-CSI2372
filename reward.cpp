#include "reward.h"

 std::ostream& operator<<(std:: ostream& os, const Reward& reward){
    int rubyVal= reward;
    os << "Ruby Value: " << rubyVal;

}


