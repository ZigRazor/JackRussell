#ifndef DOGBREEDS_JACKRUSSELL_ABSTRACTTOPIC_H
#define DOGBREEDS_JACKRUSSELL_ABSTRACTTOPIC_H

#include <string>
#include <list>

#include "Subscriber.h"
#include "AsyncQueueProcessor.hpp"

namespace DogBreeds{
    namespace JackRussell{
        class TopicManager;
        class AbstractTopic{
            friend class TopicManager;
            protected:
                std::string m_name;
                std::list<std::shared_ptr<Subscriber>> m_subscriberList;

                AbstractTopic(std::string topic_name);
                
            public:                
                virtual ~AbstractTopic() = default;

                const std::string& getName() const;
                ResultCode addSubscriber(std::shared_ptr<Subscriber> sub);
                ResultCode removeSubscriber(std::shared_ptr<Subscriber> sub);
                template<typename T>
                ResultCode publish(std::shared_ptr<T> message);
                
            
        };
    }
}

#endif // DOGBREEDS_JACKRUSSELL_ABSTRACTTOPIC_H