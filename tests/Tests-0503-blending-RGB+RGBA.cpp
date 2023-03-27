#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <type_traits>

TEST_CASE("Blending (RGB + RGBA) => RGBA")
{
    const RGBA a = RGBA{105, 37, 150, 34};
    const RGB  b = RGB {5, 137, 54};
    const RGBA pix = a + b;

    const std::array<uint8_t, 4> raw = lib::mix_color(a.r, a.g, a.b, a.a,
                                                 b.r, b.g, b.b, 255);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == pix.a);
}

TEST_CASE("PHOTO COMPOSITING: RGB+RGBA")
{
    const Image<RGB, 540, 788> base("../images/het_base.png");
    const Image<RGBA, 540, 788> effect("../images/het_rat.png");
    const Image<RGB , 540, 788> sum = base + effect;
    sum.save("images/het.png");
}


