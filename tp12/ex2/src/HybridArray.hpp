#pragma once

#include <algorithm>
#include <array>
#include <functional>
#include <utility>
#include <vector>

template <typename TValue, size_t TStaticSize>
class HybridArray
{
public:
    template <typename... TArgs, std::enable_if_t<(sizeof...(TArgs) <= TStaticSize), int> = 0>
    HybridArray(TArgs&&... args)
        : _static_values { std::forward<TArgs>(args)... }
        , _static_count { sizeof...(TArgs) }
    {}

    template <typename... TArgs, std::enable_if_t<(sizeof...(TArgs) > TStaticSize), int> = 0>
    HybridArray(TArgs&&... args)
        : _dynamic_values { std::forward<TArgs>(args)... }
        , _static_count { TStaticSize }
    {}

    constexpr static size_t static_size() { return TStaticSize; }

    size_t size() const { return _dynamic_values.empty() ? _static_count : _dynamic_values.size(); }

    TValue& push_back(const TValue& value)
    {
        if (_static_count < TStaticSize)
        {
            return _static_values[_static_count++] = value;
        }
        else
        {
            if (_static_count == TStaticSize && _dynamic_values.empty())
            {
                std::move(_static_values.begin(), _static_values.end(), std::back_inserter(_dynamic_values));
            }

            _dynamic_values.push_back(value);
            return _dynamic_values.back();
        }
    }

    const TValue& operator[](size_t index) const
    {
        return _dynamic_values.empty() ? _static_values[index] : _dynamic_values[index];
    }

    TValue& operator[](size_t index) { return const_cast<TValue&>(std::as_const(*this)[index]); }

private:
    std::array<TValue, TStaticSize> _static_values {};
    size_t                          _static_count = 0u;

    std::vector<TValue> _dynamic_values;
};

template <typename TValue>
class HybridArray<TValue, 0u> : public std::vector<TValue>
{
    using std::vector<TValue>::vector;
};
