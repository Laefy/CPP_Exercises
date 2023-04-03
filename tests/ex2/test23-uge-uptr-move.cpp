#include "../../lib/InstanceCounter.hpp"
#include "../../src/uge_unique_ptr.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("a. `uge::unique_ptr` is move-constructible.")
{
    InstanceCounter::reset_counters();
    {
        InstanceCounter*                 ptr { new InstanceCounter() };
        uge::unique_ptr<InstanceCounter> uptr1 { ptr };
        REQUIRE(InstanceCounter::count() == 1u);
        REQUIRE(uptr1.get() == ptr);

        uge::unique_ptr<InstanceCounter> uptr2 = std::move(uptr1);
        REQUIRE(InstanceCounter::count() == 1u);

        REQUIRE(uptr1.get() == nullptr);
        REQUIRE(uptr2.get() == ptr);
    }
    REQUIRE(InstanceCounter::count() == 0u);
}

TEST_CASE("b. Move of an empty `uge::unique_ptr` does not cause memory problems.")
{
    InstanceCounter::reset_counters();
    uge::unique_ptr<InstanceCounter> uptr1 {};
    uge::unique_ptr<InstanceCounter> uptr2 = std::move(uptr2);
    REQUIRE(InstanceCounter::count() == 0u);

    REQUIRE(uptr2.get() == nullptr);
}
