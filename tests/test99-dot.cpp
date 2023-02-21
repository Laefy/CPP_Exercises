#include "../src/JsonParser.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <catch2/catch_test_macros.hpp>

void dot(std::ostream &o, NodePtr const &node)
{
    o << "digraph G {" << std::endl;
    o << "rankdir=LR;" << std::endl;
    node->dot(o);
    o << "}" << std::endl;
}

TEST_CASE("")
{
    std::string dir = "../json/";

    std::string filename = dir + "cpp2023.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    NodePtr node = JsonParser::parse_from_file(filename);

    std::ofstream out("/tmp/test.gv");
    dot(out, node);
}