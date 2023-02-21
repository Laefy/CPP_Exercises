/* This files exists to check that the files compile. */
#include "../src/Node.hpp"
#include "../src/Leaf.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("There is an abstract class `Node` that inherits from `InstanceCounter.`")
{

    Node *node = nullptr;
    [[maybe_unused]] InstanceCounter *ic = node;

    // The next line tests that Node does not have a public
    // Node() constructor.
    REQUIRE(std::is_default_constructible<Node>::value == false);
}

TEST_CASE("There is an abstract class `Leaf` that inherits from `Node.`")
{

    Leaf *node = nullptr;
    [[maybe_unused]] Node *ic = node;

    // The next line tests that Leaf does not have a public
    // Leaf() constructor.
    REQUIRE(std::is_default_constructible<Leaf>::value == false);
}

#include "routine_memory_check.cpp"
