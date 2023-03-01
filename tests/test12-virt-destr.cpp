#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>
#include <memory>

TEST_CASE("ArrayNode::push_back() allows to push_back all kinds of Node's at the end of an ArrayNode")
{
    auto arraynode_ptr = ArrayNode::make_ptr();
    arraynode_ptr->push_back(ArrayNode::make_ptr());
    arraynode_ptr->push_back(StringLeaf::make_ptr("o"));
    arraynode_ptr->push_back(ObjectNode::make_ptr());
    arraynode_ptr->push_back(IntLeaf::make_ptr(3));

    std::unique_ptr<Node> node_ptr = std::move(arraynode_ptr);
    // From now on, `arraynode_ptr` is empty since it was moved to `node_ptr`

    REQUIRE(node_ptr->print() == "[[],\"o\",{},3]");
}

// If the routine memory check fails in this test, and not in the previous test,
// it means that the correct destructor is not called when `node_ptr` is destroyed.
#include "routine_memory_check.cpp"