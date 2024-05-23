#include <unistd.h>

#include <iostream>
#include <memory>

#include "Subscriber.hpp"
#include "TopicManager.h"

using namespace DogBreeds;

class MyIntSub : public JackRussell::Subscriber<int> {
 public:
  MyIntSub() : DogBreeds::JackRussell::Subscriber<int>("MyIntSub") {}
  virtual ~MyIntSub() = default;

  void onMessage(std::shared_ptr<int> message) override {
    std::cout << "Received: " << *message << std::endl;
  }
};

void exampleSinglePublish() {
  const std::string &topic_name = "intTopic";
  JackRussell::TopicManager::getInstance().createTopic<int>(topic_name);
  auto sub = std::make_shared<MyIntSub>();
  JackRussell::TopicManager::getInstance().subscribeToTopic(sub, topic_name);
  JackRussell::TopicManager::getInstance().publishToTopic(
      topic_name, std::make_shared<int>(1));
  sleep(1);
}

void example1000Publish() {
  const std::string &topic_name = "intTopic";
  JackRussell::TopicManager::getInstance().createTopic<int>(topic_name);
  auto sub = std::make_shared<MyIntSub>();
  JackRussell::TopicManager::getInstance().subscribeToTopic(sub, topic_name);
  for (int i = 0; i < 1000; i++) {
    JackRussell::TopicManager::getInstance().publishToTopic(
        topic_name, std::make_shared<int>(i));
  }
  sleep(1);
}

int main() {
  exampleSinglePublish();
  example1000Publish();
  return 0;
}
