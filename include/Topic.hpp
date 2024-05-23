/**
 * @file Topic.hpp
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief The Topic
 * @version 0.1
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_JACKRUSSELL_TOPIC_H
#define DOGBREEDS_JACKRUSSELL_TOPIC_H

#include <functional>
#include <future>
#include <list>
#include <memory>
#include <string>

#include "AbstractTopic.h"
#include "ConcurrentQueue.hpp"
#include "QueueProcessor.hpp"
#include "ResultCode.h"
#include "Subscriber.hpp"

namespace DogBreeds {
namespace JackRussell {
// Foward Declaration
class TopicManager;
/**
 * @brief The Topic Class
 *
 * @tparam T The Topic Type
 */
template <typename T>
class Topic : public AbstractTopic {
  friend class TopicManager;

 private:
  /**
   * @brief the Queue where the message are published
   *
   */
  std::shared_ptr<Labrador::ConcurrentQueue<std::shared_ptr<T>>> queue;
  /**
   * @brief the Queue processor that process the message published
   *
   */
  std::unique_ptr<Labrador::QueueProcessor<std::shared_ptr<T>>> queueProcessor;
  /**
   * @brief Construct a new Topic object
   *
   * @param topic_name the Topic Name
   */
  Topic(std::string topic_name) : AbstractTopic(topic_name) {
    queue = std::make_shared<Labrador::ConcurrentQueue<std::shared_ptr<T>>>();
    queueProcessor =
        std::make_unique<Labrador::QueueProcessor<std::shared_ptr<T>>>(
            queue, [this](std::shared_ptr<T> value) {
              std::lock_guard<std::mutex> lock(m_subscriberListMutex);
              for (auto sub : m_subscriberList) {
                auto future = std::async(
                    std::launch::async, &Subscriber<T>::onMessage,
                    static_pointer_cast<Subscriber<T>>(sub).get(), value);
              }
            });
  }

 public:
  /**
   * @brief Destroy the Topic object
   *
   */
  virtual ~Topic() = default;

  /**
   * @brief publish a message on topic queue
   *
   * @param message the message to publish
   * @return ResultCode OK if all ok
   */
  ResultCode publish(std::shared_ptr<T> message) {
    queue->enqueue(message);
    return ResultCode::OK;
  }
};

}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_TOPIC_H