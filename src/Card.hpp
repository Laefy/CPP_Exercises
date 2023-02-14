#pragma once

#include <string>
#include <string_view>
#include <utility>

enum class CardType
{
    Monster,
    Spell,
    Trap,
};

inline std::string_view to_string(const CardType type)
{
    switch (type)
    {
    case CardType::Monster:
        return "Monster";

    case CardType::Spell:
        return "Spell";

    case CardType::Trap:
        return "Trap";
    }

    return "";
}

class Card
{
public:
    explicit Card(std::string id, CardType type)
    : _id { std::move(id) }
    , _type { type }
    {}

    const std::string& get_id() const { return _id; }
    CardType get_type() const { return _type; }

    const std::string& get_name() const { return _name; }
    void set_name(std::string name) { _name = std::move(name); }

    std::string get_description() const { return _description; }
    void set_description(std::string description) { _description = std::move(description); }

    const std::string& get_symbol() const { return _symbol; }

protected:
    std::string _symbol;

private:
    std::string _id;
    CardType _type;
    std::string _name;
    std::string _description;
};
