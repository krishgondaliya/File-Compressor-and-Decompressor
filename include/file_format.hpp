#pragma once

#include <array>

namespace huffzip::file_format {

inline constexpr std::array<char, 4> kMagic = {'H', 'F', 'C', '1'};

}  // namespace huffzip::file_format
