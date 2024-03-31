#include "../lib/image_lib.hpp"
#include "image.hpp"
#include "pixels.hpp"

#include <filesystem>
#include <iostream>
#include <string>

void usage()
{
    std::cout << "Usage:\n"
              << "./transparency_mask path/to/images/folder" << std::endl;
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
        const auto base = image_lib::load<RGBA, 499, 499>(input_path / "sonic.png");
        const auto mask = image_lib::load<Luma, 499, 499>(input_path / "sonic_mask.png");
        const auto bg   = image_lib::load<RGBA, 499, 499>(input_path / "sonic_new_bg.png");
        const auto sum  = bg + (base + mask);
        image_lib::save(sum, "images/sonic_stars.png");
    }

    {
        const auto cat  = image_lib::load<RGB, 500, 500>(input_path / "mojus-500.png");
        const auto mask = image_lib::load<Luma, 500, 500>(input_path / "mojus-backrooms-alpha.png");
        const auto grad = image_lib::load<RGBA, 500, 500>(input_path / "mojus-backroom-grad.png");
        const auto back = image_lib::load<Luma, 500, 500>(input_path / "mojus-backrooms.png");
        const auto sum  = back + (cat + mask) + grad;
        image_lib::save(sum, "images/cute_cat.png");
    }

    return 0;
}
