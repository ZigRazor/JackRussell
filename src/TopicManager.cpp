#include "TopicManager.h"

#include "AbstractSubscriber.h"
namespace DogBreeds {
namespace JackRussell {
TopicManager &TopicManager::getInstance() {
  static TopicManager instance;
  return instance;
}

ResultCode TopicManager::deleteTopic(const std::string &topic_name) {
  std::lock_guard<std::mutex> lock(m_topicsMutex);
  if (m_topics.find(topic_name) == m_topics.end()) {
    // Topic not present
    return ResultCode::TOPIC_NOT_FOUND;
  }
  // delete Topic
  m_topics.erase(topic_name);
  return ResultCode::OK;
}

ResultCode TopicManager::subscribeToTopic(
    std::shared_ptr<AbstractSubscriber> sub, const std::string &topic_name) {
  std::lock_guard<std::mutex> lock(m_topicsMutex);
  auto topic = m_topics.find(topic_name);
  if (topic == m_topics.end()) {
    // Topic not found
    return ResultCode::TOPIC_NOT_FOUND;
  }
  return topic->second->addSubscriber(sub);
}
ResultCode TopicManager::unsubscribeFromTopic(
    std::shared_ptr<AbstractSubscriber> sub, const std::string &topic_name) {
  std::lock_guard<std::mutex> lock(m_topicsMutex);
  auto topic = m_topics.find(topic_name);
  if (topic == m_topics.end()) {
    // Topic not found
    return ResultCode::TOPIC_NOT_FOUND;
  }
  return topic->second->removeSubscriber(sub);
}
}  // namespace JackRussell
}  // namespace DogBreeds
