#ifndef DOGBREEDS_JACKRUSSELL_TOPIC_H
#define DOGBREEDS_JACKRUSSELL_TOPIC_H

#include <string>
#include <list>

#include "Subscriber.h"

namespace DogBreeds{
    namespace JackRussell{
        class TopicManager;
        class Topic{
            friend class TopicManager;
            private:
                std::string m_name;
                std::list<std::shared_ptr<Subscriber>> m_subscriberList;
                Topic(std::string topic_name);
                
            public:                
                virtual ~Topic() = default;

                const std::string& getName() const;
                ResultCode addSubscriber(std::shared_ptr<Subscriber> sub);
                ResultCode removeSubscriber(std::shared_ptr<Subscriber> sub);
                
            
        };
    }
}

#endif // DOGBREEDS_JACKRUSSELL_TOPIC_H