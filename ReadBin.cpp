#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>

int main()
{
    std::string u_input;
    std::cout << "Welches File > ";
    std::cin >> u_input;

    std::string final_destination = "E:\\Uni\\Projekte\\hwp2\\DUEP\\" + u_input + ".bin"; 
    
    std::ifstream input(final_destination, std::ios::in);

    std::vector<unsigned char>buffer(std::istreambuf_iterator<char>(input), {});

    for(size_t i = 0; i < buffer.size(); i++)
    {
        std::cout << i << ": " << buffer.at(i) << std::endl;
    }
}