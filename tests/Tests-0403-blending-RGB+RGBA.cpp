#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <type_traits>

TEST_CASE("Blending (RGB + RGBA) => RGB")
{
    const RGB  a = RGB {5, 137, 54};
    const RGBA b = RGBA{105, 37, 150, 34};
    const RGB pix = a + b;

    const std::array<uint8_t, 4> raw = lib::mix_color(a.r, a.g, a.b, 255,
                                                      b.r, b.g, b.b, b.a);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    //   REQUIRE(truth.a == pix.a);
}

TEST_CASE("PHOTO COMPOSITING: RGB+RGBA")
{
    const auto base = lib::load<RGB, 540, 788>("../images/het_base.png");
    const auto effect = lib::load<RGB, 540, 788>("../images/het_rat.png");
    const auto sum = base + effect;
    lib::save(sum, "images/het.png");
}


