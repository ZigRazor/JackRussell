#ifndef DOGBREEDS_JACKRUSSELL_TOPICMANAGER_H
#define DOGBREEDS_JACKRUSSELL_TOPICMANAGER_H

#include <mutex>
#include <unordered_map>

#include "AbstractTopic.h"
#include "ResultCode.h"
#include "Topic.hpp"

namespace DogBreeds {
namespace JackRussell {
class TopicManager {
 private:
  std::mutex m_topicsMutex;
  std::unordered_map<std::string, std::shared_ptr<AbstractTopic>> m_topics;
  TopicManager(){};

  virtual ~TopicManager() = default;

 public:
  static TopicManager &getInstance();

  TopicManager(TopicManager const &) = delete;
  void operator=(TopicManager const &) = delete;

  template <typename T>
  ResultCode createTopic(const std::string &topic_name) {
    std::lock_guard<std::mutex> lock(m_topicsMutex);
    if (m_topics.find(topic_name) != m_topics.end()) {
      // Topic already inserted
      return ResultCode::TOPIC_ALREDY_EXIST;
    }
    // Insert Topic
    m_topics.emplace(topic_name,
                     std::shared_ptr<AbstractTopic>(new Topic<T>(topic_name)));
    return ResultCode::OK;
  }
  ResultCode deleteTopic(const std::string &topic_name);

  ResultCode subscribeToTopic(std::shared_ptr<AbstractSubscriber> sub,
                              const std::string &topic_name);
  ResultCode unsubscribeFromTopic(std::shared_ptr<AbstractSubscriber> sub,
                                  const std::string &topic_name);
  template <typename T>
  ResultCode publishToTopic(const std::string &topic_name,
                            std::shared_ptr<T> message) {
    if (m_topics.contains(topic_name)) {
      static_pointer_cast<Topic<T>>(m_topics.at(topic_name))->publish(message);
      return ResultCode::OK;
    } else {
      return ResultCode::TOPIC_NOT_FOUND;
    }
  }
};
}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_TOPICMANAGER_H