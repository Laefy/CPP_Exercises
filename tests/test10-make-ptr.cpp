#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>

#include <utility>

// This function will compile if there exists a type `NodePtr` that points to a `Node`
void some_function(NodePtr ptr)
{
    [[maybe_unused]] Node &v = *ptr;
}

TEST_CASE("IntLeaf::make_ptr()")
{
    NodePtr node_ptr = IntLeaf::make_ptr(1);
    REQUIRE(node_ptr->print() == "1");
}

TEST_CASE("StringLeaf::make_ptr()")
{
    NodePtr node_ptr = StringLeaf::make_ptr("Hello world");
    REQUIRE(node_ptr->print() == "\"Hello world\"");
}

TEST_CASE("ArrayNode::make_ptr()")
{
    NodePtr node_ptr = ArrayNode::make_ptr();
    REQUIRE(node_ptr->print() == "[]");
}

TEST_CASE("ObjectNode::make_ptr()")
{
    NodePtr node_ptr = ObjectNode::make_ptr();
    REQUIRE(node_ptr->print() == "{}");
}

#include "routine_memory_check.cpp"