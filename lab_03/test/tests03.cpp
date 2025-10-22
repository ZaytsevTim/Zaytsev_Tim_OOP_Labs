#include <gtest/gtest.h>
#include "../include/Figure.h"
#include "../include/Rectangle.h"
#include "../include/Square.h"
#include "../include/Trapezoid.h"


TEST(RectangleTest, DefaultConstructor) {
    Rectangle rect;
    auto center = rect.center();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 0.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 0.0); 
}
TEST(RectangleTest, Area1) {
    Rectangle rect(1, 2, 4, 2, 4, 1, 1, 1);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 3.0); 
}

TEST(RectangleTest, Area2) {
    Rectangle rect(1.2, 2.2, 4.2, 2.2, 4.2, 1.2, 1.2, 1.2);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 3.0); 
}

TEST(RectangleTest, CenterCalculation) {
    Rectangle rect(1, 2, 4, 2, 4, 1, 1, 1);
    auto center = rect.center();
    EXPECT_DOUBLE_EQ(center.first, 2.5);  
    EXPECT_DOUBLE_EQ(center.second, 1.5); 
}

TEST(RectangleTest, PerimeterCalculation) {
    Rectangle rect(0, 0, 3, 0, 3, 4, 0, 4);
    EXPECT_DOUBLE_EQ(rect.perimeter(), 14.0); 
}

TEST(RectangleTest, EqualityOperator) {
    Rectangle rect1(0, 0, 2, 0, 2, 3, 0, 3);
    Rectangle rect2(-2, 0, -2, -3, 0, -3, 0, 0); // тот же прямоугольник, но вершини перечисляем, начиная со второй
    Rectangle rect3(1, 2, 7, 2, 7, 1, 1, 1); // такая же площадь, но другой периметр
    
    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
}

TEST(SquareTest, Area) {
    Square square(0, 0, 2, 0, 2, 2, 0, 2);
    EXPECT_DOUBLE_EQ(static_cast<double>(square), 4.0); 
}

TEST(SquareTest, Perimeter) {
    Square square(0, 0, 3, 0, 3, 3, 0, 3);
    EXPECT_DOUBLE_EQ(square.perimeter(), 12.0); 
}

TEST(SquareTest, Center) {
    Square square(1, 1, 3, 1, 3, 3, 1, 3);
    auto center = square.center();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

TEST(TrapezoidTest, Area) {
    Trapezoid trapezoid(0, 0, 4, 0, 3, 3, 1, 3);
    double expected_area = (4 + 2) * 3 / 2.0;
    EXPECT_NEAR(static_cast<double>(trapezoid), expected_area, 1e-9);
}

TEST(TrapezoidTest, Perimeter) {
    Trapezoid trapezoid(0, 0, 4, 0, 3, 3, 1, 3);
    double perimeter = trapezoid.perimeter();
    EXPECT_GT(perimeter, 0.0); 
}


TEST(AssignmentOperatorsTest, Copy) {
    Rectangle rect1(0, 0, 2, 0, 2, 2, 0, 2);
    Rectangle rect2;
    
    rect2 = rect1;
    EXPECT_TRUE(rect1 == rect2);
}

TEST(AssignmentOperatorsTest, Move) {
    Rectangle rect1(0, 0, 2, 0, 2, 2, 0, 2);
    Rectangle rect2;
    double original_area = static_cast<double>(rect1);
    
    rect2 = std::move(rect1);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect2), original_area);
}

TEST(ComparisonTest, DifferentTypes) {
    Rectangle rect(0, 0, 2, 0, 2, 2, 0, 2);
    Square square(0, 0, 2, 0, 2, 2, 0, 2);
    
    EXPECT_FALSE(rect == square);
}

TEST(Test, Zero) {
    Rectangle zero_rect(0, 0, 0, 0, 0, 0, 0, 0);
    EXPECT_DOUBLE_EQ(static_cast<double>(zero_rect), 0.0);
}

TEST(Test, Negative) {
    Rectangle rect(-2, -2, 0, -2, 0, 0, -2, 0);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 4.0);
}

TEST(ConversionTest, Area_from_cast) {
    Square square(0, 0, 3, 0, 3, 3, 0, 3);

    double area_direct = square.area();
    double area_conversion = static_cast<double>(square);
    
    EXPECT_DOUBLE_EQ(area_direct, area_conversion);
    
    double twoX_area = square * 2.0; 
    EXPECT_DOUBLE_EQ(twoX_area, 18.0); 
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}