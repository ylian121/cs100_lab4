#include "gtest/gtest.h"
#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;


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