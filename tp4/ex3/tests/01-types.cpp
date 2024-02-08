#include "../src/01-types.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

ANSWER_1A stringify_integer(ANSWER_1B integer);
ANSWER_2A count_nb_elements(ANSWER_2B elements);

class WrappedString
{
public:
    WrappedString(ANSWER_3A initial_content)
        : _content { initial_content }
    {}

    ANSWER_3B get_readonly_content() ANSWER_3C { return _content; }
    ANSWER_3D get_modifiable_content() ANSWER_3E { return _content; }

private:
    std::string _content;
};

TEST_CASE("Vérifie le comportement de WrappedString")
{
    WrappedString str { "hello" };

    // get_readonly_content() permet de récupérer le contenu de str.
    const auto c1 = str.get_readonly_content();
    REQUIRE("hello" == c1);

    // get_readonly_content() permet de récupérer ET de modifier le contenu de str.
    str.get_modifiable_content() = "bye";

    // L'instruction précédente a bien modifié la donnée contenue dans str.
    const auto c2 = str.get_readonly_content();
    REQUIRE("bye" == c2);
}
