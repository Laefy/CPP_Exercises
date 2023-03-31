
#include <catch2/catch_test_macros.hpp>
#include "../../lib/InstanceCounter.hpp"
#include "../../src/uge_unique_ptr.hpp"

TEST_CASE("a. `uge::unique_ptr` is copy-constructible.")
{
    InstanceCounter::reset_counters();
    {
        uge::unique_ptr<InstanceCounter> uptr1 = (new InstanceCounter());
        REQUIRE(InstanceCounter::count() == 1u);
        uge::unique_ptr<InstanceCounter> uptr2 = uptr1;
        REQUIRE(InstanceCounter::count() == 2u);

        REQUIRE(uptr1.get() != uptr2.get());
    }
    REQUIRE(InstanceCounter::count() == 0u);
}

TEST_CASE("B. `uge::unique_ptr` is move-constructible.")
{
    InstanceCounter::reset_counters();
    {
        InstanceCounter *ptr = new InstanceCounter();
        uge::unique_ptr<InstanceCounter> uptr1{ptr};
        REQUIRE(InstanceCounter::count() == 1u);
        REQUIRE(uptr1.get() == ptr);

        uge::unique_ptr<InstanceCounter> uptr2 = std::move(uptr1);
        REQUIRE(InstanceCounter::count() == 1u);

        REQUIRE(uptr1.get() == nullptr);
        REQUIRE(uptr2.get() == ptr);
    }
    REQUIRE(InstanceCounter::count() == 0u);
}
