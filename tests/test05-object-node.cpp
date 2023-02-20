#include "../src/ObjectNode.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Same basic tests for ObjectNode.")
{
    ObjectNode p{};
    REQUIRE(p.kind() == NodeKind::OBJECT);
    REQUIRE(p.print() == "{}");

    Node &r = p;
    REQUIRE(r.print() == "{}");
}

#include "routine_memory_check.cpp"