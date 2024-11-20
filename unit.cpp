#include<iostream>
#include<vector>
#include<cstdint>

int main()
{
    uint8_t byte = 0b00000001;
    uint64_t _8_Byte_chunk;
    std::vector<uint64_t> wahnsinn;
/*
    for(auto i = 0; i < 4; i++)
    {
        _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (i*8));
    }

    chunk |= (static_cast<uint16_t>(tesz) << (0));
    chunk |= (static_cast<uint16_t>(tesz) << (8));
*/
    _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (0));
    std::cout << static_cast<unsigned long int>(_8_Byte_chunk) << std::endl;
    std::cout << "test" << unsigned(_8_Byte_chunk) << std::endl;
    _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (8));
    std::cout << static_cast<unsigned long int>(_8_Byte_chunk) << std::endl;
    _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (16));
    std::cout << static_cast<unsigned long int>(_8_Byte_chunk) << std::endl;
    _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (24));
    std::cout << static_cast<unsigned long int>(_8_Byte_chunk) << std::endl;
    _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (32));
    std::cout << static_cast<unsigned long int>(_8_Byte_chunk) << std::endl;
    _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (40));
    std::cout << static_cast<unsigned long int>(_8_Byte_chunk) << std::endl;
    _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (48));
    std::cout << static_cast<unsigned long int>(_8_Byte_chunk) << std::endl;
    _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (56));
    std::cout << "test" << +_8_Byte_chunk << std::endl;
    std::cout << static_cast<unsigned long int>(_8_Byte_chunk) << std::endl;
}
