#include "Reception.hpp"
#include "../Manager/Manager.hpp"
#include <iostream>
#include <sstream>

//TODO: do an exception in Flink

namespace Plazza
{
    Reception::Reception()
    {
        this->_manager = std::make_shared<Manager>();
    }

    void Reception::run() {
        std::string input;

        while (std::getline(std::cin, input)) {
            std::cout << "> ";
            try {
                this->_manager->receiveOrder(input);
            } catch (const std::exception& e) {
                    std::cerr << "Invalid command. (TEST)" << e.what() << std::endl;
            }
        }
    }

    void Reception::notifyReadyPizza(const std::string& pizza)
    {
        std::cout << "Reception: Your pizza " << pizza << " is ready to be enjoyed!" << std::endl;
    }


    std::string Reception::str() const
    {
        return make_str("No attributes");
    }
}