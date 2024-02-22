#include "ProgramData.hpp"

#include <iostream>
#include <map>

void ProgramData::add_material(std::string name)
{
    _materials.push_back(std::make_unique<Material>(std::move(name)));
}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{
    for (const auto& m : _materials)
    {
        if (m != nullptr)
        {
            materials.push_back(m.get());
        }
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{
    const auto& recipe =
        _recipes.emplace_back(_recipes.size() + 1, std::move(materials), std::move(products));

    std::cout << "Recipe '" << recipe << "' has been registered." << std::endl;
}

void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{
    for (const auto& r : _recipes)
    {
        if (can_produce(r, nullptr))
        {
            recipes.push_back(&r);
        }
    }
}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;

    if (recipe_id > _recipes.size())
    {
        return result;
    }

    result.recipe = &_recipes[recipe_id - 1];

    if (!can_produce(*result.recipe, &result.missing_materials))
    {
        return result;
    }

    for (const auto& m : result.recipe->get_materials())
    {
        // _materials[find_material(m)] = nullptr;

        // Bonus D3
        size_t count = 1;
        auto   idx   = find_material(m, count);
        std::swap(_materials[idx], _materials.back());
        _materials.pop_back();
    }

    for (const auto& p : result.recipe->get_products())
    {
        add_material(p);
    }

    return result;
}

size_t ProgramData::find_material(const std::string& name, size_t& nb_required) const
{
    for (size_t idx = 0; idx < _materials.size(); ++idx)
    {
        const auto& material = _materials[idx];

        if (material != nullptr && name == _materials[idx]->get_name() && --nb_required == 0)
        {
            return idx;
        }
    }

    return SIZE_MAX;
}

bool ProgramData::can_produce(const Recipe& recipe, std::vector<std::string>* missing_materials) const
{
    // const auto& required = recipe.get_materials();
    // for (const auto& r : required)
    // {
    //     if (find_material(r) == SIZE_MAX)
    //     {
    //         if (missing_materials == nullptr)
    //         {
    //             return false;
    //         }

    //         missing_materials->push_back(r);
    //     }
    // }

    // Bonus C3
    auto required = std::map<std::string, size_t> {};
    for (const auto& r : recipe.get_materials())
    {
        ++required[r.c_str()];
    }

    for (auto& r : required)
    {
        if (find_material(r.first, r.second) == SIZE_MAX)
        {
            if (missing_materials == nullptr)
            {
                return false;
            }

            while (r.second-- != 0)
            {
                missing_materials->push_back(r.first);
            }
        }
    }

    return missing_materials != nullptr ? missing_materials->empty() : true;
}
