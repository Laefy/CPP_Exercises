#include "Material.hpp"
#include "ProgramData.hpp"
#include "Recipe.hpp"

#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void print_usage()
{
    std::cout << "Usage:" << std::endl;
    std::cout << "\tm <nom>                                 : Ajoute le materiau donne a l'inventaire"
              << std::endl;
    std::cout
        << "\tl                                       : Affiche les materiaux presents dans l'inventaire"
        << std::endl;
    std::cout << "\tr <m1> [<m2> ...] => <p1> [<p2> ...]    : Enregistre la recette donnee" << std::endl;
    std::cout << "\tt                                       : Affiche les recettes realisables avec "
                 "l'inventaire actuel"
              << std::endl;
    std::cout << "\tp <id>                                  : Tente de produire la recette demandee"
              << std::endl;
    std::cout << "\tq                                       : Ferme le programme" << std::endl;
}

std::deque<std::string> parse_words(const std::string& command)
{
    auto words = std::deque<std::string> {};

    auto str = std::stringstream { command };
    while (str.good())
    {
        str >> words.emplace_back();
    }

    return words;
}

std::string pop_next(std::deque<std::string>& words)
{
    if (words.empty())
    {
        return "";
    }
    else
    {
        auto next = std::move(words.front());
        words.pop_front();
        return next;
    }
}

bool is_valid_name(const std::string& name)
{
    return !name.empty() && std::all_of(name.begin(), name.end(), [](char c) { return std::isalnum(c); });
}

std::vector<std::string> consume_names(std::deque<std::string>& words)
{
    auto names = std::vector<std::string> {};

    while (!words.empty())
    {
        if (!is_valid_name(words.front()))
        {
            break;
        }

        names.emplace_back(pop_next(words));
    }

    return names;
}

int main()
{
    auto data             = ProgramData {};
    auto materials_buffer = std::vector<const Material*> {};
    auto recipes_buffer   = std::vector<const Recipe*> {};

    while (true)
    {
        std::cout << "Entrez une commande :" << std::endl;

        auto command = std::string {};
        while (command.empty())
        {
            std::getline(std::cin, command);
        }

        auto words = parse_words(command);
        if (words.empty())
        {
            print_usage();
            continue;
        }

        auto action = pop_next(words);
        if (action == "m")
        {
            auto name = pop_next(words);
            if (!is_valid_name(name))
            {
                std::cerr << "'" << name << "' is not a valid material name" << std::endl;
                print_usage();
                continue;
            }

            if (auto next = pop_next(words); next != "")
            {
                std::cerr << "Unexpected token '" << next << "' while parsing 'm' arguments" << std::endl;
                print_usage();
                continue;
            }

            data.add_material(std::move(name));
        }
        else if (action == "l")
        {
            if (auto next = pop_next(words); next != "")
            {
                std::cerr << "Unexpected token '" << next << "' while parsing 'l' arguments" << std::endl;
                print_usage();
                continue;
            }

            materials_buffer.clear();
            data.get_materials(materials_buffer);

            for (const auto* m : materials_buffer)
            {
                std::cout << *m << std::endl;
            }
        }
        else if (action == "r")
        {
            auto materials = consume_names(words);
            if (materials.empty())
            {
                std::cerr << "No materials have been given" << std::endl;
                print_usage();
                continue;
            }

            if (auto next = pop_next(words); next != "=>")
            {
                std::cerr << "Unexpected token '" << next << "' while parsing recipe formula" << std::endl;
                print_usage();
                continue;
            }

            auto products = consume_names(words);
            if (products.empty())
            {
                std::cerr << "No products have been given" << std::endl;
                print_usage();
                continue;
            }

            if (auto next = pop_next(words); next != "")
            {
                std::cerr << "Unexpected token '" << next << "' while parsing 'r' arguments" << std::endl;
                print_usage();
                continue;
            }

            data.register_recipe(std::move(materials), std::move(products));
        }
        else if (action == "t")
        {
            if (auto next = pop_next(words); next != "")
            {
                std::cerr << "Unexpected token '" << next << "' while parsing 't' arguments" << std::endl;
                print_usage();
                continue;
            }

            recipes_buffer.clear();
            data.collect_doable_recipes(recipes_buffer);

            for (const auto* r : recipes_buffer)
            {
                std::cout << *r << std::endl;
            }
        }
        else if (action == "p")
        {
            auto arg = pop_next(words);
            auto id  = std::atoi(arg.c_str());
            if (id <= 0)
            {
                std::cerr << "'" << arg << "' is not a valid identifier" << std::endl;
                print_usage();
                continue;
            }

            if (auto next = pop_next(words); next != "")
            {
                std::cerr << "Unexpected token '" << next << "' while parsing 't' arguments" << std::endl;
                print_usage();
                continue;
            }

            auto result = data.produce(id);
            if (result.recipe == nullptr)
            {
                std::cerr << "No recipe is identified with " << id << std::endl;
                continue;
            }

            if (!result.missing_materials.empty())
            {
                std::cerr << "Unable to produce '" << *result.recipe
                          << "' without the following materials :" << std::endl;
                for (const auto& m : result.missing_materials)
                {
                    std::cerr << m << std::endl;
                }
            }
        }
        else if (action == "q")
        {
            if (auto next = pop_next(words); next != "")
            {
                std::cerr << "Unexpected token '" << next << "' while parsing 'q' arguments" << std::endl;
                print_usage();
                continue;
            }

            break;
        }
        else
        {
            std::cerr << "Unknown command '" << action << "'" << std::endl;
            print_usage();
        }
    }
}
