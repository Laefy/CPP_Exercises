#pragma once

#include <array>
#include <cstdlib>
#include <functional>

template<typename P1, typename P2>
using CombinedPixel = decltype(std::declval<P1>() + std::declval<P2>());

template <typename P, size_t W, size_t H>
class Image
{
public:
    Image() = default;

    Image(const P& pixel)
    {
        for (auto& line : _pixels)
        {
            for (auto& p : line)
            {
                p = pixel;
            }
        }
    }

    Image(const std::function<P(size_t i, size_t j)>& functor)
    {
        for (auto h = size_t { 0 }; h < H; ++h)
        {
            for (auto w = size_t { 0 }; w < W; ++w)
            {
                (*this)(w, h) = functor(w, h);
            }
        }
    }

    const P& operator()(size_t i, size_t j) const { return _pixels[j][i]; }
    P&       operator()(size_t i, size_t j) { return _pixels[j][i]; }

    template <typename POther>
    Image<CombinedPixel<P, POther>, W, H> operator+(const Image<POther, W, H>& other) const
    {
        auto result = Image<CombinedPixel<P, POther>, W, H> {};

        for (auto h = size_t { 0 }; h < H; ++h)
        {
            for (auto w = size_t { 0 }; w < W; ++w)
            {
                result(w, h) = (*this)(w, h) + other(w, h);
            }
        }

        return result;
    }

private:
    std::array<std::array<P, W>, H> _pixels;
};