#include "gtest/gtest.h"
#include <gmock/gmock.h>  // Brings in gMock.
#include "../include/Awards.h"

using awards::RankList;
using awards::AwardCeremonyActions;


class MockAwards : public AwardCeremonyActions {
 public:
  MOCK_METHOD(void, playAnthem, (), (override));
  MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
  MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
  MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
  MOCK_METHOD(void, awardGold, (std::string recipient), (override));
};


class RankList {
public:
  virtual std::string getNext() = 0;
};

class RankListStub: public RankList {
public:

  virtual std::string getNext() {

    if (currNameIndex < namesList.size()) {

        currNameIndex = (1 + currNameIndex);

    }

    return (namesList[currNameIndex]);

  }


private:

    std::vector<std::string> namesList = {"Alan", "Aaron", "Brian", "John"};

    int currNameIndex = -1;
};

