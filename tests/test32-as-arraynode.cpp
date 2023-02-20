#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>

/* Json files are in directory `json` in the root directory of the TP. */
std::string json_dir = "../json/";

TEST_CASE("There is a member-function Node::as_ArrayNode")
{
    NodePtr node = ArrayNode::make_ptr();
    auto bnode = node->as_ArrayNode();
    REQUIRE(bnode->child_count() == 0);
}

TEST_CASE("Node::as_ArrayNode returns a nullptr if Node is not an ArrayNode")
{
    NodePtr node2 = IntLeaf::make_ptr(42);
    REQUIRE(node2->as_ArrayNode() == nullptr);

    NodePtr node3 = StringLeaf::make_ptr("Hello world");
    REQUIRE(node3->as_IntLeaf() == nullptr);

    NodePtr node4 = ObjectNode::make_ptr();
    REQUIRE(node4->as_ArrayNode() == nullptr);
}

#include "routine_memory_check.cpp"
