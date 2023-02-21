#include "../src/ArrayNode.hpp"
#include "../src/Node.hpp"
#include "../src/NodeKind.hpp"
#include "../src/IntLeaf.hpp"
#include "../src/ObjectNode.hpp"
#include "../src/StringLeaf.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("ObjectNode is a map.")
{
    auto object_ptr = ObjectNode::make_ptr();
    size_t size = object_ptr->child_count();
    REQUIRE(size == 0u);

    object_ptr->insert("key1", IntLeaf::make_ptr(42));
    object_ptr->insert("key1", IntLeaf::make_ptr(43));
    object_ptr->insert("key2", StringLeaf::make_ptr("Hello World!"));
    object_ptr->insert("key2", ArrayNode::make_ptr());
    object_ptr->insert("key2", StringLeaf::make_ptr("World, hello!"));

    REQUIRE(object_ptr->child_count() == 2u);
}

#include "routine_memory_check.cpp"