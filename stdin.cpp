#include<iostream>
#include<string>

std::string ReadBinary();
int main()
{
    std::cout << ReadBinary() << "\nEnd of File";
}

std::string ReadBinary()
{
    std::string eingabe;
    std::getline(std::cin, eingabe);
    return eingabe;
}
