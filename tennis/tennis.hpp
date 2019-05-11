#include "sml.hpp"
#include <string>

class Player
{
public:
    Player(std::string name) : name_(name) {}

private:
    std::string name_;
};

class Tennis
{
public:
    void scored(const Player& player){}
    std::string score_of(const Player& player){ return "40"; }
};

