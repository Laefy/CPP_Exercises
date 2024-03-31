#include "../lib/image_lib.hpp"
#include "image.hpp"
#include "pixels.hpp"

#include <filesystem>
#include <iostream>
#include <string>

void usage()
{
    std::cout << "Usage:\n"
              << "./blend path/to/images/folder" << std::endl;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        usage();
        return -1;
    }

    const auto input_path = std::filesystem::path { argv[1] };

    {
        const auto base   = image_lib::load<RGBA, 1012, 570>(input_path / "photo_base.png");
        const auto effect = image_lib::load<RGBA, 1012, 570>(input_path / "photo_dithering.png");
        const auto sum    = base + effect;
        image_lib::save(sum, "images/photo_base_and_dithering.png");
    }

    {
        const auto base   = image_lib::load<RGB, 540, 788>(input_path / "het_base.png");
        const auto effect = image_lib::load<RGBA, 540, 788>(input_path / "het_rat.png");
        const auto sum    = base + effect;
        image_lib::save(sum, "images/het_base_and_rat.png");
    }

    {
        const auto base   = image_lib::load<Luma, 499, 499>(input_path / "sonic_mask.png");
        const auto effect = image_lib::load<RGBA, 499, 499>(input_path / "sonic_new_bg.png");
        const auto sum    = base + effect;
        image_lib::save(sum, "images/sonic_mask_and_stars.png");
    }

    return 0;
}
