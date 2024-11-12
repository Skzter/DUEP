#include<iostream>
#include<string>

#define CHUNK_SIZE 64

std::string ReadBinary();
int NumberOfChunks(std::string input);

int main()
{
    std::string input = ReadBinary();
    std::cout << input.length() << std::endl;
    std::cout << input.size() << std::endl;
    std::cout << NumberOfChunks(input) << std::endl;
    double test = (double)312/64;
    std::cout.precision(4);
    std::cout.setf(std::ios::fixed);
    std::cout << test << "test" << std::endl;
}

std::string ReadBinary()
{
    std::string eingabe;
    std::getline(std::cin, eingabe);
    return eingabe;
}

int NumberOfChunks(std::string input)
{
    double t = input.length()/CHUNK_SIZE;
    std::cout << "This is with half chunks: " << t << std::endl;
    return input.length()/CHUNK_SIZE;
}
