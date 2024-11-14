#include<iostream>
#include<string>
#include<vector>

#define CHUNK_SIZE 64.0

//Send Message
std::string InputToBinary(std::string InputString);
std::string IntToBinary(int Input);
double NumberOfChunks(std::string InputBinary);
void PrintChunks(std::string InputBinary);

//Receive Message
std::vector<int> BinaryToInt(std::string InputBinary); //8bit to int -- save in vector 
std::string IntToChar(std::vector<int> InputInt); //int to char -- save in string
void PrintMessage(std::string InputString); //print message, number of chunks received

int main()
{
    std::string Input;
    std::getline(std::cin, Input);
    std::string InputConverted = InputToBinary(Input);
    std::cout << InputConverted << std::endl;
    std::cout << NumberOfChunks(InputConverted) << std::endl;
    PrintChunks(InputConverted);
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

void PrintChunks(std::string InputBinary)
{
    long unsigned int NumChunks = NumberOfChunks(InputBinary);
    for(size_t i = 0; i <  NumChunks; i++)
    {
        std::string chunk = InputBinary.substr(64*i, 64);
        std::cout << chunk << std::endl;
    }
    std::cout << InputBinary.substr(64*NumChunks, InputBinary.length() - 64*NumChunks) << std::endl;

    std::cout << "Das sind die Chunks" << std::endl;
}

double NumberOfChunks(std::string InputBinary)
{
    return InputBinary.length()/CHUNK_SIZE;
}
