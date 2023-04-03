#include "concatenate.hpp"

void concatenate(std::list<int>& list1, std::list<int>&& list2)
{
    list1.splice(list1.end(), std::move(list2));
    // We use the function splice (https://en.cppreference.com/w/cpp/container/list/splice),
    // which does exactly what we want.
}

void concatenate(std::list<int>& list1, const std::list<int>& list2)
{
    for (int i : list2)
        list1.push_back(i); // We copy every element
}