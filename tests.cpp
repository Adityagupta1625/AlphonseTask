#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "p34.h" // Include your solution class header
#include <bits/stdc++.h>


TEST_CASE("Anticlockwise Test Cases", "[Solution]")
{
    Solution sol;

    SECTION("Test Case 1")
    {

        REQUIRE(sol.solve("1 2 3 4 5 6 7") == "B R B R B B R");
    }

    SECTION("Test Case 2")
    {
        REQUIRE(sol.solve("") == "");
    }

    SECTION("Test Case 3"){
        REQUIRE(sol.solve("1")=="B");
    }

    SECTION("Test Case 4"){
        REQUIRE(sol.solve("1 2 N N 3 4")=="B R B R");
    }

    SECTION("Test Case 5"){
        REQUIRE(sol.solve("1 2 3 4 N 5 6")=="B R B R R B");
    }

    SECTION("Test Case 6"){
        REQUIRE(sol.solve("1 2 3 4 N N 6")=="B R B B R");
    }

    SECTION("Test Case 7"){
         REQUIRE(sol.solve("1 2 3 4 5 6 7 N 8 N 9 N N 10 11")=="B R B B R");
    }

    SECTION("Test Case 8"){
         REQUIRE(sol.solve("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31")=="B R B R B R B G R B G G R B G R B G G G R B G R B G G R B G R B B G G G R B G R B G G R B R R G B R B B R");
    }
}


