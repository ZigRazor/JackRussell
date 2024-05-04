#include "TopicManager.h"
namespace DogBreeds
{
    namespace JackRussell
    {
        TopicManager &TopicManager::getInstance(){
            static TopicManager instance; 
            return instance;
        }

        ResultCode TopicManager::createTopic(const std::string &topic_name){
            if( m_topics.find(topic_name) != m_topics.end()){
                //Topic already inserted
                return ResultCode::TOPIC_ALREDY_EXIST;
            }
            //Insert Topic
            m_topics.emplace(topic_name, std::shared_ptr<Topic>(new Topic(topic_name)));
            return ResultCode::OK;
        }

        ResultCode  TopicManager::deleteTopic(const std::string &topic_name){
            if( m_topics.find(topic_name) == m_topics.end()){
                //Topic not present
                return ResultCode::TOPIC_NOT_FOUND;
            }
            //delete Topic
            m_topics.erase(topic_name);
            return ResultCode::OK;
        }

        ResultCode TopicManager::subscribeToTopic(std::shared_ptr<Subscriber> sub, const std::string &topic_name){
            auto topic = m_topics.find(topic_name);
            if(topic == m_topics.end()){
                //Topic not found
                return ResultCode::TOPIC_NOT_FOUND;
            }
            return topic->second->addSubscriber(sub);
            
        }
        ResultCode TopicManager::unsubscribeFromTopic(std::shared_ptr<Subscriber> sub, const std::string &topic_name){
            auto topic = m_topics.find(topic_name);
            if(topic == m_topics.end()){
                //Topic not found
                return ResultCode::TOPIC_NOT_FOUND;
            }
            return topic->second->removeSubscriber(sub);
        }
    }
}
