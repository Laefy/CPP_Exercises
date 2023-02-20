#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("There is a member-function Node::as_StringLeaf")
{
    NodePtr node = StringLeaf::make_ptr("Hello world");
    auto bnode = node->as_StringLeaf();
    const std::string &data = bnode->data();
    REQUIRE(data == "Hello world");
}

TEST_CASE("Node::as_StringLeaf returns a nullptr if Node is not a StringLeaf")
{
    NodePtr node1 = IntLeaf::make_ptr(42);
    REQUIRE(node1->as_StringLeaf() == nullptr);

    NodePtr node2 = ArrayNode::make_ptr();
    REQUIRE(node2->as_StringLeaf() == nullptr);

    NodePtr node3 = ObjectNode::make_ptr();
    REQUIRE(node3->as_StringLeaf() == nullptr);
}

#include "routine_memory_check.cpp"
