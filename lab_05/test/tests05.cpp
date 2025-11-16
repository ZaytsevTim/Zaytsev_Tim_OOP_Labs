#include "../include/PmrList.hpp"
#include "../include/MemoryResource.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(PmrListTest, DefaultConstruction) {
    FixedBlockMemoryResource mem(1024);
    PmrList<int> list(&mem);
    
    EXPECT_EQ(list.begin(), list.end());
}

TEST(PmrListTest, PushBackAndSize) {
    FixedBlockMemoryResource mem(1024);
    PmrList<int> list(&mem);
    
    list.push_back(123);
    list.push_back(231);
    list.push_back(999);
    
    int count = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        ++count;
    }
    EXPECT_EQ(count, 3);
}

TEST(PmrListTest, PushFront) {
    FixedBlockMemoryResource mem(1024);
    PmrList<int> list(&mem);
    
    list.push_front(806);
    list.push_front(805);
    list.push_front(801);
    
    auto it = list.begin();
    EXPECT_EQ(*it, 801);
    ++it;
    EXPECT_EQ(*it, 805);
    ++it;
    EXPECT_EQ(*it, 806);
}

TEST(IteratorTest, ForwardIteration) {
    FixedBlockMemoryResource mem(1024);
    PmrList<int> list(&mem);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it; 
    EXPECT_EQ(*it, 2);
    it++; 
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(IteratorTest, BackwardIteration) {
    FixedBlockMemoryResource mem(1024);
    PmrList<int> list(&mem);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    auto it = list.rbegin();
    EXPECT_EQ(*it, 3);
    --it;  
    EXPECT_EQ(*it, 2);
    it--; 
    EXPECT_EQ(*it, 1);
}

TEST(IteratorTest, IteratorComparison) {
    FixedBlockMemoryResource mem(1024);
    PmrList<int> list(&mem);
    list.push_back(1);
    list.push_back(2);
    
    auto it1 = list.begin();
    auto it2 = list.begin();
    auto end = list.end();
    
    EXPECT_EQ(it1, it2);
    EXPECT_NE(it1, end);
    
    ++it1;
    EXPECT_NE(it1, it2);
}

TEST(IteratorTest, ArrowOperator) {
    struct Point { int x, y; };
    FixedBlockMemoryResource mem(1024);
    PmrList<Point> list(&mem);
    list.push_back({10, 20});
    
    auto it = list.begin();
    EXPECT_EQ(it->x, 10);
    EXPECT_EQ(it->y, 20);
}

struct Student {
    std::string name;
    int group;
    double mark;
};

TEST(ComplexTypesTest, StructWithStrings) {
    FixedBlockMemoryResource mem(2048);
    PmrList<Student> list(&mem);
    
    list.push_back({"Alex", 214, 4.0});
    list.push_back({"Matvey", 216, 4.9});
    
    auto it = list.begin();
    EXPECT_EQ(it->name, "Alex");
    EXPECT_EQ(it->group, 214);
    ++it;
    EXPECT_EQ(it->name, "Matvey");
    EXPECT_EQ(it->group, 216);
}

TEST(ComplexTypesTest, StringManipulation) {
    FixedBlockMemoryResource mem(2048);
    PmrList<std::string> list(&mem);
    
    list.push_back("8");
    list.push_back(">");
    list.push_back("3");
    
    auto it = list.begin();
    *it = "NOVOE";
    EXPECT_EQ(*list.begin(), "NOVOE");
}