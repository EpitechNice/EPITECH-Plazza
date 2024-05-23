#include "Reception.hpp"
#include "../Manager/Manager.hpp"
#include <iostream>
#include <sstream>

//TODO: do an exception in Flink

namespace Plazza
{
    Reception::Reception()
    {}

    void Reception::run() {
        std::string input;

        while (std::getline(std::cin, input)) {
            std::cout << "> ";
            try {
                Manager::getInstance().receiveOrder(input);
            } catch (const std::exception& e) {
                    std::cerr << "Invalid command. (TEST)" << e.what() << std::endl;
            }
        }
    }

    std::string Reception::str() const
    {
        return make_str("No attributes");
    }
}