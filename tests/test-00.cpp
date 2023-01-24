#include <catch2/catch_test_macros.hpp>

#include <string>

TEST_CASE("Test 00 - "
          "1. Une string instanciee par defaut a pour taille 0.")
{
    const auto default_string = std::string {};
    REQUIRE(default_string.length() == 0);
}

TEST_CASE("Test 00 - "
          "2. Deux string peuvent etre concatenees avec +.")
{
    const auto empty_string = std::string {};
    const auto str_a        = std::string { "toto" };
    const auto str_b        = std::string { "turlututu" };
    REQUIRE(empty_string + str_a == "toto");
    REQUIRE(str_b + empty_string == "turlututu");
    REQUIRE(str_a + str_b == "tototurlututu");
    REQUIRE(str_b + str_a == "turlutututoto");
}

TEST_CASE("Test 00 - "
          "3. Une string et un const char* peuvent etre concatenes avec +.")
{
    REQUIRE(std::string { "turlututu" } + "toto" == "turlutututoto");
    REQUIRE("toto" + std::string { "turlututu" } == "tototurlututu");
}

TEST_CASE("Test 00 - "
          "4. 0+0 = la tete a Toto.")
{
    const auto toto = 0;
    REQUIRE(0 + 0 == toto);
}

