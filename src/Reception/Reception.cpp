#include "Reception.hpp"
#include "../Manager/Manager.hpp"
#include <iostream>
#include <sstream>

//TODO: do an exception in Flink

namespace Plazza
{
    Reception::Reception(double multiplierCooking, int numChefs, int restockTime)
    {
        this->_manager = std::make_shared<Manager>(multiplierCooking, numChefs, restockTime);
        std::cout << "DEBUG | Manager : " << this->_manager->str() << std::endl;
    }

    void Reception::run() {
        std::string input;

        while (true) {
            std::cout << "> ";
            if (!std::getline(std::cin, input))
                break;
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