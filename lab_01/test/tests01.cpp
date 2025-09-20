#include <gtest/gtest.h>
#include "../include/num_to_32bit.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(num_to_32bit(1)=="00000000000000000000000000000001");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(num_to_32bit(275)=="00000000000000000000000100010011");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(num_to_32bit(1073741825)=="01000000000000000000000000000001");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
