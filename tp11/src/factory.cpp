#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

// Liste des entitées à construire
std::string desc = R"(Object
Person
Dog
Cat
Tree
House
)";

class Entity
{
public:
    virtual void print() const = 0;
};

class Factory
{
public:
    // using Builder = ...;

    template <typename TDerivedEntity>
    void register_entity()
    {}

    std::unique_ptr<Entity> build(const std::string& id) const { return nullptr; }

private:
    // ...
};

class Object : public Entity
{
public:
    void print() const override { std::cout << "Object" << std::endl; }
};

class Tree : public Object
{
public:
    void print() const override { std::cout << "Tree" << std::endl; }
};

class Person : public Entity
{
public:
    explicit Person(std::string name)
        : _name { std::move(name) }
    {}

    void print() const override { std::cout << _name << std::endl; }

    void               set_name(std::string name) { _name = std::move(name); }
    const std::string& get_name() const { return _name; }

private:
    std::string _name;
};

class Animal : public Entity
{
public:
    explicit Animal(std::string species)
        : _species { std::move(species) }
    {}

    void print() const override { std::cout << _species << std::endl; }

private:
    std::string _species;
};

class House : public Object
{
public:
    explicit House(Person& owner)
        : _owner { owner }
    {}

    void print() const override { std::cout << "House owned by " << _owner.get_name() << std::endl; }

private:
    Person& _owner;
};

int main()
{
    Factory factory;
    // factory.register_entity<Object>("Object");

    std::vector<std::unique_ptr<Entity>> entities;

    std::stringstream s;
    s << desc;
    while (!s.eof())
    {
        std::string e;
        s >> e;

        entities.emplace_back(factory.build(e));
    }

    for (const auto& e : entities)
    {
        if (e != nullptr)
        {
            e->print();
        }
    }

    return 0;
}
