#pragma once

#include <ostream>

class Material
{
    // Affiche le nom d'un materiau.
    friend std::ostream& operator<<(std::ostream& stream, const Material& material) { return stream; }
};
