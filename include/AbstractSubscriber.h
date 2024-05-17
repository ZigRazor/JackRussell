#ifndef DOGBREEDS_JACKRUSSELL_ABSTRACTSUBSCRIBER_H
#define DOGBREEDS_JACKRUSSELL_ABSTRACTSUBSCRIBER_H

#include <memory>

#include "ResultCode.h"

namespace DogBreeds {
namespace JackRussell {
class AbstractSubscriber {
 private:
  std::string m_name;

 public:
  AbstractSubscriber(const std::string& name);
  virtual ~AbstractSubscriber() = default;
};
}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_ABSTRACTSUBSCRIBER_H