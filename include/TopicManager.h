#ifndef DOGBREEDS_JACKRUSSELL_TOPICMANAGER_H
#define DOGBREEDS_JACKRUSSELL_TOPICMANAGER_H

#include "Topic.h"
#include "ResultCode.h"

#include <unordered_map>

namespace DogBreeds{
    namespace JackRussell{
        class TopicManager{
            private:
                std::unordered_map<std::string, std::shared_ptr<Topic>>  m_topics;
                TopicManager(){};
                
                virtual ~TopicManager() = default;
            public:
                static TopicManager& getInstance();

                TopicManager(TopicManager const&) = delete;
                void operator=(TopicManager const&)  = delete;

                ResultCode createTopic(const std::string& topic_name);
                ResultCode deleteTopic(const std::string& topic_name);

                ResultCode subscribeToTopic(std::shared_ptr<Subscriber> sub, const std::string& topic_name);
                ResultCode unsubscribeFromTopic(std::shared_ptr<Subscriber> sub, const std::string& topic_name);

        };
    }
}

#endif // DOGBREEDS_JACKRUSSELL_TOPICMANAGER_H