#pragma once

#include <list>

void pairwise_concatenate(std::list<std::list<int>>& list1, std::list<std::list<int>>&& list2);
void pairwise_concatenate(std::list<std::list<int>>& list1, const std::list<std::list<int>>& list2);
