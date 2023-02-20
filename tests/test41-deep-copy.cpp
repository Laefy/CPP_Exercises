#include "../src/Node.hpp"
#include "../src/JsonParser.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("Node::deep_copy() makes a deep copy of a Node.")
{
    NodePtr original_ptr = JsonParser::parse_from_file(json_dir + "pokedex.json");
    // We make the copy multiple times to ensure that deallocation works
    for (unsigned i = 0; i < 100; ++i)
    {
        NodePtr copy_ptr = original_ptr->deep_copy();
        REQUIRE(copy_ptr->height() == 5u);
        REQUIRE(copy_ptr->node_count() == 3779u);
        REQUIRE(copy_ptr->kind() == NodeKind::OBJECT);

        REQUIRE(*original_ptr == *copy_ptr);

        REQUIRE(&*original_ptr != &*copy_ptr);
    }

    // We browse the original tree to check that it was not deallocated.
    REQUIRE(original_ptr->height() == 5u);
    REQUIRE(original_ptr->node_count() == 3779u);
}

#include "routine_memory_check.cpp"