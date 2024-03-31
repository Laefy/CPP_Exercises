#include "../lib/image_lib.hpp"
#include "image.hpp"

#include <algorithm>
#include <complex>
#include <cstdint>

constexpr auto width  = 1000;
constexpr auto height = 1000;

uint8_t mandelbrot(size_t i, size_t j)
{
    const double       res = 2.0 / std::min(width, height);
    const double       x   = (double(i) - double(width) / 2.0) * res;
    const double       y   = (double(j) - double(height) / 2.0) * res;
    const std::complex c   = { x, y };
    std::complex       z   = 0.;
    uint32_t           k   = 0;

    for (; std::norm(z) < 2.0 && k < 100; ++k)
    {
        z = z * z + c;
    }
    const double norm = std::norm(z);
    if (norm < 2.0)
    {
        return uint8_t(0);
    }
    else
    {
        const double val = std::sqrt(double(k)) * 20.;

        return uint8_t(val);
    }
}

int main()
{
    // const auto image = ...;
    // image_lib::save(image, "images/mandelbrot.png");

    return 0;
}
