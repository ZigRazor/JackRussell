#ifndef DOGBREEDS_JACKRUSSELL_TOPIC_H
#define DOGBREEDS_JACKRUSSELL_TOPIC_H

#include <functional>
#include <memory>
#include <string>
#include <list>

#include "AbstractTopic.h"
#include "Subscriber.h"
#include "AsyncQueueProcessor.hpp"
#include "ConcurrentQueue.hpp"

namespace DogBreeds{
    namespace JackRussell{
        class TopicManager;
        template<typename T>
        class Topic : public AbstractTopic{
            friend class TopicManager;
            private:
                Labrador::ConcurrentQueue<std::shared_ptr<T>> queue;
                Labrador::AsyncQueueProcessor<std::shared_ptr<T>> queueProcessor;
                Topic(std::string topic_name) : AbstractTopic(topic_name), queue(){
                    std::function<void(std::shared_ptr<T>)> func = &Subscriber::onMessage;
                    queueProcessor(queue, func);
                }
                
            public:                
                virtual ~Topic() = default;

                ResultCode publish(std::shared_ptr<T> message){
                    queue.enqueue(message);
                }
                
            
        };
    }
}

#endif // DOGBREEDS_JACKRUSSELL_TOPIC_H