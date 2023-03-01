#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("ObjectNode::child_count() gives the number of children of an ArrayNode")
{
    auto objectnode_ptr = ObjectNode::make_ptr();
    size_t size = objectnode_ptr->child_count();
    REQUIRE(size == 0u);
}

TEST_CASE("ObjectNode::insert() allows to insert a new element in the dictionary.")
{
    auto objectnode_ptr = ObjectNode::make_ptr();
    size_t size = objectnode_ptr->child_count();

    objectnode_ptr->insert("H", IntLeaf::make_ptr(3110));
    REQUIRE(objectnode_ptr->child_count() == 1u);

    auto arraynode_ptr = ArrayNode::make_ptr();
    arraynode_ptr->push_back(IntLeaf::make_ptr(0));
    arraynode_ptr->push_back(StringLeaf::make_ptr("rld!"));
    arraynode_ptr->push_back(ArrayNode::make_ptr());
    arraynode_ptr->push_back(ObjectNode::make_ptr());
    objectnode_ptr->insert("W", std::move(arraynode_ptr));

    REQUIRE(objectnode_ptr->child_count() == 2u);

    // This is a raw literal, go check it out https://en.cppreference.com/w/cpp/language/string_literal */
    std::string target = R"---({"H":3110,"W":[0,"rld!",[],{}]})---";
    //                   ^^^^^^                               ^^^^^
    // The parts marked with ^ above are not part of the string;

    REQUIRE(objectnode_ptr->print() == target);
    // NB: in `target` above, keys are sorted in increasing order, not in insertion order!
}

#include "routine_memory_check.cpp"