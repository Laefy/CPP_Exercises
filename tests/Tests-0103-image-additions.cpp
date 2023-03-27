#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <type_traits>
#include <complex>

TEST_CASE("Operator + on images")
{
    Image<int, 2, 2> img_a;
    Image<int, 2, 2> img_b;
    img_a(0,0) = 1; img_a(1,0) = 2;
    img_a(0,1) = 3; img_a(1,1) = 4;
    img_b(0,0) = 5; img_b(1,0) = 6;
    img_b(0,1) = 7; img_b(1,1) = 8;
    const Image<int, 2, 2> img_add = img_a + img_b;
    
    REQUIRE(img_add(0,0) == 6);
    REQUIRE(img_add(1,0) == 8);
    REQUIRE(img_add(0,1) == 10);
    REQUIRE(img_add(1,1) == 12);
}

