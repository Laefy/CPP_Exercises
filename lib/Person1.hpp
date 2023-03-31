#include <string>

class Person1
{
public:
    Person1(const std::string &name)
        : _name{name} {}

private:
    std::string _name;
};
