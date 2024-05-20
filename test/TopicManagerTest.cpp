// test_topic.cpp
#include <gtest/gtest.h>
#include "MockSubscriber.h"
#include "Topic.hpp"
#include "TopicManager.h"
#include "ResultCode.h"

using namespace DogBreeds::JackRussell;


class TopicManagerTest : public ::testing::Test {
 protected:
  TopicManager &manager = TopicManager::getInstance();
  void SetUp() override {
    manager = TopicManager::getInstance();
  }
};

TEST_F(TopicManagerTest, CreateTopic) {
  EXPECT_EQ(manager.createTopic<int>("test_topic"), ResultCode::OK);
}

TEST_F(TopicManagerTest, CreateExistingTopic) {
  manager.createTopic<int>("test_topic");
  EXPECT_EQ(manager.createTopic<int>("test_topic"), ResultCode::TOPIC_ALREDY_EXIST);
}

TEST_F(TopicManagerTest, DeleteTopic) {
  manager.createTopic<int>("test_topic");
  EXPECT_EQ(manager.deleteTopic("test_topic"), ResultCode::OK);
}

TEST_F(TopicManagerTest, SubscribeToTopic) {
  manager.createTopic<int>("test_topic");
  auto subscriber = std::make_shared<MockSubscriber<int>>("test_subscriber");
  EXPECT_EQ(manager.subscribeToTopic(subscriber, "test_topic"), ResultCode::OK);
}

TEST_F(TopicManagerTest, UnsubscribeFromTopic) {
  manager.createTopic<int>("test_topic");
  auto subscriber = std::make_shared<MockSubscriber<int>>("test_subscriber");
  manager.subscribeToTopic(subscriber, "test_topic");
  EXPECT_EQ(manager.unsubscribeFromTopic(subscriber, "test_topic"), ResultCode::OK);
}

TEST_F(TopicManagerTest, PublishToTopic) {
  manager.createTopic<int>("test_topic");
  auto subscriber = std::make_shared<MockSubscriber<int>>("test_subscriber");
  manager.subscribeToTopic(subscriber, "test_topic");

  auto message = std::make_shared<int>(42);
  EXPECT_CALL(*subscriber, onMessage(message)).Times(1);

  EXPECT_EQ(manager.publishToTopic("test_topic", message), ResultCode::OK);
}


