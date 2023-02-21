#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("Testing quality operator with file `number_42.json`")
{
    std::string filename = json_dir + "number_42.json";
    std::unique_ptr<Node> node = JsonParser::parse_from_file(filename);
    REQUIRE(*node == *IntLeaf::make_ptr(42));
}

TEST_CASE("Testing quality operator with file `string_hello.json` ")
{
    std::string filename = json_dir + "string_hello.json";
    std::unique_ptr<Node> node = JsonParser::parse_from_file(filename);
    REQUIRE(*node == *StringLeaf::make_ptr("Hello"));
}

TEST_CASE("Testing quality operator with file `object_alphabet.json")
{
    std::string filename = json_dir + "object_alphabet.json";
    std::unique_ptr<Node> node = JsonParser::parse_from_file(filename);

    auto target = ObjectNode::make_ptr();
    for (char c = 'a'; c <= 'z'; c++)
        target->insert(std::string(1, c), IntLeaf::make_ptr(c));

    REQUIRE(*node == *target);
}

TEST_CASE("Testing quality operator with file `array_range10.json`")
{
    std::string filename = json_dir + "array_range10.json";
    std::unique_ptr<Node> node = JsonParser::parse_from_file(filename);

    auto target = ArrayNode::make_ptr();
    for (unsigned i = 0; i < 10; i++)
        target->push_back(IntLeaf::make_ptr(i));

    REQUIRE(*node == *target);
}

TEST_CASE("Testing quality operator with file `pokedex.json`")
{
    std::string filename = json_dir + "pokedex.json";
    std::unique_ptr<Node> node = JsonParser::parse_from_file(filename);
    REQUIRE(*node == *node);
}

#include "routine_memory_check.cpp"
