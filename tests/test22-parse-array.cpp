#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("Parsing an empty ArrayNode  from file `array_empty.json`")
{
    std::string filename = json_dir + "array_empty.json";
    NodePtr node = JsonParser::parse_from_file(filename);
    REQUIRE(node->height() == 0u);
    REQUIRE(node->node_count() == 1u);
    REQUIRE(node->kind() == NodeKind::ARRAY);
}

TEST_CASE("Parsing a simple ArrayNode's from file `array_range10.json`")
{

    std::string filename = json_dir + "array_range10.json";
    NodePtr node = JsonParser::parse_from_file(filename);
    REQUIRE(node->height() == 1u);
    REQUIRE(node->node_count() == 11u);
    REQUIRE(node->kind() == NodeKind::ARRAY);
}

TEST_CASE("Parsing a complex ArrayNode's from file `array_hexadecimal.json`")
{
    std::string filename = json_dir + "array_hexadecimal.json";
    NodePtr node = JsonParser::parse_from_file(filename);
    REQUIRE(node->height() == 4u);
    REQUIRE(node->node_count() == 31u);
    REQUIRE(node->kind() == NodeKind::ARRAY);
}

#include "routine_memory_check.cpp"