#ifndef DOGBREEDS_JACKRUSSELL_TOPIC_H
#define DOGBREEDS_JACKRUSSELL_TOPIC_H

#include <functional>
#include <future>
#include <list>
#include <memory>
#include <string>

#include "AbstractTopic.h"
#include "ConcurrentQueue.hpp"
#include "QueueProcessor.hpp"
#include "ResultCode.h"
#include "Subscriber.hpp"

namespace DogBreeds {
namespace JackRussell {
class TopicManager;
template <typename T>
class Topic : public AbstractTopic {
  friend class TopicManager;

 private:
  std::shared_ptr<Labrador::ConcurrentQueue<std::shared_ptr<T>>> queue;
  std::unique_ptr<Labrador::QueueProcessor<std::shared_ptr<T>>> queueProcessor;
  Topic(std::string topic_name) : AbstractTopic(topic_name) {
    queue = std::make_shared<Labrador::ConcurrentQueue<std::shared_ptr<T>>>();
    queueProcessor =
        std::make_unique<Labrador::QueueProcessor<std::shared_ptr<T>>>(
            queue, [this](std::shared_ptr<T> value) {
              std::lock_guard<std::mutex> lock(m_subscriberListMutex);
              for (auto sub : m_subscriberList) {
                auto future = std::async(
                    std::launch::async, &Subscriber<T>::onMessage,
                    static_pointer_cast<Subscriber<T>>(sub).get(), value);
              }
            });
  }

 public:
  virtual ~Topic() = default;

  ResultCode publish(std::shared_ptr<T> message) {
    queue->enqueue(message);
    return ResultCode::OK;
  }
};

}  // namespace JackRussell
}  // namespace DogBreeds

#endif  // DOGBREEDS_JACKRUSSELL_TOPIC_H