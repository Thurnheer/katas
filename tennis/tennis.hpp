#include "sml.hpp"
#include <string>

namespace tennis {

class Player
{
public:
    Player(std::string name) : name_(name) {}

private:
    std::string name_;
};

class Tennis
{
private:
    Player one_;
    Player two_;
public:
    Tennis(Player one, Player two) : one_(one), two_(two) {}
    void scored(const Player& player){}
    std::string score_of(const Player& player){ return "--"; }
};

}

