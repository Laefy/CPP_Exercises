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

    Image(const std::function<P(const size_t, const size_t)> & foo)
    {
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                (*this)(i,j) = foo(i,j);
            }
        }        
    }

    Image<P, W, H>(const std::string & path)
{
    int w, h, c;
    const uint8_t * data = stbi_load(path.c_str(),
                                     &w, &h, &c, 0);
    if(data == NULL)
    {
        std::cout << "Could not find image '" << path << "'" << std::endl;
        exit(1);
    }
    else if (w!=W || h != H || c != sizeof(P))
    {
        std::cout << "Could not open image '"
                  << path << "' with the dimensions ("
                  << W <<"," << H << ","
                  << sizeof(P)<<"), found ("
                  << w <<","<<h<<","<< c  << ")" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < W; ++i)
        {
            for (size_t j = 0; j < H; ++j)
            {
                const uint8_t * pixel_ptr = data + ((j%h)*w + (i%w))*c;
                (*this)(i,j) = *reinterpret_cast<const P *>(pixel_ptr);
            }
        }
    }
}

void
save(const std::string & path) const
{
    const auto data = reinterpret_cast<const uint8_t *>(this);
    stbi_write_png(path.c_str(), W, H, sizeof(P), data, W*sizeof(P));
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
