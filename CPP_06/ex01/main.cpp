#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data* dataPtr = new Data(42, 4.2);

    uintptr_t serialized = Serializer::serialize(dataPtr);

    Data* deserializedPtr = Serializer::deserialize(serialized);

    if (deserializedPtr == dataPtr)
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    }
    else
    {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    delete dataPtr;

    return 0;
}
