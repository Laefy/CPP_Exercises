#pragma once

#include "Card.hpp"

#include <string>
#include <string_view>
#include <utility>

enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field,
};

std::string_view to_string(const SpellType type)
{
    switch (type)
    {
    case SpellType::Normal:
        return "Normal";

    case SpellType::Equip:
        return "Equip";

    case SpellType::Continuous:
        return "Continuous";

    case SpellType::QuickPlay:
        return "Quick-Play";

    case SpellType::Field:
        return "Field";
    }

    return "";
}

class Spell: public Card
{
public:
    Spell(std::string id, std::string name, SpellType spell_type)
    : Card { std::move(id), CardType::Spell }
    , _spell_type { spell_type }
    {
        set_name(std::move(name));
        _symbol = u8"魔";
    }

    SpellType get_spell_type() const { return _spell_type; }

private:
    SpellType _spell_type = {};
};
