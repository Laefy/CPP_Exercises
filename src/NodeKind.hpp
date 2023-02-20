#pragma once

#include <iostream>

enum class NodeKind
{
    INT,
    STRING,
    ARRAY,
    OBJECT
};

std::ostream& operator<<(std::ostream& o, NodeKind kind);
