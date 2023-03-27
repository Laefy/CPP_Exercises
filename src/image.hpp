#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>


template<typename P, size_t W, size_t H>
struct Image
{
private:
    std::array<std::array<P, W>, H> _data;
public:
    Image(const P & pix)
    {
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                _data[j][i] = pix;
            }
        }
    }

    Image() = default;

    const P &
    operator()(const size_t i,
               const size_t j) const
    {
        return _data[j][i];
    }
    P &
    operator()(const size_t i,
               const size_t j)
    {
        return _data[j][i];
    }

    Image(const std::function<P(const size_t, const size_t)> & functor)
    {
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                (*this)(i,j) = functor(i,j);
            }
        }        
    }


};



template<typename A, typename B, size_t W, size_t H>
Image<A, W, H>
operator+(const Image<A,W,H> & lhs,
          const Image<B,W,H> & rhs)
{
    Image<A, W, H> out = {};
    for (size_t j = 0; j < H; ++j)
    {
        for (size_t i = 0; i < W; ++i)
        {
            out(i,j) = lhs(i,j) + rhs(i,j);
        }
    }
    return out;
}





template<typename A, size_t W, size_t H>
Image<RGBA, W, H>
operator+(const Image<A,W,H> & lhs,
          const Image<Luma,W,H> & rhs)
{
    Image<RGBA, W, H> out = {};
    for (size_t j = 0; j < H; ++j)
    {
        for (size_t i = 0; i < W; ++i)
        {
            out(i,j) = lhs(i,j) + rhs(i,j);
        }
    }
    return out;
}
