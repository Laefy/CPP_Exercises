#include <memory>
#include <string>
#include <sstream>
#include <iostream>
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

    // template <...>
    void register_entity(...) {
    }

    std::unique_ptr<Entity> build(const std::string& id) const
    {
        return nullptr;
    }

private:
};

class Object: public Entity
{
public:
    void print() const override
    {
        std::cout << "Object" << std::endl;
    }
};

class Tree : public Object {};

class Person : public Entity {};
class Animal : public Entity {};
class House : public Object {};

int main()
{
    Factory factory;
    //factory.register_entity<Object>("Object");

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


