#include "../../lib/InstanceCounter.hpp"
#include "../../src/uge_unique_ptr.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("b. `uge::unique_ptr` can be dereferenced")
{
    InstanceCounter* ptr  = new InstanceCounter();
    InstanceCounter& ref1 = *ptr;

    uge::unique_ptr<InstanceCounter> uptr { ptr };
    InstanceCounter&                 ref2 = *uptr;

    // The two references ic_ref1 and ic_ref2 are the same in
    // the sense that they reference the same part of memory.
    REQUIRE(&ref1 == &ref2);
}