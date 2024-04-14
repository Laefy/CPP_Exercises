#include "../src/HybridArray.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("There is a class-template named HybridArray")
{
    // The template arguments are:
    // 1. the type of values stored by the container
    // 2. the size under which the container uses static storage
    HybridArray<int, 1> ctn;
}
