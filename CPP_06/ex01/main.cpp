#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    // Create a Data object
    Data* dataPtr = new Data(42, 4.2);

    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(dataPtr);

    // Deserialize the serialized value
    Data* deserializedPtr = Serializer::deserialize(serialized);

    // Check if deserialized pointer equals original pointer
    if (deserializedPtr == dataPtr)
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    }
    else
    {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    // Clean up allocated memory
    delete dataPtr;

    return 0;
}
