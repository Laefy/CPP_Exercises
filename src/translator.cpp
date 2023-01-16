#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::set<std::string> make_exit_commands()
{
    return { "q", "e", "exit", "quit" };
}

bool execute_instruction(std::istream& input,
                         std::map<std::string, std::string>& dictionary,
                         std::vector<std::string>& history)
{
    const auto exit_commands = make_exit_commands();

    auto command = std::string {};
    input >> command;

    if (exit_commands.count(command) != 0)
    {
        return false;
    }
    else if (command == "add")
    {
        auto  key = std::string {};
        input >> key;

        auto& value = dictionary[key];
        input >> value;

        std::cout << key << " => " << value << std::endl;
        history.push_back("add " + key + " " + value);
    }
    else if (command == "translate")
    {
        auto line = std::string {};
        std::getline(input, line);

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
    else if (command == "save")
    {
        auto name = std::string {};
        input >> name;

        auto file = std::ofstream { name };
        for (const auto& command: history)
        {
            file << command << "\n";
        }
    }
    else if (command == "load")
    {
        auto name = std::string {};
        input >> name;

        auto file = std::ifstream { name };
        while (!file.eof())
        {
            execute_instruction(file, dictionary, history);
        }
    }

    return true;
}

int main()
{
    auto dictionary = std::map<std::string, std::string> {};
    auto history = std::vector<std::string> {};

    while (true)
    {
        std::cout << "Enter a command: " << std::endl;

        if (!execute_instruction(std::cin, dictionary, history))
        {
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}