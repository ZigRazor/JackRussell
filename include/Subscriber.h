
namespace DogBreeds{
    namespace JackRussel{
        template <typename T>
        class Subscriber{
            public:
                void onMessage(T message) const;
        };
    }
}