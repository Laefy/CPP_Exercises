#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("Luma as transparency mask (RGB+Luma) => RGBA")
{
    const RGBA pix = RGB{1,3,4} + Luma{120};
    REQUIRE(pix.r == 1);
    REQUIRE(pix.g == 3);
    REQUIRE(pix.b == 4);
    REQUIRE(pix.a == 120);
}
