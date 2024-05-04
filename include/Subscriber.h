#ifndef DOGBREEDS_JACKRUSSELL_SUBSCRIBER_H
#define DOGBREEDS_JACKRUSSELL_SUBSCRIBER_H

#include <memory>
#include "ResultCode.h"
namespace DogBreeds{
    namespace JackRussell{
        class Subscriber{
            private:
                std::shared_ptr<Subscriber> thisShared;
            public:
                Subscriber();
                virtual ~Subscriber() = default;
                template<typename T>
                void onMessage(std::shared_ptr<T> message) const;

                ResultCode subscribe(std::string topic_name);
                ResultCode unsubscribe(std::string topic_name);
        };
    }
}

#endif //DOGBREEDS_JACKRUSSELL_SUBSCRIBER_H