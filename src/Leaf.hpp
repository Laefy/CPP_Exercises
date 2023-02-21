#pragma once

#include "Node.hpp"

class Leaf : public Node
{
protected:
    Leaf(NodeKind kind)
        : Node(kind)
    {}

public:
    /* Added for test 20 */
    size_t height() const override { return 0u; }
    size_t node_count() const override { return 1u; }
};
