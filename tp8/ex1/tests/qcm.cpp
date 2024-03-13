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

    REQUIRE(std::optional<bool> { ANSWER_10 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_11 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_12 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_13 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_14 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_15 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_16 } != std::nullopt);

    REQUIRE(std::optional<bool> { ANSWER_20 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_21 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_22 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_23 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_24 } != std::nullopt);
    REQUIRE(std::optional<bool> { ANSWER_25 } != std::nullopt);
}
