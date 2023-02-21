#include "../src/StringLeaf.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Stringleaf is a class that can be built from an std::string.")
{
    StringLeaf p{"Hello World"};
}

TEST_CASE("Stringleaf derives from Leaf and from Node.")
{
    StringLeaf p{"Hello World"};
    Leaf &l = p;
    Node &r = l;
}

TEST_CASE("The kind of Stringleaf is NodeKind::STRING.")
{
    StringLeaf p{"Hello World"};
    REQUIRE(p.kind() == NodeKind::STRING);
}

TEST_CASE("Stringleaf are printed between \" \".")
{
    StringLeaf p{"Hello World"};
    REQUIRE(p.print() == "\"Hello World\"");
}

TEST_CASE("Stringleaf::data() gives the stored std::string.")
{
    StringLeaf p1{"Hello"};
    REQUIRE(p1.data() == "Hello");

    StringLeaf p2{"World"};
    REQUIRE(p2.data() == "World");
}

TEST_CASE("Stringleaf::print() is dynamically linked.")
{
    StringLeaf p{"Hello World"};
    Node &r = p;
    REQUIRE(r.print() == "\"Hello World\"");
}

#include "routine_memory_check.cpp"