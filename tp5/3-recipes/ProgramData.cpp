#include "ProgramData.hpp"

std::ostream& operator<<(std::ostream& stream, const Material& material)
{
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Recipe& recipe)
{
    return stream;
}

void ProgramData::add_material(std::string name)
{}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{}

void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;
    return result;
}