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
