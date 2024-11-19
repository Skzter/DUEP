#include<iostream>
#include<vector>
#include<cstdint>

int main()
{
    uint8_t tesz = 0b00000001;
    uint16_t chunk;
    std::vector<uint64_t> wahnsinn;

    for(auto i = 0; i < 2; i++)
    {
        chunk |= (static_cast<uint16_t>(tesz) << (i*8));
    }
/*
    chunk |= (static_cast<uint16_t>(tesz) << (0));
    chunk |= (static_cast<uint16_t>(tesz) << (8));
*/
    std::cout << static_cast<int>(chunk) << std::endl;
}
