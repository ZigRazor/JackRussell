#include <gtest/gtest.h>

#include "MockSubscriber.h"
#include "ResultCode.h"
#include "Topic.hpp"
#include "TopicManager.h"

using namespace DogBreeds::JackRussell;

class TopicManagerTest : public ::testing::Test {};

TEST_F(TopicManagerTest, CreateTopic) {
  EXPECT_EQ(TopicManager::getInstance().createTopic<int>("test_topic"),
            ResultCode::OK);
}

TEST_F(TopicManagerTest, CreateExistingTopic) {
  TopicManager::getInstance().createTopic<int>("test_topic");
  EXPECT_EQ(TopicManager::getInstance().createTopic<int>("test_topic"),
            ResultCode::TOPIC_ALREDY_EXIST);
}

TEST_F(TopicManagerTest, DeleteTopic) {
  TopicManager::getInstance().createTopic<int>("test_topic");
  EXPECT_EQ(TopicManager::getInstance().deleteTopic("test_topic"),
            ResultCode::OK);
}

TEST_F(TopicManagerTest, SubscribeToTopic) {
  TopicManager::getInstance().createTopic<int>("test_topic");
  auto subscriber = std::make_shared<MockSubscriber<int>>("test_subscriber");
  EXPECT_EQ(
      TopicManager::getInstance().subscribeToTopic(subscriber, "test_topic"),
      ResultCode::OK);
}

TEST_F(TopicManagerTest, UnsubscribeFromTopic) {
  TopicManager::getInstance().createTopic<int>("test_topic");
  auto subscriber = std::make_shared<MockSubscriber<int>>("test_subscriber");
  TopicManager::getInstance().subscribeToTopic(subscriber, "test_topic");
  EXPECT_EQ(TopicManager::getInstance().unsubscribeFromTopic(subscriber,
                                                             "test_topic"),
            ResultCode::OK);
}

TEST_F(TopicManagerTest, PublishToTopic) {
  TopicManager::getInstance().createTopic<int>("test_topic");
  auto subscriber = std::make_shared<MockSubscriber<int>>("test_subscriber");
  TopicManager::getInstance().subscribeToTopic(subscriber, "test_topic");

  auto message = std::make_shared<int>(42);
  EXPECT_CALL(*subscriber, onMessage(message)).Times(1);

  EXPECT_EQ(TopicManager::getInstance().publishToTopic("test_topic", message),
            ResultCode::OK);
}
