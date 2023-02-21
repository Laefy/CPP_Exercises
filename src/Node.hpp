#pragma once

#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class NullNode;
// class BooleanLeaf;
class IntLeaf;
class StringLeaf;
class ArrayNode;
class ObjectNode;

class Node;

using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter
{
private:
    const NodeKind _kind;

protected:
    Node(NodeKind kind)
        : _kind(kind)
    {}

public:
    virtual ~Node() = default;

    /* Added for tests 1 to 5 */
    NodeKind            kind() const { return _kind; }
    virtual std::string print() const = 0;

    /* Added for tests 20 */
    virtual size_t height() const     = 0;
    virtual size_t node_count() const = 0;

    /* Added for tests 30 to 33 */
    IntLeaf*    as_IntLeaf();
    StringLeaf* as_StringLeaf();
    ArrayNode*  as_ArrayNode();
    ObjectNode* as_ObjectNode();

    /* Added for test 38 */
    const IntLeaf*    as_IntLeaf() const;
    const StringLeaf* as_StringLeaf() const;
    const ArrayNode*  as_ArrayNode() const;
    const ObjectNode* as_ObjectNode() const;

    /* Added for test 41 */
    virtual NodePtr deep_copy() const = 0;

    /* Added for test 40 */
    virtual bool operator==(const Node&) const = 0;

    /* Not needed to pass tests */
    virtual std::string dot_label() const = 0;
    virtual void        dot(std::ostream& o) const;
    std::string         dot_id() const;
};

std::ostream& operator<<(std::ostream& o, const Node& node);
