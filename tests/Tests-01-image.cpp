#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <type_traits>
#include <complex>

TEST_CASE("Image is a template class that can be constructed from a default pixel")
{
    const Image<char, 1, 1> img(6);
}
TEST_CASE("Default constructor")
{
    // a complicated struct but that still
    // have a default constructor Foo()
    // Foo lol = {}; is valid
    struct Foo
    {
        std::string s;
        std::array<std::vector<uint32_t>, 64> stuff;
    };
    const Image<char, 1, 1> img{};
    const Image<Foo, 1, 1> img2{};
}


/* un peu trop ?
TEST_CASE("The type of integer used for the image size is unsigned")
{
    const Image<char, -1, 1> img(0);
    
}
*/

TEST_CASE("Image pixel access with image(i,j)")
{
    Image<int, 4, 4> img(0);
    img(1,2) = 2;
    img(2,1) = 5;
    
    REQUIRE(img(1,2) == 2);
    REQUIRE(img(2,1) == 5);
}

TEST_CASE("Same thing but const")
{
    const Image<int, 4, 4> img(3);
    
    REQUIRE(img(1,2) == 3);
    REQUIRE(img(2,1) == 3);
}


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

