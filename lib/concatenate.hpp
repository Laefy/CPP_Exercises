#pragma once
#include <list>

//                                                    vv r-value reference
void concatenate(std::list<int>& list1, std::list<int>&& list2);
//                             ^
//      list1 is an l-value reference because we will modify it
//                             v
void concatenate(std::list<int>& list1, const std::list<int>& list2);
//                                      ^^^^^               ^ const l-value reference