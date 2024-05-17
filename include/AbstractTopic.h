#ifndef DOGBREEDS_JACKRUSSELL_ABSTRACTTOPIC_H
#define DOGBREEDS_JACKRUSSELL_ABSTRACTTOPIC_H

#include <list>
#include <mutex>
#include <string>

#include "AbstractSubscriber.h"
#include "AsyncQueueProcessor.hpp"

namespace DogBreeds {
namespace JackRussell {
class TopicManager;
class AbstractTopic {
  friend class TopicManager;

 protected:
  std::string m_name;
  std::mutex m_subscriberListMutex;
  std::list<std::shared_ptr<AbstractSubscriber>> m_subscriberList;

  AbstractTopic(std::string topic_name);

 public:
  virtual ~AbstractTopic() = default;

  const std::string& getName() const;
  ResultCode addSubscriber(std::shared_ptr<AbstractSubscriber> sub);
  ResultCode removeSubscriber(std::shared_ptr<AbstractSubscriber> sub);
  // template<typename T>
  // ResultCode publish(std::shared_ptr<T> message);
};
}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_ABSTRACTTOPIC_H