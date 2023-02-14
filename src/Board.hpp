#pragma once

#include "Monster.hpp"
#include "Spell.hpp"
#include "Trap.hpp"

#include <memory>
#include <variant>
#include <vector>

class Board
{
public:
    using CardPtr = std::variant<std::unique_ptr<Monster>, std::unique_ptr<Spell>, std::unique_ptr<Trap>>;

    bool put(CardPtr card)
    {
        return std::visit([this](auto&& c)
        {
            if (c == nullptr)
            {
                return false;
            }

            auto& cards_count = get_cards_count(c->get_type());
            if (cards_count >= 5)
            {
                return false;
            }

            _cards.push_back(std::move(c));
            ++cards_count;

            return true;
        }, card);
    }

private:
    int& get_cards_count(CardType type)
    {
        switch (type)
        {
        case CardType::Monster:
            return _monsters_count;

        case CardType::Spell:
        case CardType::Trap:
            return _spells_or_traps_count;
        }

        return _monsters_count;
    }

    std::vector<CardPtr> _cards;
    int _monsters_count = 0;
    int _spells_or_traps_count = 0;
};
