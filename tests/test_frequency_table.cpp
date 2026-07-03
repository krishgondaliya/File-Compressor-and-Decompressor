#include <gtest/gtest.h>

#include "frequency_table.hpp"

TEST(FrequencyTableSkeleton, CanBeConstructed)
{
    const huffzip::FrequencyTable table;
    (void)table;
}
