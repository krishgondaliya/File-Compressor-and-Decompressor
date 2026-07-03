#include <gtest/gtest.h>

#include "bit_reader.hpp"

TEST(BitReaderSkeleton, CanBeConstructed)
{
    const huffzip::BitReader reader;
    (void)reader;
}
