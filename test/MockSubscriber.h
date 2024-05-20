/*
 * MockSubscriber.h
 *
 *  Created on: 20 mag 2024
 *      Author: BOTTICCIM
 */

#ifndef TEST_MOCKSUBSCRIBER_H_
#define TEST_MOCKSUBSCRIBER_H_

#include "Subscriber.hpp"
#include <gmock/gmock.h>

namespace DogBreeds {
namespace JackRussell {

template <typename T>
class MockSubscriber : public Subscriber<T> {
 public:
  MockSubscriber(const std::string &name) : Subscriber<T>(name) {}
  MOCK_METHOD(void, onMessage, (std::shared_ptr<T> message), (const, override));
};

}  // namespace JackRussell
}  // namespace DogBreeds



#endif /* TEST_MOCKSUBSCRIBER_H_ */
