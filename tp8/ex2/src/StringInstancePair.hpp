#include "../lib/InstanceCounter.hpp"

#include <memory>
#include <string>

class StringInstancePair
{
public:
    StringInstancePair(std::string s)
        : _str(std::move(s))
        , _ins(std::make_unique<InstanceCounter>())
    {}

    StringInstancePair(StringInstancePair&& other) = default;

    StringInstancePair(const StringInstancePair& other)
        : _str { other._str }
        , _ins { std::make_unique<InstanceCounter>(other.get_instance_counter()) }
    {}

    const InstanceCounter& get_instance_counter() const { return *_ins; }
    const std::string&     get_str() const { return _str; }

private:
    std::string                      _str;
    std::unique_ptr<InstanceCounter> _ins;
};
