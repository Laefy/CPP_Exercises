#include "../src/IntLeaf.hpp"
#include "../src/StringLeaf.hpp"
#include "../src/ArrayNode.hpp"
#include "../src/ObjectNode.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("The kind of IntLeaf is NodeKind::INTEGER.")
{
    IntLeaf i{1};
    REQUIRE(i.kind() == NodeKind::INT);

    Node &n = i;
    REQUIRE(n.kind() == NodeKind::INT);
}

TEST_CASE("The kind of Stringleaf is NodeKind::STRING.")
{
    StringLeaf s{"Hello World"};
    REQUIRE(s.kind() == NodeKind::STRING);

    Node &n = s;
    REQUIRE(n.kind() == NodeKind::STRING);
}

TEST_CASE("The kind of ArrayNode is NodeKind::ARRAY.")
{
    ArrayNode a{};
    REQUIRE(a.kind() == NodeKind::ARRAY);

    Node &n = a;
    REQUIRE(n.kind() == NodeKind::ARRAY);
}

TEST_CASE("The kind of ObjectNode is NodeKind::OBJECT.")
{
    ObjectNode o{};
    REQUIRE(o.kind() == NodeKind::OBJECT);

    Node &n = o;
    REQUIRE(n.kind() == NodeKind::OBJECT);
}

/* The class LyingIntLeaf is an IntLeaf that lies about its kind when LyingIntLeaf::kind(). */
class LyingIntLeaf : public IntLeaf
{
public:
    LyingIntLeaf(int data) : IntLeaf(data) {}

    NodeKind kind() const { return NodeKind::STRING; }
    NodeKind kind() { return NodeKind::STRING; }
};

TEST_CASE("Node::kind() is statically typed ! ")
{
    LyingIntLeaf i{42};
    REQUIRE(i.kind() == NodeKind::STRING);

    Node &n = i;
    REQUIRE(n.kind() == NodeKind::INT);

    const Node &n_const = i;
    REQUIRE(n.kind() == NodeKind::INT);

    /*
        Hint: the kind of a Node should be stored in the class Node,
        and passed on in the constructor.
    */
}
