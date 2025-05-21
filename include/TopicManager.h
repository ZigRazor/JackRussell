/**
 * @file TopicManager.h
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief The Topic Manager
 * @version 0.1
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_JACKRUSSELL_TOPICMANAGER_H
#define DOGBREEDS_JACKRUSSELL_TOPICMANAGER_H

#include <mutex>
#include <unordered_map>

#include "AbstractTopic.h"
#include "ResultCode.h"
#include "Topic.hpp"

namespace DogBreeds {
namespace JackRussell {
/**
 * @brief Topic Manager Class
 *
 * This is a singleton class
 */
class TopicManager {
 private:
  /**
   * @brief Mutex for the topics map
   *
   */
  std::mutex m_topicsMutex;
  /**
   * @brief the topics map
   *
   */
  std::unordered_map<std::string, std::shared_ptr<AbstractTopic>> m_topics;
  /**
   * @brief Construct a new Topic Manager object
   *
   */
  TopicManager() {};

  /**
   * @brief Destroy the Topic Manager object
   *
   */
  virtual ~TopicManager() = default;

 public:
  /**
   * @brief Get the Instance object
   *
   * @return TopicManager& the topic manager singleton reference
   */
  static TopicManager &getInstance();

  /**
   * @brief [deleted] Construct a new Topic Manager object
   *
   */
  TopicManager(TopicManager const &) = delete;
  /**
   * @brief @brief [deleted] Assignement Operator
   *
   */
  void operator=(TopicManager const &) = delete;

  /**
   * @brief Create a Topic object
   *
   * @tparam T The Topic Type
   * @param topic_name The Topic Name to Create
   * @return ResultCode OK if all Ok, or TOPIC_ALREDY_EXIST if the topic already
   * exist
   */
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
  /**
   * @brief Create a SyncTopic object
   *
   * @tparam T The Topic Type
   * @param topic_name The Topic Name to Create
   * @return ResultCode OK if all Ok, or TOPIC_ALREDY_EXIST if the topic already
   * exist
   */
  template <typename T>
  ResultCode createSyncTopic(const std::string &topic_name) {
    std::lock_guard<std::mutex> lock(m_topicsMutex);
    if (m_topics.find(topic_name) != m_topics.end()) {
      // Topic already inserted
      return ResultCode::TOPIC_ALREDY_EXIST;
    }
    // Insert Topic
    m_topics.emplace(topic_name, std::shared_ptr<AbstractTopic>(
                                     new SyncTopic<T>(topic_name)));
    return ResultCode::OK;
  }
  /**
   * @brief Delete Topic
   *
   * @param topic_name The Topic Name to delete
   * @return ResultCode OK if all Ok, or TOPIC_NOT_FOUND if not found the
   * specified topic
   */
  ResultCode deleteTopic(const std::string &topic_name);

  /**
   * @brief Subscribe To Topic
   *
   * @param sub the shared_ptr of the subscriber
   * @param topic_name the Topic name in which the subscriber will be subscribed
   * @return ResultCode OK if all Ok, TOPIC_NOT_FOUND if not found the specific
   * topic, SUBSCRIBER_IS_ALREADY_SUBSCRIBED_TO_TOPIC if the subscriber is
   * already subscribed to topic
   */
  ResultCode subscribeToTopic(std::shared_ptr<AbstractSubscriber> sub,
                              const std::string &topic_name);
  /**
   * @brief Unsubscribe From Topic
   *
   * @param sub the shared_ptr of the subscriber
   * @param topic_name the Topic name in which the subscriber will be
   * unsubscribed
   * @return ResultCode OK if all Ok, TOPIC_NOT_FOUND if not found the specific
   * topic, SUBSCRIBER_NOT_FOUND_IN_TOPIC if the subscriber is
   * not subscribed to topic
   */
  ResultCode unsubscribeFromTopic(std::shared_ptr<AbstractSubscriber> sub,
                                  const std::string &topic_name);
  /**
   * @brief Publish message to Topic
   *
   * @tparam T the Message type
   * @param topic_name the topic name
   * @param message the shared_ptr of the message
   * @return ResultCode OK if all Ok, TOPIC_NOT_FOUND if not found the specific
   * topic
   */
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