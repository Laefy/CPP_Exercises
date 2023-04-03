#include <string>

class Person3
{
public:
    Person3(std::string name)
        : _name { std::move(name) }
    {}

private:
    std::string _name;
};