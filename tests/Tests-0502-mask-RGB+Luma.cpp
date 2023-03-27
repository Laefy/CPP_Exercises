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

TEST_CASE("PHOTO COMPOSITING: Un gentil petit chat")
{
    const auto cat  = lib::load<RGB ,500,500>("../images/mojus-500.png");
    
    const auto mask = lib::load<Luma, 500,500>("../images/mojus-backrooms-alpha.png");
    const auto grad = lib::load<RGBA ,500,500>("../images/mojus-backroom-grad.png");
    const auto back = lib::load<Luma , 500,500>("../images/mojus-backrooms.png");
    const auto sum = back + (cat+mask) + grad;
    
    lib::save(sum, "images/cute_cat.png");
    
    
}


