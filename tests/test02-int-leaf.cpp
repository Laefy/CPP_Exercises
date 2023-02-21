#include "../src/IntLeaf.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("IntLeaf is a class that can be built from an integer.")
{
    IntLeaf p{1};
}

TEST_CASE("IntLeaf derives from Leaf and from Node.")
{
    IntLeaf p{1};
    Leaf &l = p;
    Node &r = l;
}

TEST_CASE("IntLeaf are printed as numbers.")
{
    IntLeaf p{1};
    REQUIRE(p.print() == "1");
}

TEST_CASE("IntLeaf::data() gives the stored int.")
{
    IntLeaf p1{1};
    REQUIRE(p1.data() == 1);

    IntLeaf p2{42};
    REQUIRE(p2.data() == 42);
}

TEST_CASE("IntLeaf::print() is dynamically linked.")
{
    IntLeaf p{1};
    Node &r = p;
    REQUIRE(r.print() == "1");
}

#include "routine_memory_check.cpp"