#include<iostream>
#include<vector>
#include<cstdint>
#include<array>

#define CHECKSUM_SIZE 255

std::array<uint8_t,2> FletcherChecksum(std::array<uint8_t, 9> chunk);

int main()
{
    uint8_t byte = 0b10000001;
    uint64_t _8_Byte_chunk = 0;
    std::vector<uint64_t> wahnsinn;

    for(size_t i = 0; i < 8; i++)
    {
        _8_Byte_chunk |= (static_cast<uint64_t>(byte) << (i*8));
        std::cout << _8_Byte_chunk << std::endl;
    }

    std::array<uint8_t,9> test;
    std::string wiki = "Wikipedia";

    for(size_t i = 0; i < 9; i++)
    {
        std::cout << static_cast<int>(wiki.at(i)) << std::endl;
        test.at(i) = static_cast<uint8_t>(wiki.at(i));
    }

    std::array<uint8_t, 2>aus = FletcherChecksum(test);

    for(size_t i = 0; i < aus.size();i++)
    {
        std::cout << static_cast<int>(aus[i]) << std::endl;
    }


    std::cout << _8_Byte_chunk << std::endl;
}

std::array<uint8_t,2> FletcherChecksum(std::array<uint8_t, 9>chunk)
{
    int sum1 = 0;
    int sum2 = 0;

    for(size_t i = 0; i < chunk.size(); i++)
    {
        sum1 = (sum1 + chunk[i]) % CHECKSUM_SIZE; 
        sum2 = (sum1 + sum2) % CHECKSUM_SIZE;
    }

    std::array<uint8_t,2>ausgabe = {sum1, sum2};
    return ausgabe;
}
