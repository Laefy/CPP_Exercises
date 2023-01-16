#include <iostream>
#include <set>
#include <string>

std::set<std::string> make_exit_commands()
{
    return { "q", "e", "exit", "quit" };
}

int main()
{
    const auto exit_commands = make_exit_commands();

    while (true)
    {
        std::cout << "Enter a command: " << std::endl;

        auto command = std::string {};
        std::cin >> command;

        if (exit_commands.count(command) != 0)
        {
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}