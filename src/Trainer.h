#pragma once

#include "PC.h"
#include "Pokeball.h"
#include "Pokedex.h"

#include <array>
#include <memory>
#include <string>
#include <utility>

// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string& name, PC& pc)
    : _name { name }
    , _pc { pc }
    {}

    const std::string& name() const
    {
        return _name;
    }

    const std::array<Pokeball, 6>& pokeballs() const
    {
        return _pokeballs;
    }

    void capture(PokemonPtr pokemon)
    {
        pokemon->set_trainer(*this);
        _pokedex.add(*pokemon);

        for (auto& pokeball: _pokeballs)
        {
            if (pokeball.empty())
            {
                pokeball.store(std::move(pokemon));
                return;
            }
        }

        _pc.transfer(std::move(pokemon));
    }

    void store_in_pc(size_t index)
    {
        _pc.transfer(_pokeballs[index].steal());
    }

    void fetch_from_pc(const std::string& name)
    {
        for (auto& pokeball: _pokeballs)
        {
            if (pokeball.empty())
            {
                auto pokemon = _pc.steal(*this, name);
                if (pokemon != nullptr)
                {
                    pokeball.store(std::move(pokemon));
                }

                return;
            }
        }
    }

    const Pokedex& pokedex() const
    {
        return _pokedex;
    }

private:
    std::string _name;
    PC&         _pc;
    Pokedex     _pokedex;

    std::array<Pokeball, 6> _pokeballs;
};
