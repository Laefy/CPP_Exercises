#pragma once

#include "../lib/Consumable.hpp"
#include "../lib/Cupboard.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Recipe.hpp"
#include "../lib/Unit.hpp"

#include <optional>
#include <random>
#include <set>
#include <string>

class Kitchen
{
public:
    const Unit& register_unit(Unit unit);
    const Unit* find_unit(const std::string& name) const;

    const Ingredient& register_ingredient(Ingredient ingredient);
    const Ingredient* find_ingredient(const std::string& name) const;

    std::optional<Consumable> make_random_consumable(float                       quantity,
                                                     std::optional<unsigned int> expiration_time);

    const Cupboard& get_cupboard() const { return _cupboard; }
    void            store_in_cupboard(Consumable consumable);

    float compute_quantity(const std::function<bool(const Consumable&)>& consumable_filter) const;
    float compute_quantity(const Ingredient& ingredient) const;

    void wait_time(unsigned int time);
    void tidy_up();

    void          register_recipe(Recipe recipe);
    const Recipe* find_recipe(const std::string& name) const;

    std::map<const Ingredient*, float> compute_missing_quantities(const Recipe& recipe) const;
    std::set<const Recipe*>            compute_feasible_recipes() const;

private:
    struct ElementNameComparer
    {
        using is_transparent = bool;

        bool compare_insensitive(const std::string& s1, const std::string& s2) const
        {
            return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                                [](char c1, char c2) { return tolower(c1) < tolower(c2); });
        }

        bool operator()(const Unit& u1, const Unit& u2) const { return u1.name < u2.name; }
        bool operator()(const Unit& unit, const std::string& name) const { return unit.name < name; }
        bool operator()(const std::string& name, const Unit& unit) const { return name < unit.name; }

        bool operator()(const Ingredient& i1, const Ingredient& i2) const
        {
            return compare_insensitive(i1.name, i2.name);
        }

        bool operator()(const Ingredient& ingredient, const std::string& name) const
        {
            return compare_insensitive(ingredient.name, name);
        }

        bool operator()(const std::string& name, const Ingredient& ingredient) const
        {
            return compare_insensitive(name, ingredient.name);
        }

        bool operator()(const Recipe& r1, const Recipe& r2) const { return r1.name < r2.name; }
        bool operator()(const Recipe& recipe, const std::string& name) const { return recipe.name < name; }
        bool operator()(const std::string& name, const Recipe& recipe) const { return name < recipe.name; }
    };

    std::random_device _rd;

    std::set<Unit, ElementNameComparer>       _units;
    std::set<Ingredient, ElementNameComparer> _ingredients;
    std::set<Recipe, ElementNameComparer>     _recipes;

    Cupboard _cupboard;
};
