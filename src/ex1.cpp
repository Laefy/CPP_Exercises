#include "ex1.hpp"

#include "../lib/concatenate.hpp"

void pairwise_concatenate(std::list<std::list<int>>& list1, std::list<std::list<int>>&& list2)
{
    for (unsigned i = list1.size(); i < list2.size(); ++i)
        list1.emplace_back();
    auto it1 = list1.begin();
    for (auto it2 = list2.begin(); it2 != list2.end(); ++it2)
    {
        concatenate(*it1, std::move(*it2));
        ++it1;
    }
}

void pairwise_concatenate(std::list<std::list<int>>& list1, const std::list<std::list<int>>& list2)
{
    for (unsigned i = list1.size(); i < list2.size(); ++i)
        list1.emplace_back();
    auto it1 = list1.begin();
    for (auto it2 = list2.begin(); it2 != list2.end(); ++it2)
    {
        concatenate(*it1, *it2);
        ++it1;
    }
}
