#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("Node::height() gives the height of the tree.")
{
    auto truenode_ptr = IntLeaf::make_ptr(1);
    REQUIRE(truenode_ptr->height() == 0u);

    auto falsenode_ptr = IntLeaf::make_ptr(0);
    auto arraynode_ptr = ArrayNode::make_ptr();
    arraynode_ptr->push_back(std::move(truenode_ptr));
    arraynode_ptr->push_back(std::move(falsenode_ptr));
    REQUIRE(arraynode_ptr->height() == 1u);

    auto stringnode_ptr = StringLeaf::make_ptr("Hello world");
    REQUIRE(stringnode_ptr->height() == 0u);

    auto intnode_ptr = IntLeaf::make_ptr(1);
    REQUIRE(intnode_ptr->height() == 0u);

    auto objectnode_ptr = ObjectNode::make_ptr();
    objectnode_ptr->insert("array", std::move(arraynode_ptr));
    objectnode_ptr->insert("string", std::move(stringnode_ptr));
    objectnode_ptr->insert("int", std::move(intnode_ptr));
    REQUIRE(objectnode_ptr->height() == 2u);
}

TEST_CASE("Node::node_count() gives the number of Node's in the tree.")
{
    auto truenode_ptr = IntLeaf::make_ptr(1);
    REQUIRE(truenode_ptr->node_count() == 1u);

    auto falsenode_ptr = IntLeaf::make_ptr(0);
    auto arraynode_ptr = ArrayNode::make_ptr();
    arraynode_ptr->push_back(std::move(truenode_ptr));
    arraynode_ptr->push_back(std::move(falsenode_ptr));
    REQUIRE(arraynode_ptr->node_count() == 3u);

    auto stringnode_ptr = StringLeaf::make_ptr("Hello world");
    REQUIRE(stringnode_ptr->node_count() == 1u);

    auto intnode_ptr = IntLeaf::make_ptr(1);
    REQUIRE(intnode_ptr->node_count() == 1u);

    auto objectnode_ptr = ObjectNode::make_ptr();
    objectnode_ptr->insert("array", std::move(arraynode_ptr));
    objectnode_ptr->insert("string", std::move(stringnode_ptr));
    objectnode_ptr->insert("int", std::move(intnode_ptr));
    REQUIRE(objectnode_ptr->node_count() == 6u);
}

#include "routine_memory_check.cpp"