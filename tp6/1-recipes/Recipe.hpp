#pragma once

#include <ostream>

class Recipe
{
    // Affiche l'identifiant et la formule d'une recette.
    friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe) { return stream; }
};
