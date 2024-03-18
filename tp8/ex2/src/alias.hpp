#pragma once

#include "../lib/InstanceCounter.hpp"

#include <memory>

using PTR_ALIAS1 = std::unique_ptr<InstanceCounter>;
using PTR_ALIAS2 = InstanceCounter*;