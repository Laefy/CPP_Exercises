#include "../../lib/InstanceCounter.hpp"
#include "../../src/uge_unique_ptr.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("a. `uge::unique_ptr` can be built from a pointer, taking ownership of it.")
{
    InstanceCounter::reset_counters();
    {
        [[maybe_unused]] uge::unique_ptr<InstanceCounter> ptr { new InstanceCounter() };
        // At the end of the block `ptr` is destroyed.
        // We expect the object held to be destroyed as well.
    }
    REQUIRE(InstanceCounter::count() == 0u);
}

TEST_CASE("b. `uge::unique_ptr` has a method get().")
{
    InstanceCounter*                 ic1 = new InstanceCounter {};
    uge::unique_ptr<InstanceCounter> ptr { ic1 };

    InstanceCounter* ic2 = ptr.get();
    REQUIRE(ic1 == ic2);
}

TEST_CASE("c. `uge::unique_ptr` is default-constructible in which case it holds a nullptr.")
{
    uge::unique_ptr<InstanceCounter> uptr;
    REQUIRE(uptr.get() == nullptr);
}