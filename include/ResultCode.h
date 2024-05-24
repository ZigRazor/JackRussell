/**
 * @file ResultCode.h
 * @author ZigRazor (zigrazor@gmail.com)
 * @brief Result Code Enumeration
 * @version 0.1
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DOGBREEDS_JACKRUSSELL_RESULTCODE_H
#define DOGBREEDS_JACKRUSSELL_RESULTCODE_H

namespace DogBreeds {
namespace JackRussell {
/**
 * @brief Result Code Enum Class
 *
 */
enum class ResultCode {
  /**
   * @brief Ok
   *
   */
  OK,
  /**
   * @brief Generic Error
   *
   */
  GENERIC_ERROR,
  /**
   * @brief Topic Not Found Error
   *
   */
  TOPIC_NOT_FOUND,
  /**
   * @brief Topic Already Exist Error
   *
   */
  TOPIC_ALREDY_EXIST,
  /**
   * @brief Subscriber Not Found in Topic Error
   *
   */
  SUBSCRIBER_NOT_FOUND_IN_TOPIC,
  /**
   * @brief Subscriber Is Already Subscribed To Topic Error
   *
   */
  SUBSCRIBER_IS_ALREADY_SUBSCRIBED_TO_TOPIC
};
}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_RESULTCODE_H