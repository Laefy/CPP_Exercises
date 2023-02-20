#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("Parsing an IntLeaf from file `number_42.json`")
{
    std::string filename = json_dir + "number_42.json";
    NodePtr node = JsonParser::parse_from_file(filename);
    REQUIRE(node->height() == 0u);
    REQUIRE(node->node_count() == 1u);
    REQUIRE(node->kind() == NodeKind::INT);
}

TEST_CASE("Parsing a StringLeaf from file `string_hello.json`")
{
    std::string filename = json_dir + "string_hello.json";
    NodePtr node = JsonParser::parse_from_file(filename);
    REQUIRE(node->height() == 0u);
    REQUIRE(node->node_count() == 1u);
    REQUIRE(node->kind() == NodeKind::STRING);
}

#include "routine_memory_check.cpp"