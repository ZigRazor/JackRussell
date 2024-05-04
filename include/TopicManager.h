#include "Topic.h"

#include <unordered_map>
#include <list>

namespace DogBreeds{
    namespace JackRussel{
        class TopicManager{
            private:
              std::list<Topic>  m_topicList;
            public:
                TopicManager& getInstance();
                void createTopic(std::string topic_name);
                void deleteTopic(std::string topic_name);
                
        };
    }
}