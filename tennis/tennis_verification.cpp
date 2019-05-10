#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "tennis.hpp"

TEST_CASE("When the two players reach 40 it is called douce", "[deuce]")
{
    Tennis tennis;
    tennis.player_one_scored();
    tennis.player_two_scored();
    tennis.player_one_scored();
    tennis.player_two_scored();
    tennis.player_one_scored();
    tennis.player_two_scored();

    REQUIRE("deuce" == tennis.player_one_score());
    REQUIRE("deuce" == tennis.player_two_score());
}


