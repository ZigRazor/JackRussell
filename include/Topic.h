#include <string>
#include <list>

namespace DogBreeds{
    namespace JackRussel{
        class Topic{
            private:
                std::string m_name;
                Topic(std::string topic_name);
            public:                
                const std::string& getName() const;
                
        };
    }
}