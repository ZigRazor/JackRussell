#include "Topic.h"

namespace DogBreeds{
    namespace JackRussel{
        Topic::Topic(std::string topic_name){
            m_name = topic_name;
        }

        const std::string& Topic::getName() const{
            return m_name;
        }
    }
}