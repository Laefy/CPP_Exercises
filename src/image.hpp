#pragma once

#include <cstddef>

template<typename P, size_t W, size_t H>
struct Image
{
    std::array<std::array<P, H>, W> _pixels;
    
    Image(const P & base_pixel)
    {
        for (auto & col: _pixels)
        {
            for (auto & pix: col)
            {
                pix = base_pixel;
            }
        }
    }
    Image() = default;
    template<typename P2, size_t W2 = W, size_t H2 = H>
    Image(const Image<P2, W2, H2> & other)
    {
        for (auto & col: _pixels)
        {
            for (auto & pix: col)
            {
                pix = from<P, P2>(pix);
            }
        }
    }
    P &
    operator()(const size_t i, const size_t j)
    {
        return _pixels[i][j];
    }
    const P &
    operator()(const size_t i, const size_t j) const
    {
        return _pixels[i][j];
    }

    template<typename RHS>
    Image<P, W, H>
    operator+(const Image<RHS, W, H> & rhs)
    {
        Image<P, W, H> out{};
        for (uint32_t i = 0; i < W; ++i)
        {
            for (uint32_t j = 0; j < H; ++j)
            {
                out(i,j) = (*this)(i,j) + rhs(i,j);
            }
        }
        return out;
    }
    Image<P, W, H>(const auto & fonctor)
    {
        for (uint32_t i = 0; i < W; ++i)
        {
            for (uint32_t j = 0; j < H; ++j)
            {
                (*this)(i,j) = fonctor(i,j);
            }
        }
        
    }
    
    
};

