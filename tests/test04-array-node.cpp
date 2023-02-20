#include "../src/ArrayNode.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("ArrayNode is a class that can be built from an integer.")
{
    ArrayNode p{};
}

TEST_CASE("ArrayNode derives from Node.")
{
    ArrayNode p{};
    Node &r = p;
}

TEST_CASE("The kind of ArrayNode is NodeKind::ARRAY.")
{
    ArrayNode p{};
    REQUIRE(p.kind() == NodeKind::ARRAY);
}

TEST_CASE("ArrayNode are arrays of nodes. By default it is empty, hence printed as an empty list.")
{
    ArrayNode p{};
    REQUIRE(p.print() == "[]");
}

TEST_CASE("ArrayNode::print() is dynamically linked.")
{
    ArrayNode p{};
    const Node &r = p;
    REQUIRE(r.print() == "[]");
}

#include "routine_memory_check.cpp"