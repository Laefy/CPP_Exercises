#include "../src/pixels.hpp"
#include "../src/image.hpp"
#include "../lib/lib.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("Luma as transparency mask (RGBA+Luma) => RGBA")
{

    const RGBA pix = RGBA{1,3,4,200} + Luma{120};
    REQUIRE(pix.r == 1);
    REQUIRE(pix.g == 3);
    REQUIRE(pix.b == 4);
    REQUIRE(pix.a == (200*120)/255);
}


TEST_CASE("PHOTO COMPOSITING: RGB + (RGBA + LUMA)")
{
    {
        const auto base = lib::load<RGB, 499, 499>("../images/sonic.png");
        const auto mask = lib::load<RGB, 499, 499>("../images/sonic_mask.png");
        const auto bg   = lib::load<RGB, 499, 499>("../images/sonic_new_bg.png");
        const auto sum = bg + (base + mask);
        lib::save(sum, "images/sonic_stars.png");
    }

}
