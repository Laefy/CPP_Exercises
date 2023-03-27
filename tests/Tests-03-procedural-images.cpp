#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <type_traits>
#include <complex>


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

    lib::save(img, "images/mandelbrot.png");

}
