#include "../src/pixels.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("The channels of the pixels are encoded on one byte")
{
    REQUIRE(sizeof(RGBA) == 4);
    REQUIRE(sizeof(RGB ) == 3);
    REQUIRE(sizeof(Luma) == 1);
}

