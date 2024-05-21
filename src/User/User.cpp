#include "User.hpp"
#include "Manager.hpp"
#include <iostream>
#include <sstream>

void User::readCommand() {
    std::string command;
    while (std::getline(std::cin, command)) {
        Manager::getInstance().receiveOrder(command);
    }
}
