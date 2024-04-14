#include "../src/02-hashing.hpp"

#include <catch2/catch_test_macros.hpp>
#include <unordered_set>

struct MyObject
{
    bool ANSWER_1(const MyObject& other) const { return ANSWER_2; }

    int value = 0;
};

namespace std {

ANSWER_3
struct ANSWER_4
{
    int operator()(const MyObject& o) const { return o.value; }
};

} // namespace std

TEST_CASE("MyObject can be used inside an unordered_set")
{
    auto set = std::unordered_set<MyObject> {};
    REQUIRE(set.size() == 0u);

    // 3 can be emplaced
    set.emplace(MyObject { 3 });
    REQUIRE(set.size() == 1u);

    // -4 too
    set.emplace(MyObject { -4 });
    REQUIRE(set.size() == 2u);

    // 3 is already present
    set.emplace(MyObject { 3 });
    REQUIRE(set.size() == 2u);
}