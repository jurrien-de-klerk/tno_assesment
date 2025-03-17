
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <IFF.h>

using ::testing::AllOf;
using ::testing::Field;
using ::testing::Test;

class MockObserver : public IObserver<EntityType> {
public:
  MOCK_METHOD(void, notify, (const EntityType &message), (override));
};

class TestIFF : public Test {
protected:
  void SetUp() override {
    observer_ = std::make_shared<MockObserver>();
    iff_.attach(observer_);
  }

  std::shared_ptr<MockObserver> observer_;
  IFF iff_;
};

TEST_F(TestIFF, emptyMsg) {
  EXPECT_CALL(*observer_, notify(EntityType::Friend));
  iff_.notify({});
}

TEST_F(TestIFF, singleOddNumber) {
  EXPECT_CALL(*observer_, notify(EntityType::Foe));
  iff_.notify({1});
}

TEST_F(TestIFF, singleEvenNumber) {
  EXPECT_CALL(*observer_, notify(EntityType::Friend));
  iff_.notify({2});
}

TEST_F(TestIFF, moreOddNumber) {
  EXPECT_CALL(*observer_, notify(EntityType::Foe));
  iff_.notify({1, 2, 1});
}

TEST_F(TestIFF, moreEvenNumber) {
  EXPECT_CALL(*observer_, notify(EntityType::Friend));
  iff_.notify({2, 1, 2});
}
