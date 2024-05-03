#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;


TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(), 9);
}

TEST(TriangleTests, testPerimeter2) {
    Triangle *aTriangle = new Triangle(10,10,5);
    EXPECT_EQ (aTriangle->getPerimeter(), 25);
}

TEST(TriangleTests, testArea1) {
    Triangle *aTriangle = new Triangle(15,12,6);
    EXPECT_EQ (aTriangle->getArea(), 34.2);
}

TEST(TriangleTests, testKind1) {
    Triangle *aTriangle = new Triangle(15,15,15);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::EQUILATERAL);
}