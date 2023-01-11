#include <iostream>
#include <string>

int main()
{
    std::cout << "What's your name?" << std::endl;

    // std::cout << "Hello world!" << std::endl;

    // auto var = 0;
    std::string var;
    std::cin >> var;

    std::cout << "Hello " << var << "!" << std::endl;

    return 0;
}