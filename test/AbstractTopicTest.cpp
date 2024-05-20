#include <gtest/gtest.h>

#include "AbstractTopic.h"
#include "MockSubscriber.h"
#include "MockTopic.h"
#include "ResultCode.h"

using namespace DogBreeds::JackRussell;

class AbstractTopicTest : public ::testing::Test {
 protected:
  std::shared_ptr<AbstractTopic> topic;
  void SetUp() override { topic = std::make_shared<MockTopic>("test_topic"); }
};

TEST_F(AbstractTopicTest, AddSubscriber) {
  auto subscriber = std::make_shared<MockSubscriber<int>>("test_subscriber");
  EXPECT_EQ(topic->addSubscriber(subscriber), ResultCode::OK);
}

TEST_F(AbstractTopicTest, RemoveSubscriber) {
  auto subscriber = std::make_shared<MockSubscriber<int>>("test_subscriber");
  topic->addSubscriber(subscriber);
  EXPECT_EQ(topic->removeSubscriber(subscriber), ResultCode::OK);
}

TEST_F(AbstractTopicTest, GetName) {
  EXPECT_EQ(topic->getName(), "test_topic");
}
