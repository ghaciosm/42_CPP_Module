#include "Serializer.hpp"

int main()
{
    Data data;
    data.name = "Gulcin";
    data.value = 42;

    uintptr_t serializedPtr = Serializer::serialize(&data);
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    if(deserializedPtr == &data)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;
}