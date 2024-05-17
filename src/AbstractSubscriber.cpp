#include "AbstractSubscriber.h"

#include "TopicManager.h"

namespace DogBreeds {
namespace JackRussell {

AbstractSubscriber::AbstractSubscriber(const std::string& name)
    : m_name(name) {}
}  // namespace JackRussell
}  // namespace DogBreeds