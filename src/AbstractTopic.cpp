#include "AbstractTopic.h"
#include <algorithm>

namespace DogBreeds{
    namespace JackRussell{
        AbstractTopic::AbstractTopic(std::string topic_name){
            m_name = topic_name;
        }

        const std::string& AbstractTopic::getName() const{
            return m_name;
        }

        ResultCode AbstractTopic::addSubscriber(std::shared_ptr<Subscriber> sub){
            if(std::find(m_subscriberList.begin(),m_subscriberList.end(),sub) != m_subscriberList.end() ){
                return ResultCode::SUBSCRIBER_IS_ALREADY_SUBSCRIBED_TO_TOPIC;
            }
            m_subscriberList.push_back(sub);
            return ResultCode::OK;
        }
        
        ResultCode AbstractTopic::removeSubscriber(std::shared_ptr<Subscriber> sub){
            auto subscriberIt = std::find(m_subscriberList.begin(),m_subscriberList.end(),sub);
            if(subscriberIt == m_subscriberList.end() ){
                return ResultCode::SUBSCRIBER_NOT_FOUND_IN_TOPIC;
            }
            m_subscriberList.erase(subscriberIt);
            return ResultCode::OK;
        }
    }
}