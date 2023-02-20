#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("Adding Chikorita to the pokedex")
{
    auto node = JsonParser::parse_from_file(json_dir + "pokedex.json");
    auto pokemon_node = node->as_ObjectNode()->at("pokemon")->as_ArrayNode();

    auto chikorita = ObjectNode::make_ptr();
    chikorita->insert("id", IntLeaf::make_ptr(152));
    chikorita->insert("name", StringLeaf::make_ptr("Chikorita"));
    chikorita->insert("num", StringLeaf::make_ptr("152"));
    chikorita->insert("type", ArrayNode::make_ptr());
    chikorita->at("type")->as_ArrayNode()->push_back(StringLeaf::make_ptr("Grass"));

    pokemon_node->push_back(std::move(chikorita));

    REQUIRE(pokemon_node->child_count() == 152u);
    REQUIRE(node->height() == 5u);
    REQUIRE(node->node_count() == 3779u + 6u);
}

#include "routine_memory_check.cpp"