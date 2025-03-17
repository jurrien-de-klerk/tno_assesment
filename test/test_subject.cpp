

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <Subject.h>

using ::testing::AllOf;
using ::testing::Field;

class MockIntObserver : public IObserver<int> {
public:
  MOCK_METHOD(void, notify, (const int &message), (override));
};

struct ComplexMessage {
  int i;
  float f;
};

class MockComplexObserver : public IObserver<ComplexMessage> {
public:
  MOCK_METHOD(void, notify, (const ComplexMessage &message), (override));
};

TEST(TestSubject, SubjectInIsolation) {
  Subject<int> s;
  s.doNotify(0);

  // Nothing is attached, so no error should occur.
  SUCCEED();
}

TEST(TestSubject, SingleIntObserver) {
  Subject<int> s;
  auto observer = std::make_shared<MockIntObserver>();
  s.attach(observer);

  EXPECT_CALL(*observer, notify(1));
  s.doNotify(1);
}

TEST(TestSubject, MultipleIntObserver) {
  Subject<int> s;
  auto observer1 = std::make_shared<MockIntObserver>();
  auto observer2 = std::make_shared<MockIntObserver>();
  s.attach(observer1);
  s.attach(observer2);

  EXPECT_CALL(*observer1, notify(1));
  EXPECT_CALL(*observer2, notify(1));
  s.doNotify(1);
}

TEST(TestSubject, ComplexObserver) {
  Subject<ComplexMessage> s;
  auto observer = std::make_shared<MockComplexObserver>();
  s.attach(observer);

  ComplexMessage msg = {0, 1.0};

  EXPECT_CALL(*observer, notify(AllOf(Field(&ComplexMessage::i, 0),
                                      Field(&ComplexMessage::f, 1.0))));
  s.doNotify(msg);
}
