/**
 * @file AbstractSubscriber.h
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief Abstract Subscriber
 * @version 0.1
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_JACKRUSSELL_ABSTRACTSUBSCRIBER_H
#define DOGBREEDS_JACKRUSSELL_ABSTRACTSUBSCRIBER_H

#include <memory>

#include "ResultCode.h"

namespace DogBreeds {
namespace JackRussell {
/**
 * @brief Abstract Subscriber Class
 *
 */
class AbstractSubscriber {
 private:
  /**
   * @brief Name of the Subscriber
   *
   */
  std::string m_name;

 public:
  /**
   * @brief Construct a new Abstract Subscriber object
   *
   * @param name the name of the subscriber
   */
  AbstractSubscriber(const std::string& name);
  /**
   * @brief Destroy the Abstract Subscriber object
   *
   */
  virtual ~AbstractSubscriber() = default;
};
}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_ABSTRACTSUBSCRIBER_H