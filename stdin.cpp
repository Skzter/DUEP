#include<iostream>
#include<string>

#define CHUNK_SIZE 64.0

std::string InputToBinary(std::string InputString);
std::string IntToBinary(int Input);
double NumberOfChunks(std::string InputBinary);

int main()
{
    std::string Input;
    std::getline(std::cin, Input);
    std::string InputConverted = InputToBinary(Input);
    std::cout << InputConverted << std::endl;
    std::cout << NumberOfChunks(InputConverted) << std::endl;
 }

std::string InputToBinary(std::string InputString)
{
    std::string InputInBinary;
    for(size_t i = 0; i < InputString.length(); i++)
    {
        int Converted = static_cast<int>(InputString[i]);
        InputInBinary += IntToBinary(Converted);
    }
    return InputInBinary;
}

std::string IntToBinary(int Input)
{
    int Quotient;
    int Remainder;
    std::string Binary;
    
    do
    {
        Quotient = Input / 2;
        Remainder = Input - (Quotient * 2);
        Binary = std::to_string(Remainder) + Binary;
        Input = Quotient;
    }while(Quotient != 0);

    return Binary;
}

double NumberOfChunks(std::string InputBinary)
{
    return InputBinary.length()/CHUNK_SIZE;
}


