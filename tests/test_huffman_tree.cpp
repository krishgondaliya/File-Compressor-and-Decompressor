#include <gtest/gtest.h>

#include "huffman_tree.hpp"

TEST(HuffmanTreeSkeleton, NodeHasDefaultState)
{
    const huffzip::HuffmanNode node;

    EXPECT_EQ(node.frequency, 0U);
    EXPECT_FALSE(node.is_leaf);
}
