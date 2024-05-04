#ifndef DOGBREEDS_JACKRUSSELL_RESULTCODE_H
#define DOGBREEDS_JACKRUSSELL_RESULTCODE_H

namespace DogBreeds{
    namespace JackRussell{
        enum class ResultCode{
            OK,
            GENERIC_ERROR,
            TOPIC_NOT_FOUND,
            TOPIC_ALREDY_EXIST,
            SUBSCRIBER_NOT_FOUND_IN_TOPIC,
            SUBSCRIBER_IS_ALREADY_SUBSCRIBED_TO_TOPIC
        };

        
    }
}

#endif // DOGBREEDS_JACKRUSSELL_RESULTCODE_H