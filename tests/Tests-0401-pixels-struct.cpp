#include "../src/pixels.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("The 3 pixels structure RGBA RGB Luma are implemented")
{
    const RGBA rgba = {250, 105, 50, 255};
    const RGB rgb = {250, 105, 50};
    const Luma luma = {204};
    REQUIRE(rgba.r == 250);
    REQUIRE(rgba.g == 105);
    REQUIRE(rgba.b == 50);
    REQUIRE(rgba.a == 255);
    REQUIRE(rgb.r == 250);
    REQUIRE(rgb.g == 105);
    REQUIRE(rgb.b == 50);
    REQUIRE(luma.gray == 204);
}
