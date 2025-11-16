#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Square.h"
#include "../include/Triangle.h"
#include "../include/Rectangle.h"
#include "../include/Array.h"

TEST(Point, ParameterizedConstructor) {
    Point<double> p(3.5, 2.1);
    EXPECT_DOUBLE_EQ(p.x(), 3.5);
    EXPECT_DOUBLE_EQ(p.y(), 2.1);
}

TEST(Point, OutputOperator) {
    Point<int> p(10, 20);
    testing::internal::CaptureStdout();
    std::cout << p;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(10, 20)");
}

TEST(SquareTest, ConstructorAndGetters) {
    Square<double> square(1.0, 2.0, 4.0);
    Point<double> center = square.geom_center();
    EXPECT_DOUBLE_EQ(center.x(), 1.0);
    EXPECT_DOUBLE_EQ(center.y(), 2.0);
}

TEST(SquareTest, AreaCalculation) {
    Square<double> square(0, 0, 5.0);
    EXPECT_DOUBLE_EQ(square.area(), 25.0);
}

TEST(SquareTest, IntCoordinates) {
    Square<int> square(0, 0, 3);
    EXPECT_DOUBLE_EQ(square.area(), 9.0);
}

TEST(TriangleTest, ConstructorAndArea) {
    Triangle<double> triangle(0, 0, 6.0, 4.0);
    EXPECT_DOUBLE_EQ(triangle.area(), 12.0);
}

TEST(TriangleTest, GeometricCenter) {
    Triangle<double> triangle(2.0, 3.0, 4.0, 5.0);
    Point<double> center = triangle.geom_center();
    EXPECT_DOUBLE_EQ(center.x(), 2.0);
    EXPECT_DOUBLE_EQ(center.y(), 3.0);
}

TEST(RectangleTest, ConstructorAndArea) {
    Rectangle<double> rect(0, 0, 4.0, 3.0);
    EXPECT_DOUBLE_EQ(rect.area(), 12.0); 
}

TEST(RectangleTest, GeometricCenter) {
    Rectangle<double> rect(1.5, 2.5, 6.0, 4.0);
    Point<double> center = rect.geom_center();
    EXPECT_DOUBLE_EQ(center.x(), 1.5);
    EXPECT_DOUBLE_EQ(center.y(), 2.5);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}