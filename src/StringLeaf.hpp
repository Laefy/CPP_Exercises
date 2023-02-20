#pragma once

#include "Leaf.hpp"
#include "Node.hpp"

#include <string>

class StringLeaf : public Leaf
{
private:
    std::string _data;

public:
    StringLeaf(std::string data)
        : Leaf { NodeKind::STRING }
        , _data { data }
    {}

    /* Added for test 3 */
    std::string        print() const override;
    const std::string& data() const { return _data; }

    /* Added for test 10 */
    static std::unique_ptr<StringLeaf> make_ptr(std::string s);

    /* Added for test 40 */
    NodePtr deep_copy() const override { return make_ptr(data()); }

    /* Added for test 41 */
    bool operator==(const Node& other) const override;

    /* Not needed to pass tests */
    std::string dot_label() const override { return "\\\"" + _data + "\\\""; }
};