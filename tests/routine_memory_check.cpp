#include "../src/InstanceCounter.hpp"

/* All tests will end with this TEST_CASE. */
TEST_CASE("Routine memory check: all nodes were correctly deallocated.")
{
    REQUIRE(InstanceCounter::counter() == 0);
}
