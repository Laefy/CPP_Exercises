#include <string>
#include <string_view>

class Person2
{
public:
    Person2(std::string_view name)
        : _name { name }
    {}

private:
    std::string _name;
};