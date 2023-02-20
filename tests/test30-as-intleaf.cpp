#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("There is a member-function Node::as_IntLeaf")
{
    NodePtr node = IntLeaf::make_ptr(42);
    auto bnode = node->as_IntLeaf();
    int data = bnode->data();
    REQUIRE(data == 42);
}

TEST_CASE("Node::as_IntLeaf returns a nullptr if Node is not a IntLeaf")
{

    NodePtr node2 = StringLeaf::make_ptr("Hello world");
    REQUIRE(node2->as_IntLeaf() == nullptr);

    NodePtr node3 = ArrayNode::make_ptr();
    REQUIRE(node3->as_IntLeaf() == nullptr);

    NodePtr node4 = ObjectNode::make_ptr();
    REQUIRE(node4->as_IntLeaf() == nullptr);
}

#include "routine_memory_check.cpp"
