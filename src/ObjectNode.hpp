#pragma once

#include "Node.hpp"

#include <map>
#include <memory>
#include <numeric>

class ObjectNode : public Node
{
private:
    std::map<std::string, NodePtr> _data;

public:
    const std::map<std::string, NodePtr>& data() const { return _data; }

    /* Added for test 5*/
    ObjectNode()
        : Node(NodeKind::OBJECT)
    {}
    std::string print() const override;

    /* Added for test 10*/
    static std::unique_ptr<ObjectNode> make_ptr(std::map<std::string, NodePtr> data = {});

    /* Added for test 12*/
    void   insert(std::string key, NodePtr value) { _data.emplace(std::move(key), std::move(value)); }
    size_t child_count() const { return _data.size(); }

    /* Added for test 20 */
    size_t height() const override;
    size_t node_count() const override;

    /* Added for test 34*/
    bool  has_child(const std::string& key) const { return _data.count(key); }
    Node* at(const std::string& key);

    /* Added for test 38 */
    const Node* at(std::string const& key) const;

    /* Added for test 40 */
    bool operator==(const Node& other) const override;

    /* Added for test 41 */
    NodePtr deep_copy() const override;

    /* Not needed to pass tests */
    std::string dot_label() const override { return "{...}"; }
    void        dot(std::ostream& o) const override;
};
