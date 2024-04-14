#include "../src/qcm.hpp"

#include <catch2/catch_test_macros.hpp>
#include <optional>

TEST_CASE("QCM - You answered all questions")
{
    REQUIRE(std::optional<bool>{ANSWER_00} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_01} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_02} != std::nullopt);
    
    REQUIRE(std::optional<bool>{ANSWER_10} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_11} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_12} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_13} != std::nullopt);
    
    REQUIRE(std::optional<bool>{ANSWER_20} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_21} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_22} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_23} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_24} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_25} != std::nullopt);
    
    REQUIRE(std::optional<bool>{ANSWER_30} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_31} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_32} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_33} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_34} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_35} != std::nullopt);

    REQUIRE(std::optional<bool>{ANSWER_40} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_41} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_42} != std::nullopt);
    REQUIRE(std::optional<bool>{ANSWER_43} != std::nullopt);
}
