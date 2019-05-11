#include <catch2/catch.hpp>
#include "tennis.hpp"

TEST_CASE("Normal counting in tennis", "[counting]")
{
    Tennis tennis;
    Player federer("Federer");
    Player nadal("Nadal");

    SECTION("First comes love") {
        REQUIRE("Love" == tennis.score_of(federer));
        REQUIRE("Love" == tennis.score_of(nadal));
    }

    tennis.scored(federer);

    SECTION("Then comes 15") {
        REQUIRE("15" == tennis.score_of(federer));
        REQUIRE("Love" == tennis.score_of(nadal));
    }

    tennis.scored(federer);

    SECTION("Then comes 30") {
        REQUIRE("15" == tennis.score_of(federer));
        REQUIRE("Love" == tennis.score_of(nadal));
    }

    tennis.scored(federer);

    SECTION("Then comes 40") {
        REQUIRE("15" == tennis.score_of(federer));
        REQUIRE("Love" == tennis.score_of(nadal));
    }

    tennis.scored(federer);

    SECTION("Then comes won") {
        REQUIRE("won" == tennis.score_of(federer));
        REQUIRE("Love" == tennis.score_of(nadal));
    }
}

TEST_CASE("When the two players reach 40 it is called douce", "[deuce]")
{
    Tennis tennis;
    Player federer("Federer");
    Player nadal("Nadal");
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
        REQUIRE("advangtage" == tennis.score_of(federer));
        REQUIRE("" == tennis.score_of(nadal));
    }

    tennis.scored(federer);

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



