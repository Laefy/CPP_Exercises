#pragma once

#include "ArrayNode.hpp"
#include "IntLeaf.hpp"
#include "Node.hpp"
#include "NodeKind.hpp"
#include "ObjectNode.hpp"
#include "StringLeaf.hpp"

#include <iostream>
#include <optional>

class JsonParser
{
private:
    std::istream& _in;

    void extract_spaces();
    bool check_next_char_equals(int c, std::string_view other_possibilities = "");

    std::optional<std::string> extract_string();

    std::unique_ptr<Node> parse_Node();
    std::unique_ptr<Node> parse_constant(std::string_view target);
    std::unique_ptr<Node> parse_StringLeaf();
    std::unique_ptr<Node> parse_IntLeaf();
    std::unique_ptr<Node> parse_ArrayNode();
    std::unique_ptr<Node> parse_ObjectNode();

public:
    JsonParser(std::istream& in)
        : _in(in)
    {}

    std::unique_ptr<Node> run();

    static std::unique_ptr<Node> parse_from_istream(std::istream& in);
    static std::unique_ptr<Node> parse_from_file(std::string const& path);
    static std::unique_ptr<Node> parse_from_string(std::string const& str);
};