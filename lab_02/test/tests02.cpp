#include <gtest/gtest.h>
#include "../include/Twelve.h"

TEST(test_02, Defalut_constructor)
{
    Twelve num;
    
    EXPECT_EQ(num.get_decimal(), 0);
    
    Twelve other("A");
    Twelve sum = num.plus(other);
    EXPECT_EQ(sum.get_decimal(), 10);

}

TEST(test_02, Size)
{
    Twelve num (3, 'A');
    EXPECT_EQ(num.get_decimal(), 1570);

}

TEST(test_02, String)
{
    Twelve num ("1AB");
    EXPECT_EQ(num.get_decimal(), 275);

}

TEST(test_02, list)
{
    Twelve num{'A', 'B', '1'};
    EXPECT_EQ(num.get_decimal(), 1573);

}

TEST(test_02, Plus)
{
    Twelve a("1A");
    Twelve b(2, '2');
    Twelve res = a.plus(b);
    EXPECT_EQ(res.get_decimal(), 48);

}

TEST(test_02, Minus)
{
    Twelve a("27");
    Twelve b(2, '2');
    Twelve res = a.minus(b);
    EXPECT_EQ(res.get_decimal(), 5);

}

TEST(test_02, Minus_Error)
{
    Twelve a("5");
    Twelve b("A7");

    EXPECT_THROW(a.minus(b), std::underflow_error);

}
TEST(test_02, Copy) {
    Twelve original("123A");
    Twelve copy = original.copy();
    
    EXPECT_TRUE(original.equals(copy));
    EXPECT_EQ(original.get_decimal(), copy.get_decimal());
}

TEST(test_02, Equals) {
    Twelve a("AAA");
    Twelve b(3, 'A');
    Twelve c("ABA");
    
    EXPECT_TRUE(a.equals(b));
    EXPECT_FALSE(a.equals(c));
}

TEST(test_02, Bigger) {
    Twelve a("A"); 
    Twelve b("B"); 
    
    EXPECT_FALSE(a.bigger(b));
    EXPECT_TRUE(b.bigger(a));
}

TEST(test_02, Immutability) {
    Twelve original("123A");
    Twelve a = original.plus(Twelve("1"));
    Twelve b = original.minus(Twelve("1"));
    
    // Оригинальный объект не изменился
    EXPECT_EQ(original.get_decimal(), 2062);
    EXPECT_TRUE(original.equals(Twelve("123A")));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
