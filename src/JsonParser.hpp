#pragma once

#include "ArrayNode.hpp"
#include "IntLeaf.hpp"
#include "Node.hpp"
#include "NodeKind.hpp"
#include "ObjectNode.hpp"
#include "OptionalString.hpp"
#include "StringLeaf.hpp"

#include <iostream>

class JsonParser
{
private:
    std::istream& _in;

    void extract_spaces();
    bool check_next_char_equals(int c, std::string_view other_possibilities = "");

    OptionalString extract_string();

    NodePtr parse_Node();
    NodePtr parse_constant(std::string_view target);
    NodePtr parse_StringLeaf();
    NodePtr parse_IntLeaf();
    NodePtr parse_ArrayNode();
    NodePtr parse_ObjectNode();

public:
    JsonParser(std::istream& in)
        : _in(in)
    {}

    NodePtr run();

    static NodePtr parse_from_istream(std::istream& in);
    static NodePtr parse_from_file(std::string const& path);
    static NodePtr parse_from_string(std::string const& str);
};