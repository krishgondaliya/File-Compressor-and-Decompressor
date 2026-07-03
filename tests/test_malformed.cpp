#include <gtest/gtest.h>

#include "errors.hpp"

TEST(MalformedSkeleton, FormatErrorCarriesMessage)
{
    const huffzip::FormatError error{"bad format"};

    EXPECT_STREQ(error.what(), "bad format");
}
