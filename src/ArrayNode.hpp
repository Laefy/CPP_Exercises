#pragma once

#include "Node.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class ArrayNode : public Node
{
private:
    std::vector<NodePtr> _data;

public:
    /* Added for test 4 */
    ArrayNode()
        : Node(NodeKind::ARRAY)
    {}
    std::string print() const override;

    /* Added for test 10 */
    static std::unique_ptr<ArrayNode> make_ptr(std::vector<NodePtr> data = {});

    /* Added for test 11 */
    size_t child_count() const { return _data.size(); }
    void   push_back(NodePtr node);

    /* Added for test 20 */
    size_t height() const override;
    size_t node_count() const override;

    /* Added for test 36 */
    std::vector<NodePtr>::iterator begin() { return _data.begin(); }
    std::vector<NodePtr>::iterator end() { return _data.end(); }

    /* Added for test 38 */
    std::vector<NodePtr>::const_iterator begin() const { return _data.begin(); }
    std::vector<NodePtr>::const_iterator end() const { return _data.end(); }

    /* Added for test 40*/
    bool operator==(const Node& other) const override;

    /* Added for test 41*/
    NodePtr deep_copy() const override;

    /* Not needed to pass tests */
    std::string dot_label() const override { return "[...]"; }
    void        dot(std::ostream& o) const;
};
