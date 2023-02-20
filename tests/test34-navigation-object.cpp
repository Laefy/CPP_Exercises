#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("One may test the existence of a key child in an ObjectNode with ObjectNode::has_child")
{
    auto node_ptr = JsonParser::parse_from_file(json_dir + "pokedex.json");
    auto objectnode_ptr = node_ptr->as_ObjectNode();
    REQUIRE(objectnode_ptr->has_child("pokemon") == true);
    REQUIRE(objectnode_ptr->has_child("digimon") == false);
}

TEST_CASE("One may advance to the child associated with a key in an Object Node with ObjectNode::at")
{
    auto node_ptr = JsonParser::parse_from_file(json_dir + "pokedex.json");
    auto objectnode_ptr = node_ptr->as_ObjectNode();
    auto pokemons_ptr = objectnode_ptr->at("pokemon");
    REQUIRE(pokemons_ptr != nullptr);
    REQUIRE(pokemons_ptr != objectnode_ptr);
    REQUIRE(pokemons_ptr->kind() == NodeKind::ARRAY);

    // This check that pokemon_node is not const
    pokemons_ptr->as_ArrayNode()->push_back(IntLeaf::make_ptr(42));
}

TEST_CASE("If there is no child with given key ObjectNode::at returns a null pointer")
{
    auto node_ptr = JsonParser::parse_from_file(json_dir + "pokedex.json");
    auto objectnode_ptr = node_ptr->as_ObjectNode();
    REQUIRE(objectnode_ptr->at("digimon") == nullptr);
}

#include "routine_memory_check.cpp"