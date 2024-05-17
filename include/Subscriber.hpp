#ifndef DOGBREEDS_JACKRUSSELL_SUBSCRIBER_H
#define DOGBREEDS_JACKRUSSELL_SUBSCRIBER_H

#include <memory>

#include "AbstractSubscriber.h"
#include "ResultCode.h"

namespace DogBreeds {
namespace JackRussell {
template <typename T>
class Subscriber : public AbstractSubscriber {
 private:
 public:
  Subscriber() : AbstractSubscriber() {}
  virtual ~Subscriber() = default;
  virtual void onMessage(std::shared_ptr<T> message) const;
};
}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_SUBSCRIBER_H