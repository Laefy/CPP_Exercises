#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <type_traits>


TEST_CASE("Blending (RGBA + RGBA) => RGBA")
{
    const RGBA a = RGBA{105, 37, 150, 34};
    const RGBA b = RGBA{5, 137, 54, 100};
    const RGBA pix = a + b;

    const std::array<uint8_t, 4> raw = lib::mix_color(a.r, a.g, a.b, a.a,
                                                 b.r, b.g, b.b, b.a);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == pix.a);
}

TEST_CASE("PHOTO COMPOSITING: RGBA+RGBA")
{
    const auto base   = lib::load<RGBA,1012,570>("../images/photo_base.png");
    const auto effect = lib::load<RGBA,1012,570>("../images/photo_dithering.png");
    const auto sum = base + effect;
    lib::save(sum, "images/compositing.png");
    
}
