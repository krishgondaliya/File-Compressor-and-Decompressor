#pragma once

#include <cstdint>
#include <memory>

namespace huffzip {

struct HuffmanNode {
    std::uint64_t frequency{0};
    std::uint16_t min_symbol{0};
    bool is_leaf{false};
    std::uint8_t symbol{0};
    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right;
};

}  // namespace huffzip
