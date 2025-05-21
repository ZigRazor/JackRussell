/**
 * @file SyncTopic.hpp
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief The SyncTopic
 * @version 0.1
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_JACKRUSSELL_SYNCTOPIC_H
#define DOGBREEDS_JACKRUSSELL_SYNCTOPIC_H

#include <functional>
#include <future>
#include <list>
#include <memory>
#include <string>

#include "AbstractTopic.h"
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
class SyncTopic : public AbstractTopic {
  friend class TopicManager;

 private:
  /**
   * @brief Construct a new Topic object
   *
   * @param topic_name the Topic Name
   */
  SyncTopic(std::string topic_name) : AbstractTopic(topic_name) {}

 public:
  /**
   * @brief Destroy the Topic object
   *
   */
  virtual ~SyncTopic() = default;

  /**
   * @brief publish a message on topic queue
   *
   * @param message the message to publish
   * @return ResultCode OK if all ok
   */
  ResultCode publish(std::shared_ptr<T> message) {
    std::lock_guard<std::mutex> lock(m_subscriberListMutex);
    for (auto& subscriber : m_subscriberList) {
      auto sub = std::dynamic_pointer_cast<Subscriber<T>>(subscriber);
      if (sub) {
        sub->onMessage(message);
      }
    }
    return ResultCode::OK;
  }
};

}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_SYNCTOPIC_H