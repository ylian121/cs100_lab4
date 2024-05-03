/*
    TRIANGLE TESTS
*/

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

TEST(TriangleTests, testDeath1) {
    EXPECT_DEATH (Triangle *aTriangle = new Triangle(0.9,-0.1,0.7), "Does not satisfy triangle inequality");
}

TEST(TriangleTests, testKind2) {
    Triangle *aTriangle = new Triangle(10,8,8);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::ISOSCELES);
}

TEST(TriangleTests, testThrow1) {
    Triangle *aTriangle = new Triangle(10,8,8);
    EXPECT_NO_THROW (aTriangle->getKind());
}

TEST(TriangleTests, testKind3) {
    Triangle *aTriangle = new Triangle(10,5,8);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::SCALENE);
}

/*
    HAILSTONE TESTS
*/

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

/*
    AWARDS TESTS
*/

#include "gtest/gtest.h"
#include <gmock/gmock.h>  // Brings in gMock.
#include "../include/Awards.h"

using awards::RankList;
using awards::AwardCeremonyActions;
using ::testing::InSequence;


class MockAwards : public AwardCeremonyActions {
 public:
  MOCK_METHOD(void, playAnthem, (), (override));
  MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
  MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
  MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
  MOCK_METHOD(void, awardGold, (std::string recipient), (override));
};


class RankListStub: public RankList {
public:

  virtual std::string getNext() {

    if (currNameIndex < namesList.size()) {

        // currNameIndex = (1 + currNameIndex);
        return (namesList.at(currNameIndex++));

    }
    else{
        return "";
    }

  }


private:

    std::vector<std::string> namesList = {"Alan", "Aaron", "Brian", "John"};

    int currNameIndex = 0;
};

TEST(AwardsTests, testperformAwardCeremony) {
    
    MockAwards awardCeremony;
    RankListStub rankL;
    {
        
        InSequence seq;
        EXPECT_CALL(awardCeremony, playAnthem());
        EXPECT_CALL(awardCeremony, awardBronze("Alan"));
        EXPECT_CALL(awardCeremony, awardSilver("Aaron"));
        EXPECT_CALL(awardCeremony, awardGold("Brian"));
        EXPECT_CALL(awardCeremony, turnOffTheLightsAndGoHome());


    }
    performAwardCeremony(rankL, awardCeremony);
 }
