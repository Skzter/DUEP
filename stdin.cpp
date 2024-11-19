#include<iostream>
#include<string>
#include<vector>
#include<math.h>

#define CHUNK_SIZE 64

//Send Message
std::string InputToBinary(std::string InputString);
std::string IntToBinary(int Input);
void MakeChunks(std::string InputBinary);
double NumberOfChunks(std::string InputBinary);
void PrintSendChunks(std::string InputBinary);

//Receive Message
void SaveBinaryInInt(std::string InputBinary); //whole Message in Int -- save in vector 
std::string IntToChar(std::vector<int> InputInt); //int to char -- save in string
void PrintMessage(std::string InputString); //print message, number of chunks received

//Global Variables
std::vector<std::string> ChunksSend;
std::vector<int> ReceivedBinaryToInt;

int main()
{
    std::string Input;
    std::getline(std::cin, Input);
    std::string InputConverted = InputToBinary(Input);
    MakeChunks(InputConverted);
    PrintSendChunks(InputConverted);
    std::cout << std::endl;

    SaveBinaryInInt(InputConverted);
    std::cout << "Ergebnis > ";
    for(size_t i = 0; i < ReceivedBinaryToInt.size(); i++)
    {
        std::cout << static_cast<char>(ReceivedBinaryToInt.at(i));
    }
    std::cout << std::endl;
}


std::string InputToBinary(std::string InputString)
{
    std::string InputInBinary;
    for(size_t i = 0; i < InputString.length(); i++)
    {
        unsigned char c_Converted = static_cast<unsigned char>(InputString[i]);
        int i_Converted = static_cast<int>(c_Converted);
        InputInBinary += IntToBinary(i_Converted);
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
    
    if(Binary.length() < 8)
    {
        long unsigned int temp = 8-Binary.length();
        for(size_t i = 0; i < temp; i++)
        {
            Binary = "0" + Binary;
        }
    }
    return Binary;
}

void MakeChunks(std::string InputBinary)
{
    long unsigned int NumChunks = NumberOfChunks(InputBinary);

    for(size_t i = 0; i < NumChunks; i++)
    {
        ChunksSend.push_back(InputBinary.substr(CHUNK_SIZE*i, CHUNK_SIZE));
    }


    if(CHUNK_SIZE*NumChunks < InputBinary.length())
    {
        unsigned long int Remainder = InputBinary.length()-CHUNK_SIZE*NumChunks;

        for(size_t i = 0; i < CHUNK_SIZE-Remainder; i++)
        {
            InputBinary += "0";
        }

        ChunksSend.push_back(InputBinary.substr(CHUNK_SIZE*NumChunks, CHUNK_SIZE));
    }
}

void PrintSendChunks(std::string InputBinary)
{
    for(size_t i = 0; i < ChunksSend.size(); i++)
    {
        std::cout << ChunksSend.at(i) << std::endl; 
    }
}

double NumberOfChunks(std::string InputBinary)
{
    return InputBinary.length()/CHUNK_SIZE;
}

void SaveBinaryInInt(std::string InputBinary)
{
    for(size_t i = 0; i < InputBinary.length(); i = i+8)
    {
        std::string byte = InputBinary.substr(i, 8);
        ReceivedBinaryToInt.push_back(std::stoi(byte, 0, 2));
    }
}
