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


/*
template<typename Pix>
RGBA
to_rgba(const Pix & pix);

template<typename Pix>
Pix
from_rgba(const RGBA & pix);


template<>
RGBA
to_rgba(const )

*/



template<typename A, typename B>
A from(const B & stuff);

template<>
RGBA
from(const RGBA & stuff)
{
    return stuff;
}

template<typename A, typename B>
B into(const A & stuff)
{
    return from<B,A>(stuff);
}

template<>
RGB from<RGB, RGBA>(const RGBA & pix)
{
    return {pix.r, pix.g, pix.b};
}
template<>
RGBA from<RGBA, RGB>(const RGB & pix)
{
    return {pix.r, pix.g, pix.b, 255};
}
template<>
Luma from<Luma, RGBA>(const RGBA & pix)
{
    return {rgb_to_grayscale(pix.r, pix.g, pix.b)};
}
template<>
RGBA from<RGBA, Luma>(const Luma & pix)
{
    const auto [r,g,b] = grayscale_to_rgb(pix.gray);
    return {r,g,b, 255};
}



template<typename A, typename B>
A from(const B & stuff)
{
    RGBA rgba = from<RGBA, B>(stuff);
    return from<A, RGBA>(rgba);
}





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

// blending
template<typename Pix>
RGBA
operator+(const Pix & pix,
          const RGBA & rhs)
{
    RGBA rgba = from<RGBA, Pix>(pix);
    const auto & [r,g,b,a] = mix_color(rhs.r, rhs.g, rhs.b, rhs.a,
                                       rgba.r, rgba.g, rgba.b, rgba.a);

    return {r,g,b,a};
}

// blending
template<typename Pix>
RGBA
operator+(const Pix & pix,
          const RGB & rhs)
{
    RGBA rgba = from<RGBA, Pix>(pix);
    const auto & [r,g,b,a] = mix_color(rhs.r, rhs.g, rhs.b, 255,
                                       rgba.r, rgba.g, rgba.b, rgba.a);

    return {r,g,b,a};
}

