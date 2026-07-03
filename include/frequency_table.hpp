#pragma once

#include <array>
#include <cstdint>

namespace huffzip {

class FrequencyTable {
public:
    FrequencyTable() = default;

private:
    std::array<std::uint64_t, 256> frequencies_{};
    std::uint64_t total_bytes_{0};
};

}  // namespace huffzip
