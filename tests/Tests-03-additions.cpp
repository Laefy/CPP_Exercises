#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <type_traits>


TEST_CASE("Luma as transparency mask (RGB+Luma)")
{
    const RGBA pix = RGB{1,3,4} + Luma{120};
    REQUIRE(pix.r == 1);
    REQUIRE(pix.g == 3);
    REQUIRE(pix.b == 4);
    REQUIRE(pix.a == 120);
}
TEST_CASE("Luma as transparency mask (RGBA+Luma)")
{

    const RGBA pix = RGBA{1,3,4,200} + Luma{120};
    REQUIRE(pix.r == 1);
    REQUIRE(pix.g == 3);
    REQUIRE(pix.b == 4);
    REQUIRE(pix.a == (200*120)/255);
}
TEST_CASE("Luma as transparency mask (Luma+Luma)")
{
    const RGBA pix = Luma{100} + Luma{120};
    const RGB rgb = from<RGB, Luma>(Luma{100});
    REQUIRE(pix.r == rgb.r);
    REQUIRE(pix.g == rgb.g);
    REQUIRE(pix.b == rgb.b);
    REQUIRE(pix.a == 120);
}
