/* This files exists to check that the files compile. */
#include "../src/Node.hpp"
#include "../src/Leaf.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("There is an abstract class `Node` that inherits from `InstanceCounter.`")
{

    Node *node = nullptr;
    [[maybe_unused]] InstanceCounter *ic = node;

    // This tests that Node is an abstract class.
    // REQUIRE(std::is_abstract<Node>::value);
}

TEST_CASE("There is an abstract class `Leaf` that inherits from `Node.`")
{

    Leaf *node = nullptr;
    [[maybe_unused]] Node *ic = node;

    // This tests that Leaf is an abstract class.
    // REQUIRE(std::is_abstract<Leaf>::value);
}

#include "routine_memory_check.cpp"
