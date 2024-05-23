#include <unistd.h>

#include <iostream>
#include <memory>
#include <sstream>

#include "Subscriber.hpp"
#include "TopicManager.h"

using namespace DogBreeds;

class MyIntSub : public JackRussell::Subscriber<int> {
 public:
  MyIntSub() : DogBreeds::JackRussell::Subscriber<int>("MyIntSubS") {}
  virtual ~MyIntSub() = default;

  void onMessage(std::shared_ptr<int> message) override {
    std::cout << "Received: " << *message << std::endl;
  }
};

class MyStringSub : public JackRussell::Subscriber<std::string> {
 public:
  MyStringSub()
      : DogBreeds::JackRussell::Subscriber<std::string>("MyStringSub") {}
  virtual ~MyStringSub() = default;

  void onMessage(std::shared_ptr<std::string> message) override {
    std::cout << "Received: " << *message << std::endl;
  }
};

void exampleSinglePublishMultipleTopic() {
  const std::string &int_topic_name = "intTopic";
  JackRussell::TopicManager::getInstance().createTopic<int>(int_topic_name);
  auto intSub = std::make_shared<MyIntSub>();
  JackRussell::TopicManager::getInstance().subscribeToTopic(intSub,
                                                            int_topic_name);
  const std::string &str_topic_name = "strTopic";
  JackRussell::TopicManager::getInstance().createTopic<int>(str_topic_name);
  auto strSub = std::make_shared<MyStringSub>();
  JackRussell::TopicManager::getInstance().subscribeToTopic(strSub,
                                                            str_topic_name);
  JackRussell::TopicManager::getInstance().publishToTopic(
      int_topic_name, std::make_shared<int>(1));
  JackRussell::TopicManager::getInstance().publishToTopic(
      str_topic_name, std::make_shared<std::string>("Test"));

  sleep(1);
}

void example1000PublishMultipleTopic() {
  const std::string &int_topic_name = "intTopic";
  JackRussell::TopicManager::getInstance().createTopic<int>(int_topic_name);
  auto intSub = std::make_shared<MyIntSub>();
  JackRussell::TopicManager::getInstance().subscribeToTopic(intSub,
                                                            int_topic_name);
  const std::string &str_topic_name = "strTopic";
  JackRussell::TopicManager::getInstance().createTopic<int>(str_topic_name);
  auto strSub = std::make_shared<MyStringSub>();
  JackRussell::TopicManager::getInstance().subscribeToTopic(strSub,
                                                            str_topic_name);
  for (int i = 0; i < 1000; i++) {
    JackRussell::TopicManager::getInstance().publishToTopic(
        int_topic_name, std::make_shared<int>(i));
    std::stringstream ss;
    ss << "Test" << i;
    JackRussell::TopicManager::getInstance().publishToTopic(
        str_topic_name, std::make_shared<std::string>(ss.str()));
  }
  sleep(1);
}

int main() {
  exampleSinglePublishMultipleTopic();
  example1000PublishMultipleTopic();
  return 0;
}
