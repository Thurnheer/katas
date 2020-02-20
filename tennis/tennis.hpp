#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsubobject-linkage"
#include "sml.hpp"
#pragma GCC diagnostic pop
#include <string>
#include <tuple>

namespace tennis {

enum class score {
    love,
    fifteen,
    thirty
};

score operator++(score& toIncrement, int)
{
    switch(toIncrement) {
        case score::love:
            return toIncrement = score::fifteen;
        case score::fifteen:
            return toIncrement = score::thirty;
        default:
            return toIncrement;
    }
}

std::string toString(const score& s) {
    switch(s) {
        case score::love:
            return "love";
        case score::fifteen:
            return "15";
        case score::thirty:
            return "30";
        default:
            return "";
    }
}

class Player
{
public:
    Player(std::string name) : name_(name) {}

    friend bool operator==(const Player& lhs, const Player& rhs);
    friend bool operator!=(const Player& lhs, const Player& rhs);
private:
    std::string name_;
};

bool operator==(const Player& lhs, const Player& rhs) {
    return 0 == lhs.name_.compare(rhs.name_);
}

bool operator!=(const Player& lhs, const Player& rhs) {
    return !(lhs == rhs);
}

struct advantage {
    Player adv;
};

struct Thirtycounting {
    Player player_has_forty;
    score otherPlayerScore;
};

struct PlayerScores {
    Player one_;
    score scorePlayerOne_;
    Player two_;
    score scorePlayerTwo_;
};

// actions
const auto increment_score = [](const Player& p, PlayerScores& s) {
    if(p == s.one_) {
        s.scorePlayerOne_++;
    }
    else {
        s.scorePlayerTwo_++;
    }
};

const auto initForty = [](const Player& p, PlayerScores& s, Thirtycounting& t) {
    t.player_has_forty = p;
    t.otherPlayerScore = p == s.one_ ? s.scorePlayerTwo_ : s.scorePlayerOne_;
};

const auto playerWon = [](const Player& p, Player& winner) {
    winner = p;
};

const auto initAdvantage = [](const Player& p, advantage& a) {
    a.adv = p;
};

// guards
const auto hasThirty = [](const Player& p, PlayerScores& s) {
    if(p == s.one_ && s.scorePlayerOne_ == score::thirty) {
        return true;
    }
    else if(p == s.two_ && s.scorePlayerTwo_ == score::thirty) {
        return true;
    }
    else {
        return false;
    }
};

const auto isLeading = [](const Player& p, Thirtycounting& count){
    if(p == count.player_has_forty) {
        return true;
    }
    else {
        return false;
    }
};

const auto otherReachesForty = [](const Player& p, Thirtycounting& count){
    if(p == count.player_has_forty) {
        return false;
    }
    else if(count.otherPlayerScore == score::thirty) {
        return true;
    }
    else {
        return false;
    }
};

const auto hasAdvantage = [](const Player& p, advantage& a) {
    return p == a.adv;
};

struct TennisImpl {
    auto operator()() const {
        using namespace boost::sml;
        return make_transition_table(
            * "normal_counting"_s + event<Player> [!hasThirty] / increment_score = "normal_counting"_s
            , "normal_counting"_s + event<Player> [hasThirty] = "forty_counting"_s
            , "forty_counting"_s + on_entry<_> / initForty
            , "forty_counting"_s + event<Player> [isLeading] = "won"_s
            , "forty_counting"_s + event<Player> [otherReachesForty] = "deuce"_s
            , "deuce"_s + event<Player> = "advantage"_s
            , "advantage"_s + on_entry<_> / initAdvantage
            , "advantage"_s + event<Player> [hasAdvantage] = "won"_s
            , "advantage"_s + event<Player> [!hasAdvantage] = "deuce"_s
            , "won"_s + on_entry<_> / playerWon
            , "won"_s = boost::sml::X
        );
    }
};

class Tennis
{
private:
    PlayerScores ps_;
    Thirtycounting tc_;
    advantage playerWithAdvantage;
    Player winner_;
    boost::sml::sm<TennisImpl> tennis_statemachine;
public:
    Tennis(Player one, Player two)
    : ps_{one, score{score::love}, two, score{score::love}}
    , tc_{Player(""), score::love}
    , playerWithAdvantage{ Player("") }
    , winner_("")
    , tennis_statemachine(ps_, tc_, winner_, playerWithAdvantage)
    {}
    void scored(const Player& player){ tennis_statemachine.process_event(player); }
    std::string score_of(const Player& player){
        using namespace boost::sml;
        if(winner_ != std::string("")) {
            return  player == winner_ ? "won" : "";
        }
        else if (tennis_statemachine.is("advantage"_s)) {
            return playerWithAdvantage.adv == player ? "advantage" : "";
        }
        else if (tennis_statemachine.is("deuce"_s)) {
            return "deuce";
        }
        else if(tc_.player_has_forty != std::string("")) {
            if(tc_.player_has_forty == player) {
                return "40";
            }
            else {
                return toString(tc_.otherPlayerScore);
            }
        }
        else if(player == ps_.one_) {
            return toString(ps_.scorePlayerOne_);
        }
        else {
            return toString(ps_.scorePlayerTwo_);
        }
    }
};

}

