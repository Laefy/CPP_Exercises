#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

std::set<std::string> make_exit_commands()
{
    return { "q", "e", "exit", "quit" };
}

int main()
{
    const auto exit_commands = make_exit_commands();

    auto dictionary = std::map<std::string, std::string> {};

    while (true)
    {
        std::cout << "Enter a command: " << std::endl;

        auto command = std::string {};
        std::cin >> command;

        if (exit_commands.count(command) != 0)
        {
            break;
        }
        else if (command == "add")
        {
            auto  key = std::string {};
            std::cin >> key;

            auto& value = dictionary[key];
            std::cin >> value;

            std::cout << key << " => " << value << std::endl;
        }
        else if (command == "translate")
        {
            auto line = std::string {};
            std::getline(std::cin, line);

            auto words = std::stringstream {};
            words << line;

            while (!words.eof())
            {
                auto key = std::string {};
                words >> key;
            
                const auto it = dictionary.find(key);
                std::cout << (it == dictionary.end() ? "???" : it->second) << " ";
            }

            std::cout << std::endl;
        }
        else if (command == "print")
        {
            for (const auto& [key, value]: dictionary)
            {
                std::cout << key << " => " << value << std::endl;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}