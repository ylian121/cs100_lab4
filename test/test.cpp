#include "gtest/gtest.h"
#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;

TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(), 9);
}

TEST(TriangleTests, testPerimeter2) {
    Triangle *aTriangle = new Triangle(-3,-3,-3);
    EXPECT_EQ (aTriangle->getPerimeter(), 0);
}

TEST(TriangleTests, testPerimeter3) {
    Triangle *aTriangle = new Triangle(1.5, 3, 3);
    EXPECT_EQ (aTriangle->getPerimeter(), 7.5);
}

TEST(TriangleTests, testPerimeter4) {
    Triangle *aTriangle = new Triangle(0, 0, 0);
    EXPECT_EQ (aTriangle->getPerimeter(), 0);
}

TEST(TriangleTests, testPerimeterE) {
    EXPECT_DEATH (Triangle *aTriangle = new Triangle(-5555.11, 0, 1), "ERROR: invalid input");
}

TEST(TriangleTests, isIso) {
    Triangle *aTriangle = new Triangle(1,1,1);
    EXPECT_TRUE (aTriangle->isIsosceles());
}

TEST(TriangleTests, isEq) {
    Triangle *aTriangle = new Triangle(5,3,10);
    EXPECT_FALSE (aTriangle->isEquilateral());
}

TEST(TriangleTests, testArea) {
    Triangle *aTriangle = new Triangle(5,1,10);
    EXPECT_DOUBLE_EQ (aTriangle->getArea(), 2);
}

TEST(TriangleTests, testPerimeterT) {
    Triangle *aTriangle = new Triangle(5,3,10);
    aTriangle->getPerimeter();
    EXPECT_NO_THROW(aTriangle->getPerimeter());
}

TEST(HailstoneTests, testInputZero) {
    
    EXPECT_FALSE (satisfiesHailstone(0));
}

TEST(HailstoneTests, testInputOne) {
    
    EXPECT_TRUE (satisfiesHailstone(1));

}

TEST(HailstoneTests, testInputEven) {
    
    EXPECT_TRUE (satisfiesHailstone(4));

}

TEST(HailstoneTests, testInputOdd) {
    
    EXPECT_TRUE (satisfiesHailstone(5));

}