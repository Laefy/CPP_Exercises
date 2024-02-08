#include "../src/qcm.hpp"

#include <catch2/catch_test_macros.hpp>
#include <optional>

TEST_CASE("QCM - You answered all questions")
{
    REQUIRE(std::optional<bool> { ANSWER_1 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_2 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_3 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_4 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_5 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_6 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_7 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_8 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_9 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_10 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_11 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_12 } != std::nullopt);
}
