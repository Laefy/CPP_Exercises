#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

#include <iostream>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("Parsing the full pokedex !")
{
    std::unique_ptr<Node> node = JsonParser::parse_from_file(json_dir + "pokedex.json");
    REQUIRE(node->kind() == NodeKind::OBJECT);
    REQUIRE(node->height() == 5u);
    REQUIRE(node->node_count() == 3779u);
}

#include "routine_memory_check.cpp"