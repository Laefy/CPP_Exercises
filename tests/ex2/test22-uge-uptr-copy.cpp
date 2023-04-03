
#include "../../lib/InstanceCounter.hpp"
#include "../../src/uge_unique_ptr.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("a. A `uge::unique_ptr` is copy-constructible.")
{
    InstanceCounter::reset_counters();
    {
        uge::unique_ptr<InstanceCounter> uptr1 { new InstanceCounter() };
        REQUIRE(InstanceCounter::count() == 1u);
        uge::unique_ptr<InstanceCounter> uptr2 = uptr1;
        REQUIRE(InstanceCounter::count() == 2u);

        REQUIRE(uptr1.get() != uptr2.get());
    }
    REQUIRE(InstanceCounter::count() == 0u);
}

TEST_CASE("b. Copy of an empty `uge::unique_ptr` does not cause memory problems..")
{
    InstanceCounter::reset_counters();
    uge::unique_ptr<InstanceCounter> uptr1 {};
    uge::unique_ptr<InstanceCounter> uptr2 = uptr1;

    REQUIRE(InstanceCounter::count() == 0u);
    REQUIRE(uptr2.get() == nullptr);
}
