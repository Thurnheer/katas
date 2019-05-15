#include "sml.hpp"
#include <string>
#include <tuple>

namespace tennis {


enum class score {
    love,
    fifteen,
    thirty
};

struct advantage {
    bool value;
};

struct forty {
};

class Player
{
public:
    Player(std::string name) : name_(name) {}

    friend bool operator==(const Player& lhs, const Player& rhs);
private:
    std::string name_;
};

bool operator==(const Player& lhs, const Player& rhs) {
    return 0 == lhs.name_.compare(rhs.name_);
}

using PlayerScores = std::tuple<Player, score, Player, score>;
// actions
const auto increment_score = [](const Player& p, PlayerScores& s) {
};

struct TennisImpl {
    auto operator()() const {
        using namespace boost::sml;
        return make_transition_table(
            * "normal_counting"_s + event<Player> / increment_score = "normal_counting"_s
            , "won"_s = boost::sml::X
        );
    }
};

class Tennis
{
private:
    boost::sml::sm<TennisImpl> tennis_statemachine;
public:
    Tennis(Player one, Player two) :
        tennis_statemachine(std::make_tuple(one, score{score::love},
                            two, score{score::love}
                            ))
    {}
    void scored(const Player& player){}
    std::string score_of(const Player& player){ return "--"; }
};

}

