#ifndef TEST_MOCKSUBSCRIBER_H_
#define TEST_MOCKSUBSCRIBER_H_

#include <gmock/gmock.h>

#include "Subscriber.hpp"

namespace DogBreeds {
namespace JackRussell {

template <typename T>
class MockSubscriber : public Subscriber<T> {
 public:
  MockSubscriber(const std::string &name) : Subscriber<T>(name) {}
  MOCK_METHOD(void, onMessage, (std::shared_ptr<T> message), (override));
};

}  // namespace JackRussell
}  // namespace DogBreeds

#endif /* TEST_MOCKSUBSCRIBER_H_ */
