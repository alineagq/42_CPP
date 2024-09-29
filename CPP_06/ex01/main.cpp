#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data originalData(42, 3.14);
    
    uintptr_t raw = Serializer::serialize(&originalData);
    
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Original Data: value = " << originalData.value << ", score = " << originalData.score << std::endl;
    std::cout << "Deserialized Data: value = " << deserializedData->value << ", score = " << deserializedData->score << std::endl;

    return 0;
}
