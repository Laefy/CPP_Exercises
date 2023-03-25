#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <type_traits>
#include <complex>

// TEST_CASE("We can construct an Image with a std::function foo so that foo(i,j) returns the pixel at coordinates (i,j)")
// {
//     const size_t WIDTH = 32;
//     const size_t HEIGHT = 16;
    
//     const std::function<char(const size_t, const size_t)> foo = []
//         (const size_t i, const size_t j)
//     {
//         return 97+ (i+j*j)%16;
//     };
//     const auto img = Image<char, WIDTH, HEIGHT>(foo);

    
//     for (size_t j = 0; j < HEIGHT; ++j)
//     {
//         for (size_t i = 0; i < WIDTH; ++i)
//         {
//             REQUIRE(img(i,j) == foo(i,j));
//             std::cout << img(i,j) << " ";
//         }
//         std::cout << std::endl;
//     }
    
// }

TEST_CASE("Look we can already do pretty neat things, look at images/mandelbrot.png")
{
    const size_t WIDTH = 1000;
    const size_t HEIGHT = 1000;
   
    const auto fun = [&](const size_t i, const size_t j)
    {
        const double res = 2.0/std::min(WIDTH, HEIGHT);
        const double x = (double(i) - double(WIDTH)/2.0)*res;
        const double y = (double(j) -double(HEIGHT)/2.0)*res;
        const std::complex c = {x,y};
        std::complex z = 0.;
        uint32_t k = 0;
        
        for (; std::norm(z) < 2.0 && k < 100; ++k)
        {
            z = z*z + c;
        }
        const double norm = std::norm(z);
        if (norm < 2.0)
        {
            return uint8_t(0);
        }
        else
        {
            const double val = std::sqrt(double(k))*20.;

            return uint8_t(val);
        }
    };
    
    const Image<uint8_t, WIDTH, HEIGHT> img(fun);

    img.save("images/mandelbrot.png");

}
