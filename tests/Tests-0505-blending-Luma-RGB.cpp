#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Blending (Luma + RGB) => RGB")
{
    const Luma a = Luma{109};
    const RGB  b = RGB {105, 37, 150};
    const RGB  pix = a + b;
    
    const RGB  c = from<RGB, Luma>(a);
    const std::array<uint8_t, 4> raw = lib::mix_color(c.r, c.g, c.b, 255,
                                                 b.r, b.g, b.b, 255);
    const RGBA truth = reinterpret_cast<const RGBA &>(raw);
    REQUIRE(truth.r == pix.r);
    REQUIRE(truth.g == pix.g);
    REQUIRE(truth.b == pix.b);
    REQUIRE(truth.a == 255);
    
}
