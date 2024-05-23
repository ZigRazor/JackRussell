/**
 * @file AbstractTopic.h
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief Abstract Topic
 * @version 0.1
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_JACKRUSSELL_ABSTRACTTOPIC_H
#define DOGBREEDS_JACKRUSSELL_ABSTRACTTOPIC_H

#include <list>
#include <mutex>
#include <string>

#include "AbstractSubscriber.h"
#include "AsyncQueueProcessor.hpp"

namespace DogBreeds {
namespace JackRussell {
// Foward Declaration
class TopicManager;
/**
 * @brief Abstract Topic Class
 *
 */
class AbstractTopic {
  friend class TopicManager;

 protected:
  /**
   * @brief The Topic Name
   *
   */
  std::string m_name;
  /**
   * @brief Mutex for Subscriber List
   *
   */
  std::mutex m_subscriberListMutex;
  /**
   * @brief Subscriber List
   *
   */
  std::list<std::shared_ptr<AbstractSubscriber>> m_subscriberList;

  /**
   * @brief Construct a new Abstract Topic object
   *
   * @param topic_name the topic name
   */
  AbstractTopic(std::string topic_name);

 public:
  /**
   * @brief Destroy the Abstract Topic object
   *
   */
  virtual ~AbstractTopic() = default;

  /**
   * @brief Get the Name object
   *
   * @return const std::string& The Topic Name
   */
  const std::string& getName() const;
  /**
   * @brief Add Subscriber
   *
   * @param sub the shared_ptr of the Subscriber to add
   * @return ResultCode OK if the subscriber is added,
   * SUBSCRIBER_IS_ALREADY_SUBSCRIBED_TO_TOPIC if the subscriber is already
   * subscribed
   */
  ResultCode addSubscriber(std::shared_ptr<AbstractSubscriber> sub);
  /**
   * @brief Remove Subscriber
   *
   * @param sub the shared_ptr of the Subscriber to Remove
   * @return ResultCode OK if the subscriber is removed,
   * SUBSCRIBER_NOT_FOUND_IN_TOPIC if the subscriber isn't subscribed to the
   * topic
   */
  ResultCode removeSubscriber(std::shared_ptr<AbstractSubscriber> sub);
  // template<typename T>
  // ResultCode publish(std::shared_ptr<T> message);
};
}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_ABSTRACTTOPIC_H