#include <catch2/catch.hpp>
#include "tennis.hpp"

TEST_CASE("Normal counting in tennis", "[counting]")
{
    using namespace tennis;

    Player federer("Federer");
    Player nadal("Nadal");
    Tennis tennis(federer, nadal);

    SECTION("First comes love") {
        REQUIRE("love" == tennis.score_of(federer));
        REQUIRE("love" == tennis.score_of(nadal));
    }

    tennis.scored(federer);

    SECTION("Then comes 15") {
        REQUIRE("15" == tennis.score_of(federer));
        REQUIRE("love" == tennis.score_of(nadal));
    }

    tennis.scored(federer);

    SECTION("Then comes 30") {
        REQUIRE("30" == tennis.score_of(federer));
        REQUIRE("love" == tennis.score_of(nadal));
    }

    tennis.scored(federer);

    SECTION("Then comes 40") {
        REQUIRE("40" == tennis.score_of(federer));
        REQUIRE("love" == tennis.score_of(nadal));
    }

    tennis.scored(federer);

    SECTION("Then comes won") {
        REQUIRE("won" == tennis.score_of(federer));
        REQUIRE("" == tennis.score_of(nadal));
    }
}

TEST_CASE("When the two players reach 40 it is called douce", "[deuce]")
{
    using namespace tennis;

    Player federer("Federer");
    Player nadal("Nadal");
    Tennis tennis(federer, nadal);
    tennis.scored(federer);
    tennis.scored(nadal);
    tennis.scored(federer);
    tennis.scored(nadal);
    tennis.scored(federer);
    tennis.scored(nadal);

    REQUIRE("deuce" == tennis.score_of(federer));
    REQUIRE("deuce" == tennis.score_of(nadal));

    tennis.scored(federer);

    SECTION("when a player then scores it is called advantage") {
        REQUIRE("advantage" == tennis.score_of(federer));
        REQUIRE("" == tennis.score_of(nadal));
    }

    tennis.scored(nadal);

    SECTION("when the other player scores it retournes to deuce") {
        REQUIRE("deuce" == tennis.score_of(federer));
        REQUIRE("deuce" == tennis.score_of(nadal));
    }
    
    tennis.scored(federer);
    tennis.scored(federer);

    SECTION("when a player with advantage scores he wins") {
        REQUIRE("won" == tennis.score_of(federer));
    }

}



