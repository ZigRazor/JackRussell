#ifndef DOGBREEDS_JACKRUSSELL_ABSTRACTSUBSCRIBER_H
#define DOGBREEDS_JACKRUSSELL_ABSTRACTSUBSCRIBER_H

#include <memory>

#include "ResultCode.h"

namespace DogBreeds {
namespace JackRussell {
class AbstractSubscriber {
 public:
  AbstractSubscriber();
  virtual ~AbstractSubscriber() = default;

  // ResultCode subscribe(std::string topic_name);
  // ResultCode unsubscribe(std::string topic_name);
};
}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_ABSTRACTSUBSCRIBER_H