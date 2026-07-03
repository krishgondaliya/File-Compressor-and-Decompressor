#include <gtest/gtest.h>

#include "bit_writer.hpp"

TEST(BitWriterSkeleton, CanBeConstructed)
{
    const huffzip::BitWriter writer;
    (void)writer;
}
