#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>


struct RGBA
{
    uint8_t r,g,b,a;
};
struct RGB
{
    uint8_t r,g,b;
};
struct Luma
{
    uint8_t gray;
};

template<typename A, typename B>
A from(const B & x);

template<> RGBA from(const RGBA & x){ return x; }
template<> RGB  from(const RGB  & x){ return x; }
template<> Luma from(const Luma & x){ return x; }

    
template<>
RGBA from(const RGB & x)
{
    return {x.r,x.g,x.b,255};
}

template<>
RGB from(const RGBA & x)
{
    return {x.r,x.g,x.b};
}

template<>
RGB from(const Luma & x)
{
    const auto [r,g,b] = lib::grayscale_to_rgb(x.gray);
    return {r,g,b};
}

template<>
Luma from(const RGB & x)
{
    return {lib::rgb_to_grayscale(x.r,x.g,x.b)};
}

template<>
RGBA from(const Luma & x)
{
    return from<RGBA, RGB>(from<RGB, Luma>(x));
}
template<>
Luma from(const RGBA & x)
{
    return from<Luma, RGB>(from<RGB, RGBA>(x));
}


RGBA
operator+(const RGBA & lhs,
          const RGBA & rhs)
{
    const auto [r,g,b,a] = lib::mix_color(
        lhs.r, lhs.g, lhs.b, lhs.a,
        rhs.r, rhs.g, rhs.b, rhs.a
        );
    return {r,g,b,a};
}

#define IMPL_BLEND(A,B,C)                       \
C operator+(const A & lhs, const B & rhs)       \
{                                               \
    return from<C, RGBA>(from<RGBA, A>(lhs)     \
                         + from<RGBA, B>(rhs)); \
}

IMPL_BLEND(RGBA, RGB , RGBA);
IMPL_BLEND(RGB , RGBA, RGB );
IMPL_BLEND(Luma, RGBA, RGBA);
IMPL_BLEND(Luma, RGB , RGB);
IMPL_BLEND(RGB , RGB , RGB);


// mask operator
template<typename Pix>
RGBA
operator+(const Pix & pix,
          const Luma & mask)
{
    RGBA rgba = from<RGBA, Pix>(pix);
    rgba.a = uint8_t((uint32_t(rgba.a)*uint32_t(mask.gray)/255));
    return rgba;
}
