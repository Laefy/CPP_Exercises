#pragma once

#include "Pokemon.h"

#include <map>
#include <string>
#include <vector>

class Pokedex
{
public:
    void add(const Pokemon& pokemon)
    {
        _pokemons_by_name[pokemon.name()].push_back(&pokemon);
    }

    const std::vector<const Pokemon*>& find(const std::string& name) const
    {
        const auto it = _pokemons_by_name.find(name); 
        return it == _pokemons_by_name.end() ? empty_list : it->second;
    }

private:
    static inline std::vector<const Pokemon*> empty_list;

    std::map<std::string, std::vector<const Pokemon*>> _pokemons_by_name;
};
