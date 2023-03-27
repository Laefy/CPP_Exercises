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
        const Image<RGB, 499, 499> base("../images/sonic.png");
        const Image<Luma, 499, 499> mask("../images/sonic_mask.png");
        const Image<RGBA, 499, 499> bg("../images/sonic_new_bg.png");
        const Image<RGBA, 499, 499> sum = bg + (base + mask);
        sum.save("images/sonic_stars.png");
    }

}
