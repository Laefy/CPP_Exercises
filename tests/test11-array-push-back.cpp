#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>
#include <memory>

TEST_CASE("ArrayNode::child_count() gives the number of children of an ArrayNode")
{
    auto arraynode_ptr = ArrayNode::make_ptr();
    REQUIRE(arraynode_ptr->child_count() == 0);
}

TEST_CASE("ArrayNode::push_back() allows to push_back all kinds of Node's at the end of an ArrayNode")
{
    auto arraynode_ptr = ArrayNode::make_ptr();

    arraynode_ptr->push_back(ArrayNode::make_ptr());
    REQUIRE(arraynode_ptr->child_count() == 1);

    arraynode_ptr->push_back(StringLeaf::make_ptr("o"));
    REQUIRE(arraynode_ptr->child_count() == 2);

    arraynode_ptr->push_back(ObjectNode::make_ptr());
    REQUIRE(arraynode_ptr->child_count() == 3);

    arraynode_ptr->push_back(IntLeaf::make_ptr(3));
    REQUIRE(arraynode_ptr->child_count() == 4);

    REQUIRE(arraynode_ptr->print() == "[[],\"o\",{},3]");
}

#include "routine_memory_check.cpp"