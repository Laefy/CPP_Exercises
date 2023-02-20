#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

#include <iostream>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("Parsing an empty ObjectNode  from file `object_empty.json`")
{
    NodePtr node_ptr = JsonParser::parse_from_file(json_dir + "object_empty.json");
    REQUIRE(node_ptr->kind() == NodeKind::OBJECT);
    REQUIRE(node_ptr->height() == 0u);
    REQUIRE(node_ptr->node_count() == 1u);
}

TEST_CASE("Parsing a simple ObjectNode from file `object_alphabet.json`")
{
    NodePtr node_ptr = JsonParser::parse_from_file(json_dir + "object_alphabet.json");
    REQUIRE(node_ptr->kind() == NodeKind::OBJECT);
    REQUIRE(node_ptr->height() == 1u);
    REQUIRE(node_ptr->node_count() == 27u);
}

TEST_CASE("Parsing a complex ObjectNode from file `cpp2023.json`")
{
    NodePtr node_ptr = JsonParser::parse_from_file(json_dir + "cpp2023.json");
    REQUIRE(node_ptr->kind() == NodeKind::OBJECT);
    REQUIRE(node_ptr->height() == 4u);
    REQUIRE(node_ptr->node_count() == 30u);
}

#include "routine_memory_check.cpp"