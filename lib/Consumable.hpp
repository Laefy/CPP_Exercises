#pragma once

#include "Ingredient.hpp"

#include <functional>
#include <optional>
#include <ostream>
#include <tuple>

// A consumable represents a quantity of an ingredient.
// It may expire in a certain amount of time.
// For example : 2 apples, or 150ml of milk.
struct Consumable
{
    // The ingredient.
    std::reference_wrapper<const Ingredient> ingredient;

    // The quantity left.
    float quantity = 0.f;

    // If the consumable has an expiration date, the amount of time before it gets expired.
    std::optional<unsigned int> expiration_time;
};

inline auto as_tuple(const Consumable& consumable)
{
    return std::tuple { &consumable.ingredient.get(), consumable.quantity, consumable.expiration_time };
}

// Whether two consumables are considered to be equal.
inline bool operator==(const Consumable& c1, const Consumable& c2)
{
    return as_tuple(c1) == as_tuple(c2);
}

// Output a textual representation of a Consumable.
inline std::ostream& operator<<(std::ostream& stream, const Consumable& consumable)
{
    const auto& unit         = consumable.ingredient.get().unit.get();
    const auto  is_countable = unit.name.empty();

    stream << consumable.quantity;

    if (is_countable)
    {
        stream << consumable.ingredient.get().name << (consumable.quantity > 1.f ? "s" : "");
    }
    else
    {
        stream << unit.name << " of " << consumable.ingredient.get().name;
    }

    if (consumable.expiration_time)
    {
        stream << " (exp: " << *consumable.expiration_time << ")";
    }

    return stream;
}

// Whether the consumable has been entirely consumed.
inline bool is_any_left(const Consumable& consumable)
{
    return consumable.quantity > 0.f;
}

// Whether the consumable is out-dated.
inline bool is_outdated(const Consumable& consumable)
{
    return consumable.expiration_time.value_or(1u) == 0u;
}

namespace std {

template <>
struct hash<Consumable>
{
    size_t operator()(const Consumable& c) const
    {
        return hash<const void*> {}(&c.ingredient.get()) ^ hash<float> {}(c.quantity) ^
               hash<optional<int>> {}(c.expiration_time);
    }
};

} // namespace std
