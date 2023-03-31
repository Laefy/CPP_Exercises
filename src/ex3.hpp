#pragma once

#include <iterator>

template <unsigned i>
constexpr unsigned fibonacci()
{
    if constexpr (i < 2)
        return 1;
    else
        return fibonacci<i - 1>() + fibonacci<i - 2>();
}

template <typename T1, typename T2>
constexpr bool content_of_same_type()
{
    return std::is_same<typename T1::value_type, typename T2::value_type>::value;
}

template <typename T>
constexpr bool has_random_access()
{
    return std::is_same<typename std::iterator_traits<typename T::iterator>::iterator_category,
                        std::random_access_iterator_tag>::value;
}

template <typename T>
int access(T const &container, unsigned i)
{
    if constexpr (has_random_access<T>())
        return container[i];
    else
    {
        auto it = container.begin();
        for (int k = 0; k < i; k++)
            ++it;
        return *it;
    }
}

template <typename T1, typename T2>
void add_all(T1 &t1, const T2 &t2)
{
    if constexpr (content_of_same_type<T1, T2>())
        for (const auto &elem : t2)
            t1.emplace_back(elem);
}