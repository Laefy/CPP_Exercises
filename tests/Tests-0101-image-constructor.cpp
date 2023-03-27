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
