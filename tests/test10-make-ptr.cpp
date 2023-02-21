#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>

#include <utility>

TEST_CASE("IntLeaf::make_ptr()")
{
    std::unique_ptr<IntLeaf> node_ptr = IntLeaf::make_ptr(1);
    REQUIRE(node_ptr->print() == "1");
}

TEST_CASE("StringLeaf::make_ptr()")
{
    std::unique_ptr<StringLeaf> node_ptr = StringLeaf::make_ptr("Hello world");
    REQUIRE(node_ptr->print() == "\"Hello world\"");
}

TEST_CASE("ArrayNode::make_ptr()")
{
    std::unique_ptr<ArrayNode> node_ptr = ArrayNode::make_ptr();
    REQUIRE(node_ptr->print() == "[]");
}

TEST_CASE("ObjectNode::make_ptr()")
{
    std::unique_ptr<ObjectNode> node_ptr = ObjectNode::make_ptr();
    REQUIRE(node_ptr->print() == "{}");
}

TEST_CASE("Note that all these member-functions return something that can be stored in std::unique_ptr<Node>.")
{
    std::unique_ptr<Node> node_ptr1 = IntLeaf::make_ptr(1);
    REQUIRE(node_ptr1->print() == "1");

    std::unique_ptr<Node> node_ptr2 = StringLeaf::make_ptr("Hello world");
    REQUIRE(node_ptr2->print() == "\"Hello world\"");

    std::unique_ptr<Node> node_ptr3 = ArrayNode::make_ptr();
    REQUIRE(node_ptr3->print() == "[]");

    std::unique_ptr<Node> node_ptr4 = ObjectNode::make_ptr();
    REQUIRE(node_ptr4->print() == "{}");
}

#include "routine_memory_check.cpp"