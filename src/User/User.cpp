#include "User.hpp"
#include "../Manager/Manager.hpp"
#include <iostream>
#include <sstream>

//TODO: do an exception in Flink

User::User()
{}

void User::readCommand() {
    std::string command;

    while (std::getline(std::cin, command)) {
        std::cout << "> ";
        try {
            Manager::getInstance().receiveOrder(command);
        } catch (const std::exception& e) {
                std::cerr << "Invalid command. (TEST)" << e.what() << std::endl;
        }
    }
}

std::string User::str() const
{
    return make_str("No attributes");
}