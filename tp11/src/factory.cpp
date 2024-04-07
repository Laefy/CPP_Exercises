#include <functional>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

std::string desc = R"(Person
Dog
Cat
Object
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
    using Builder = std::function<std::unique_ptr<Entity>()>;

    template <typename TEntity, typename... TArgs>
    void register_entity(const std::string& id, TArgs&&... args)
    {
        _builders.emplace(id, [&args...]() -> std::unique_ptr<Entity>
        {
            return std::make_unique<TEntity>(std::forward<TArgs>(args)...);
        });
    }

    std::unique_ptr<Entity> build(const std::string& id) const
    {
        auto it = _builders.find(id);
        if (it != _builders.end())
        {
            return it->second();
        }

        return nullptr;
    }

private:
    std::map<std::string, Builder> _builders;
};

class Person : public Entity
{
public:
    explicit Person(std::string name)
    : _name { std::move(name) }
    {}

    void print() const override
    {
        std::cout << _name << std::endl;
    }
    
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

    void print() const override
    {
        std::cout << _species << std::endl;
    }

private:
    std::string _species;
};

class Object: public Entity
{
public:
    void print() const override
    {
        std::cout << "Object" << std::endl;
    }
};

class Tree: public Object
{
public:
    void print() const override
    {
        std::cout << "Tree" << std::endl;
    }
};

class House: public Object
{
public:
    explicit House(Person& owner)
    : _owner { owner }
    {}

    void print() const override
    {
        std::cout << "House owned by " << _owner.get_name() << std::endl;
    }

private:
    Person& _owner;
};

int main()
{
    Factory factory;

    factory.register_entity<Person>("Person", "Paul");
    factory.register_entity<Object>("Object");
    factory.register_entity<Tree>("Tree");
    factory.register_entity<Animal>("Dog", std::string { "Dog" });
    factory.register_entity<Animal>("Cat", std::string { "Cat" });

    Person jean { "Jean" };
    factory.register_entity<House>("House", std::ref(jean));

    std::vector<std::unique_ptr<Entity>> entities;

    std::stringstream s;
    s << desc;
    while (!s.eof())
    {
        std::string e;
        s >> e;

        entities.emplace_back(factory.build(e));
    }

    for (const auto& e: entities)
    {
        if (e != nullptr)
        {
            e->print();
        }
    }

    return 0;
}


