#include <gtest/gtest.h>
#include "../include/num_to_32bit.h"

TEST(test_01, test_set)
{
    ASSERT_TRUE(num_to_32bit(1)=="00000000000000000000000000000001");
}

TEST(test_02, test_set)
{
    ASSERT_TRUE(num_to_32bit(275)=="00000000000000000000000100010011");
}

TEST(test_03, test_set)
{
    ASSERT_TRUE(num_to_32bit(1073741825)=="01000000000000000000000000000001");
}

TEST(test_04, test_set)
{
    ASSERT_TRUE(num_to_32bit(0)=="00000000000000000000000000000000");
}

TEST(test_05, test_set)
{
    ASSERT_TRUE(num_to_32bit(2147483647)=="01111111111111111111111111111111");
}
TEST(test_06, test_set)
{
    ASSERT_TRUE(num_to_32bit(4294967295)=="11111111111111111111111111111111");
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
