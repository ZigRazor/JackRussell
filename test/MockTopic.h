#ifndef TEST_MOCKTOPIC_H_
#define TEST_MOCKTOPIC_H_

#include <gmock/gmock.h>

#include "AbstractTopic.h"

namespace DogBreeds {
namespace JackRussell {

class MockTopic : public AbstractTopic {
 public:
  MockTopic(const std::string &name) : AbstractTopic(name) {}
};

}  // namespace JackRussell
}  // namespace DogBreeds

#endif /* TEST_MOCKTOPIC_H_ */
