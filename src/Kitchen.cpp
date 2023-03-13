#include "Kitchen.hpp"

#include <utility>

const Unit& Kitchen::register_unit(Unit unit)
{
    auto [it, emplaced] = _units.emplace(std::move(unit));
    return *it;
}

const Unit* Kitchen::find_unit(const std::string& name) const
{
    const auto it = _units.find(name);
    return it != _units.end() ? &(*it) : nullptr;
}

const Ingredient& Kitchen::register_ingredient(Ingredient ingredient)
{
    auto [it, emplaced] = _ingredients.emplace(std::move(ingredient));
    return *it;
}

const Ingredient* Kitchen::find_ingredient(const std::string& name) const
{
    const auto it = _ingredients.find(name);
    return it != _ingredients.end() ? &(*it) : nullptr;
}

std::optional<Consumable> Kitchen::make_random_consumable(float                       quantity,
                                                          std::optional<unsigned int> expiration_time)
{
    if (_ingredients.empty())
    {
        return std::nullopt;
    }

    auto        ingredient_position = std::uniform_int_distribution<size_t> { 0u, _ingredients.size() - 1u };
    const auto& ingredient          = *std::next(_ingredients.begin(), ingredient_position(_rd));

    return Consumable { ingredient, quantity, expiration_time };
}

void Kitchen::store_in_cupboard(Consumable consumable)
{
    _cupboard.consumables.emplace_back(std::move(consumable));
}

float Kitchen::compute_quantity(const std::function<bool(const Consumable&)>& consumable_filter) const
{
    const auto& consumables = _cupboard.consumables;
    return std::accumulate(consumables.begin(), consumables.end(), 0.f,
                           [&consumable_filter](float r, const Consumable& c)
                           {
                               const auto quantity = consumable_filter(c) ? c.quantity : 0.f;
                               return r + quantity;
                           });
}

float Kitchen::compute_quantity(const Ingredient& ingredient) const
{
    return compute_quantity([&ingredient](const Consumable& c)
                            { return c.expiration_time != 0 && &c.ingredient.get() == &ingredient; });
}

void Kitchen::wait_time(unsigned int time)
{
    for (auto& c : _cupboard.consumables)
    {
        if (auto& expiration = c.expiration_time)
        {
            expiration = *expiration - std::min(time, *expiration);
        }
    }
}

void Kitchen::tidy_up()
{
#if 1 // Optimized method
    const auto should_keep = [](const Consumable& c) { return is_any_left(c) && !is_outdated(c); };

    const auto try_merge = [](Consumable& r, const Consumable& c)
    {
        if (&r.ingredient.get() == &c.ingredient.get() && r.expiration_time == c.expiration_time)
        {
            r.quantity += c.quantity;
            return true;
        }

        return false;
    };

    const auto compare = [](const Consumable& c1, const Consumable& c2)
    {
        return std::tuple { &c1.ingredient.get(), c1.expiration_time } <
               std::tuple { &c2.ingredient.get(), c2.expiration_time };
    };

    auto& consumables = _cupboard.consumables;

    std::sort(consumables.begin(), consumables.end(), compare);

    consumables = std::accumulate(consumables.begin(), consumables.end(), std::vector<Consumable> {},
                                  [&should_keep, &try_merge](auto&& r, const Consumable& c)
                                  {
                                      if (should_keep(c))
                                      {
                                          if (r.empty() || !try_merge(r.back(), c))
                                          {
                                              r.emplace_back(c);
                                          }
                                      }

                                      return std::move(r);
                                  });

#else // Method that tries to reuse compute_quantity

    using Key = std::pair<const Ingredient*, std::optional<unsigned int>>;

    auto  quantity_by_ingredients = std::map<Key, float> {};
    auto& consumables             = _cupboard.consumables;

    const auto make_key = [](const Consumable& c) { return Key { &c.ingredient.get(), c.expiration_time }; };
    std::transform(consumables.begin(), consumables.end(), std::inserter(quantity_by_ingredients),
                   [this, &make_key](const Consumable& c)
                   {
                       const auto key    = make_key(c);
                       const auto filter = [&key, &make_key](const Consumable& o)
                       { return key == make_key(o); };
                       return { key, compute_quantity(filter) };
                   });

    consumables.clear();

    for (const auto& [key, quantity] : quantity_by_ingredients)
    {
        if (quantity != 0.f)
        {
            const auto& [ingredient, expiration_time] = key;
            consumables.emplace_back(Consumable { *ingredient, quantity, expiration_time });
        }
    }

#endif
}

void Kitchen::register_recipe(Recipe recipe)
{
    _recipes.emplace(std::move(recipe));
}

const Recipe* Kitchen::find_recipe(const std::string& name) const
{
    const auto it = _recipes.find(name);
    return it != _recipes.end() ? &(*it) : nullptr;
}

std::map<const Ingredient*, float> Kitchen::compute_missing_quantities(const Recipe& recipe) const
{
    auto result = std::map<const Ingredient*, float> {};

    std::transform(recipe.quantity_by_ingredient.begin(), recipe.quantity_by_ingredient.end(),
                   std::inserter(result, result.end()),
                   [this](const auto& item)
                   {
                       auto [ingredient, quantity] = item;
                       return std::pair { ingredient, quantity - compute_quantity(*ingredient) };
                   });

    for (auto it = result.begin(); it != result.end();)
    {
        const auto& [ingredient, quantity] = *it;
        it                                 = quantity <= 0.f ? result.erase(it) : std::next(it);
    }

    return result;
}

std::set<const Recipe*> Kitchen::compute_feasible_recipes() const
{
    auto tmp = std::vector<const Recipe*> {};
    std::transform(_recipes.begin(), _recipes.end(), std::back_inserter(tmp),
                   [](const Recipe& r) { return &r; });

    auto result = std::set<const Recipe*> {};
    std::copy_if(tmp.begin(), tmp.end(), std::inserter(result, result.end()),
                 [this](const Recipe* r) { return compute_missing_quantities(*r).empty(); });

    return result;
}
