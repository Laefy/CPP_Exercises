#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("Luma as transparency mask (Luma+Luma) => RGBA")
{
    const RGBA pix = Luma{100} + Luma{120};
    const RGB rgb = from<RGB, Luma>(Luma{100});
    REQUIRE(pix.r == rgb.r);
    REQUIRE(pix.g == rgb.g);
    REQUIRE(pix.b == rgb.b);
    REQUIRE(pix.a == 120);
}
