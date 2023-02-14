#pragma once

#include "Card.hpp"

#include <string>
#include <string_view>
#include <utility>

enum class TrapType
{
    Normal,
    Continuous,
    Counter,
};

std::string_view to_string(const TrapType type)
{
    switch (type)
    {
    case TrapType::Normal:
        return "Normal";

    case TrapType::Continuous:
        return "Continuous";

    case TrapType::Counter:
        return "Counter";
    }

    return "";
}

class Trap: public Card
{
public:
    Trap(std::string id, std::string name, TrapType trap_type)
    : Card { std::move(id), CardType::Trap }
    , _trap_type { trap_type }
    {
        set_name(std::move(name));
        _symbol = u8"罠";
    }

    TrapType get_trap_type() const { return _trap_type; }

private:
    TrapType _trap_type = {};
};
