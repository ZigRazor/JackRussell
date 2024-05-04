#include "Subscriber.h"
#include "TopicManager.h"

namespace DogBreeds{
    namespace JackRussell{
        
        Subscriber::Subscriber(){
            thisShared = std::shared_ptr<Subscriber>(this);
        }
        
        ResultCode Subscriber::subscribe(std::string topic_name){
            return TopicManager::getInstance().subscribeToTopic(thisShared, topic_name);
        };

        ResultCode Subscriber::unsubscribe(std::string topic_name){
            return TopicManager::getInstance().unsubscribeFromTopic(thisShared, topic_name);
        };
    }
}