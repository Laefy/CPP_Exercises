#pragma once

#include "Leaf.hpp"
#include "Node.hpp"

class IntLeaf : public Leaf
{
private:
    int _data;

public:
    inline const int& data() const { return _data; }

    std::string print() const override { return std::to_string(_data); }

    IntLeaf(int data)
        : Leaf { NodeKind::INT }
        , _data { data }
    {}

    /* Added for test 10 */
    static std::unique_ptr<IntLeaf> make_ptr(int data);

    /* Added for test 40 */
    NodePtr deep_copy() const override { return make_ptr(data()); }

    /* Added for test 43 */
    bool operator==(const Node& other) const override;

    std::string dot_label() const override { return std::to_string(_data); }
};
