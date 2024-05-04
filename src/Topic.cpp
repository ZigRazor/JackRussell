#include "Topic.h"
#include <algorithm>

namespace DogBreeds{
    namespace JackRussell{
        Topic::Topic(std::string topic_name){
            m_name = topic_name;
        }

        const std::string& Topic::getName() const{
            return m_name;
        }

        ResultCode Topic::addSubscriber(std::shared_ptr<Subscriber> sub){
            if(std::find(m_subscriberList.begin(),m_subscriberList.end(),sub) != m_subscriberList.end() ){
                return ResultCode::SUBSCRIBER_IS_ALREADY_SUBSCRIBED_TO_TOPIC;
            }
            m_subscriberList.push_back(sub);
            return ResultCode::OK;
        }
        
        ResultCode Topic::removeSubscriber(std::shared_ptr<Subscriber> sub){
            auto subscriberIt = std::find(m_subscriberList.begin(),m_subscriberList.end(),sub);
            if(subscriberIt == m_subscriberList.end() ){
                return ResultCode::SUBSCRIBER_NOT_FOUND_IN_TOPIC;
            }
            m_subscriberList.erase(subscriberIt);
            return ResultCode::OK;
        }
    }
}