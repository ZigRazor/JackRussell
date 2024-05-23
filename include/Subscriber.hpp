/**
 * @file Subscriber.hpp
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief Subscriber
 * @version 0.1
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_JACKRUSSELL_SUBSCRIBER_H
#define DOGBREEDS_JACKRUSSELL_SUBSCRIBER_H

#include <memory>

#include "AbstractSubscriber.h"
#include "ResultCode.h"

namespace DogBreeds {
namespace JackRussell {
/**
 * @brief Subscriber Class
 *
 * @tparam T the type of the Subscriber
 */
template <typename T>
class Subscriber : public AbstractSubscriber {
 private:
 public:
  /**
   * @brief Construct a new Subscriber object
   *
   * @param name the subscriber name
   */
  Subscriber(const std::string& name) : AbstractSubscriber(name) {}
  /**
   * @brief Destroy the Subscriber object
   *
   */
  virtual ~Subscriber() = default;
  /**
   * @brief Manage the received Callback when a message is sent
   *
   * this virtual function must be overriden by the derived class
   *
   * @param message the incoming message
   */
  virtual void onMessage(std::shared_ptr<T> message) = 0;
};
}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_SUBSCRIBER_H